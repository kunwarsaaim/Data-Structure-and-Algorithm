#include "iostream"
#include "cmath"
#include "queue"
using namespace std;


struct node{
    int data;
    node *rchild;
    node *lchild;
};

class tree{

private:
    
    node *newnode(int info){
        node* temp = (node*)malloc(sizeof(node));
        temp->data = info;
        temp->lchild = temp->rchild = NULL;
        return (temp);
    }
    
    node **insertaddress(node *root,node *arr[]){
        node *ptr = root;
        if (ptr==NULL) return arr;
        
        queue<node *> q;
        q.push(root);
        int i=0;
        while (!q.empty()) {
            ptr = q.front();
            q.pop();
            arr[i] = ptr;
            i++;
            if (ptr->lchild!=NULL)
                q.push(ptr->lchild);
            if (ptr->rchild!=NULL)
                q.push(ptr->rchild);
        }
        cout<<endl;
        return arr;
    }
    

public:
    
    node *insert_tree(node *root,int i, int n){
        if (i<n) {
            cout<<"Enter node data in node number "<<i<<" : ";
            int info;
            cin>>info;
            root = newnode(info);
            root->lchild = insert_tree(root->lchild, 2*i +1, n);
            root->rchild = insert_tree(root->rchild, 2*i+2, n);
        }
        return root;
    }
 
    
    void levelorder(node *root){
        
        node *ptr = root;
        if (ptr==NULL) return;
        
        queue<node *> q;
        q.push(root);
        
        while (!q.empty()) {
            ptr = q.front();
            q.pop();
            cout<<ptr->data<<" ";
            if (ptr->lchild!=NULL)
                q.push(ptr->lchild);
            if (ptr->rchild!=NULL)
                q.push(ptr->rchild);
        }
        cout<<endl;
    }
    
    
    node *rotate_left(node *root,int level){
        int count = 0;
        node *arr[25];
        insertaddress(root,arr);
        int m = pow(2, level-2)-1;
        int n = pow(2, level-1)-1;
        int k = m;
        arr[m++]->rchild = arr[n++];
        while (count<(pow(2, level-2)-1)) {
            arr[m]->lchild = arr[n++];
            arr[m++]->rchild = arr[n++];
            count++;
        }
        arr[k]->lchild = arr[n];
        return root;
    }
    
    
    node *rotate_right(node *root,int level){
        int count = 0;
        node *arr[25];
        insertaddress(root,arr);
        int m = pow(2, level-2)-1;
        int n = pow(2, level-1)-1;
        int temp1 = n++;
        while (count<(pow(2, level-2)-1)) {
            arr[m]->lchild = arr[n++];
            arr[m++]->rchild = arr[n++];
            count++;
        }
        arr[m]->lchild = arr[n];
        arr[m]->rchild=arr[temp1];
        return root;
    }
};


int main(){
    cout<<"Enter height of tree : ";
    int h;
    cin>>h;
    int n = pow(2, h) -1;
    cout<<endl;
    tree obj;
    cout<<"Enter tree data in postorder"<<endl;
    node *root = obj.insert_tree(root, 0, n);
    cout<<endl;
    cout<<"Levelorder traversal of Tree"<<endl;
    obj.levelorder(root);
    cout<<endl;
    cout<<"Enter level number to rotate(starting from 1) : ";
    int level;
    cin>>level;
    cout<<endl;
    cout<<"1.Rotate left\n2.Rotate right"<<endl;
    int rotation;
    cin>>rotation;
    if(rotation==1)
        root = obj.rotate_left(root, level);
    
    if (rotation==2)
        root = obj.rotate_right(root, level);
    cout<<"Levelorder traversal of rotated Tree"<<endl;
    obj.levelorder(root);
    cout<<endl;
}

