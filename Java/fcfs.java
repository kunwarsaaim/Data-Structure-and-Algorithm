import java.util.*;

class Process{
	String p;
	int arrival_time;
	int burst_time;
	String g;
	int time;

	Process(String pj, int aj, int bj){
		p = pj;
		arrival_time = aj;
		burst_time = bj;
	}
	Process(String gj, int tj){
		g = gj;
		time = tj;
	}
}
class fcfs{
    static void sortj(Process pro[],int n){
     Process k;
     for(int i=0;i<n-1;i++){
         for(int j=0;j<n-i-1;j++){
             if(pro[j].arrival_time>pro[j+1].arrival_time){
                k = pro[j];
                pro[j] = pro[j+1];
                pro[j+1] = k;
             }
         }
     }
}
	public static void main(String arg[]){
		int n;
		Scanner s = new Scanner(System.in);
		System.out.println("enter no of process");
		n = s.nextInt();

		Process pro[] = new Process[n];
		Process chart[] = new Process[10];
		String as;
		int at;
		int bt;
    for (int i=0; i<n; i++) {
        System.out.println("Enter Process Name | Arrival Time | Burst Time: ");
        
         as= s.next();
         at= s.nextInt();
         bt= s.nextInt();
         Process z = new Process(as,at,bt);
         pro[i] = z;

    }
		System.out.println("");

		System.out.println("Process\t Arrival Time\t Burst Time");
		for(int i=0; i<n; i++){
			System.out.println(pro[i].p+ "\t\t\t" +pro[i].arrival_time+"\t\t\t\t"+pro[i].burst_time);
		}

		System.out.println();
		sortj(pro,n);
	for(int i=0; i<n; i++){
	System.out.println(pro[i].p+ "\t\t\t" +pro[i].arrival_time+"\t\t\t\t"+pro[i].burst_time);
	}
	
    int process_count=0,chart_count=0;
    while(process_count<n){
        if ((pro[0].arrival_time!=0 && chart_count==0)  || (process_count>0 && pro[process_count].arrival_time>chart[chart_count-1].time)) {
           chart[chart_count] = new Process("I",pro[process_count].arrival_time);
           chart_count++;
        }
        else{
            if(chart_count==0){
                chart[chart_count] = new Process(pro[process_count].p,pro[process_count].burst_time);
                process_count++;
                chart_count++;
            }
            else{
                chart[chart_count] = new Process(pro[process_count].p, chart[chart_count-1].time + pro[process_count].burst_time);
                process_count++;
                chart_count++;
            }
        }
    }
    
    System.out.println("Gant Chart: ");
    for(int i=0;i<chart_count;i++){
        System.out.print(chart[i].g+"\t");
    }
    System.out.println();
    for(int i=0;i<chart_count;i++){
        System.out.print(chart[i].time+"\t");
    }
    System.out.println();
    
    float average_waiting=0,average_turnaround=0;
    process_count=0;
    for (int i=0; i<chart_count; i++) {
        if(chart[i].g != "I"){
            int turn_around = chart[i].time-pro[process_count].arrival_time;
            int waiting_time = turn_around-pro[process_count].burst_time;
            System.out.println("Process "+pro[process_count].p+" Turn Around Time: "+turn_around+ " Waiting Time: "+waiting_time);
            average_waiting+=waiting_time;
            average_turnaround+=turn_around;
            process_count++;
        }
    }
    System.out.println();
    
    average_turnaround= (float)average_turnaround/n;
    average_waiting = (float)average_waiting/n;
    System.out.println("Average turnaround Time: "+average_turnaround+"  Average Waiting Time: "+average_waiting);
	}
	
}