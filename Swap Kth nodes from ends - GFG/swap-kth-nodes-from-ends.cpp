// { Driver Code Starts
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



Node *swapkthnode(Node* head, int num, int K);

void addressstore(Node **arr, Node* head)
{
    Node* temp = head;
    int i = 0;
    while(temp){
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node ** before, Node **after, int num, int K)
{
    if(K > num)
        return 1;
    return (before[K-1] == after[num - K]) && (before[num-K] == after[K-1]);
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int num, K , firstdata;
        cin>>num>>K;
        int temp;
        cin>>firstdata;
        Node* head = new Node(firstdata);
        Node* tail = head;
        for(int i = 0; i<num - 1; i++){
            cin>>temp;
            tail->next = new Node(temp);
            tail = tail->next;
        }
        
        Node *before[num];
        addressstore(before, head);
        
        head = swapkthnode(head, num, K);
        
        Node *after[num];
        addressstore(after, head);
        
        if(check(before, after, num, K))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends


//User function Template for C++

/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
  }
*/

//Function to swap Kth node from beginning and end in a linked list.
Node *swapkthnode(Node* head, int num, int K)
{
    // Your Code here
    if(K>num ||num==1 ) return head;
    if(num==2){
        Node*newhead=head->next;
        newhead->next=head;
        head->next=NULL;
        head=newhead;
        return head;
    }
    Node*curr=head,*curr1=head;
    if( num%2==0 && ( K==num/2 || K==(num/2)+1 )  ){
        K=num/2;
        int x=K-2;
        while(x--){
            curr=curr->next;
        }
        Node*tempprev=curr;
        Node*temp=curr->next;
        Node*end=curr->next->next;
        Node*endnext=end->next;
        tempprev->next=end;
        end->next=temp;
        temp->next=endnext;
        return head;
    }
    if(K==1 || K==num){
        while(curr1->next->next!=NULL){
            curr1=curr1->next;
        }
        Node*endprev=curr1;
        Node*end=curr1->next;
        Node*temp=curr;
        Node*tempnext=curr->next;
        end->next=tempnext;
        endprev->next=temp;
        temp->next=NULL;
        head=end;
    }
    else{
        int c=K-2,c1=(num-K-1);
        while(c--){
            curr=curr->next;
        }
        while(c1--){
            curr1=curr1->next;
        }
        Node*endprev=curr1;
        Node*end=curr1->next;
        Node*endnext=curr1->next->next;
        Node*tempnext=curr->next->next;
        Node*temp=curr->next;
        Node*tempprev=curr;
        tempprev->next=end;
        end->next=tempnext;
        endprev->next=temp;
        temp->next=endnext;
    }
    return head;
}
