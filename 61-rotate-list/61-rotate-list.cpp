/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0)return head;
        int size=1;
        ListNode* curr=head;
        while(curr->next!=NULL){
            curr=curr->next;
            size++;
        }
        curr->next=head;
        k=size-k%size;
        while(k--){
            curr=curr->next;
        }
        head=curr->next;
        curr->next=NULL;
        return head;
    }
};