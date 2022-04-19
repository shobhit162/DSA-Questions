// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node* partition(struct Node* head, int x);

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    int t;
    cin >> t;

    while (t--) {
        struct Node* head = NULL;
        struct Node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            if (i == 0) {
                head = new Node(value);
                temp = head;
            } else {
                temp->next = new Node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        // Solution ob;

        head = partition(head, k);
        printList(head);
    }

    return (0);
}
// } Driver Code Ends


// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

struct Node* partition(struct Node* head, int x) {
    // code here
     vector<int> a,b,c;
    Node *itr=head;
    while(itr!=NULL)
    {
        if(itr->data==x)
        b.push_back(itr->data);
        if(itr->data<x)
        a.push_back(itr->data);
        if(itr->data>x)
        c.push_back(itr->data);
        itr=itr->next;
    }
    Node *it2=head;
    for(int i=0;i<a.size();i++)
    {
        it2->data=a[i];
        it2=it2->next;
    }
     for(int i=0;i<b.size();i++)
    {
        it2->data=b[i];
        it2=it2->next;
    }
     for(int i=0;i<c.size();i++)
    {
        it2->data=c[i];
        it2=it2->next;
    }
    return head;
}