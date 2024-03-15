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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode *temp,*prev;
    int node=0,count=1;
    temp=head;
    while(temp){
        temp=temp->next;
        node++;
    }
    if(node-n==0){
        head=head->next;
        return head;
    }
    temp=head;
    while(count!=node-n+1){
        prev=temp;
        temp=temp->next;
        count++;
    }
    prev->next=temp->next;
    temp->next=NULL;
    return head;
    }
};