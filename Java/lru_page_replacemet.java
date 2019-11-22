import java.util.*;
class lru_page_replacement{
	static int lru(int no_pages[], int frames_no ){
		int n = no_pages.length;
		HashSet<Integer> frames = new HashSet<Integer>(frames_no);
		HashMap <Integer,Integer> map_time = new HashMap<Integer,Integer>();

		int number_of_page_faults =0;
		for (int i=0; i<n;i++ ) {
			System.out.println("Adding page "+no_pages[i]+" to frame");
			if(frames.size()<frames_no){
				if(!frames.contains(no_pages[i])){
					frames.add(no_pages[i]);
					number_of_page_faults++;
					System.out.println("There is page fault");
				}
				map_time.put(no_pages[i],i);

			}
			else{
				if(!frames.contains(no_pages[i])){
					int last_used = Integer.MAX_VALUE, no_ = Integer.MIN_VALUE;
					Iterator<Integer> itr = frames.iterator();
					while(itr.hasNext()){
						int next_ = itr.next();
						if(map_time.get(next_)<last_used){
							last_used = map_time.get(next_);
							no_ = next_;
						}
					}
					frames.remove(no_);
					map_time.remove(no_);
					frames.add(no_pages[i]);
					number_of_page_faults++;
					System.out.println("There is page fault" );
				}
				map_time.put(no_pages[i],i);
			}
			System.out.println("");
			System.out.println("frame: ");
			System.out.println(frames);
			System.out.println("");
			System.out.println("Least recently used table: ");
			map_time.forEach((k,v) -> System.out.println("Page No.: "+k+ " Time: "+v) );
			System.out.println("");
		}
		return number_of_page_faults;
	}
	public static void main(String args[]){
		Scanner s = new Scanner(System.in);
		System.out.println("Enter number of pages: ");
		int len  = s.nextInt();
		int [] pages = new int[len];
		System.out.println("Enter page number: ");
		for (int i=0;i<len ; i++) {
			pages[i] = s.nextInt();
		}
		System.out.println("Enter number of frames: ");
		int frames_no = s.nextInt();
		int faults = lru(pages,frames_no);
		System.out.println("Number of page faults are: ");
		System.out.println(faults);
	}
}