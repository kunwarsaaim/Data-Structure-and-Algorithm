#include <iostream>
#include <vector>
using namespace std;


void swap(vector <int> &arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void restoreUp(vector <int> &arr, int size){
    int k = arr[size];
    int child = size;
    int parent = (child - 1)/2;
    while(parent >= 0 && arr[child] > arr[parent]){
        swap(arr, child, parent);
        child = parent;
        parent = (child - 1)/2;
    }
    arr[child] = k;
}

void restoreDown(vector <int> &arr, int root){
    int child = root;
    int left = 2 * child + 1;
    int right = 2 * child + 2;
    int size = arr.size();
    while(left < size){
        if(right < size && arr[right] > arr[left]){
            child = right;
        }
        else{
            child = left;
        }
        if(arr[child] > arr[root]){
            swap(arr, child, root);
            root = child;
            left = 2 * root + 1;
            right = 2 * root + 2;
        }
        else{
            break;
        }
    }
}

void insert(vector <int> &arr , int num){
    int size = arr.size();
    arr.push_back(num);
    restoreUp(arr, size);
}


int del_root(vector <int> &arr){
    int size = arr.size();
    int root = arr[0];
    arr[0] = arr[size - 1];
    arr.pop_back();
    restoreDown(arr, 0);
    return root;
}


void buildHeap(vector <int> &arr){
    int size = arr.size();
    for(int i = size/2 - 1; i >= 0; i--){
        restoreDown(arr, i);
    }
}

void display(vector <int> &arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int randomize(){   

    return (rand() % 100);  
} 
// ================================================================================
std::string do_padding (unsigned index, unsigned mlength){
  std::string padding;
  if (int((index-1)/2) != 0){
    return (int((index-1)/2) % 2 == 0) ?
    (do_padding(int((index-1)/2),mlength) + std::string(mlength+4,' ') + " ")  :
    (do_padding(int((index-1)/2),mlength) + std::string(mlength+3,' ') + " |") ;
  }
  return padding;
}


void printer (std::vector<int> const & tree, unsigned index, unsigned mlength){
  auto last = tree.size() - 1 ;
  auto  left = 2 * index + 1 ;
  auto  right = 2 * index + 2 ;
  std::cout << " " << tree[index] << " ";
  if (left <= last){
    auto llength = std::to_string(tree[left]).size();
    std::cout << "---" << std::string(mlength - llength,'-');
    printer(tree,left,mlength);
    if (right <= last) {
      auto rlength = std::to_string(tree[right]).size();
      std::cout << "\n" << do_padding(right,mlength) << std::string(mlength+ 3,' ') << " | ";
      std::cout << "\n" << do_padding(right,mlength) << std::string(mlength+ 3,' ') << " └" <<
      std::string(mlength - rlength,'-');
      printer(tree,right,mlength);
    }
  }
}


void print_tree (std::vector<int> & tree){
  unsigned mlength = 0;
  for (int & element : tree){
    auto clength = std::to_string(element).size();
    if (clength > mlength) {
      mlength = std::to_string(element).size();
    }
  }
  std::cout <<  std::string(mlength- std::to_string(tree[0]).size(),' ');
  printer(tree,0,mlength);
}

// ======================================================================================

int main(){
    cout<<"Enter Number of Test Cases: ";
    int c;
    cin>>c;
    srand(time(NULL)); 
    for(int i=0;i<c;i++){
        cout<<"Tescase "<<i+1<<endl;
        cout<<endl;
        int size = rand() % 20;
        vector<int> arr(size);
        // vector <int> arr;
        generate(arr.begin(), arr.end(), randomize); 
        cout<<"Before: ==================================="<<endl;
        display(arr);
        cout<<endl;
        buildHeap(arr);

        cout<<"After: ===================================== "<<endl;
        print_tree(arr);
        cout<<endl;
        cout<<"Input Number to Insert: ================================="<<endl;
        int num;
        cin >> num;
        insert(arr, num);
        cout<<endl;
        cout<<"After Insert: ===================================== "<<endl;
        print_tree(arr);
        cout<<endl;
        cout<<"Deleting root: ================================="<<endl;
        cout<< del_root(arr) << endl;
        print_tree(arr);
        cout<<endl;
        cout<<"=================xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx================"<<endl;
        cout<<endl;
    }
   
    return 0;

}

