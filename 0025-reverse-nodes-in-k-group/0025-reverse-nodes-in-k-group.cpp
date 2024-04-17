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
    int count(ListNode* head){
        int n=0;
        while(head){
            head=head->next;
            n++;
        }
        return n;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {

          // bc
          int num=count(head);                                      
          if(num<k){
              return head;
          }
          int x=k;
          ListNode *next, *prev=NULL;
          ListNode *curr=head;
          while(x--){
              next=curr->next;
              curr->next=prev;
              prev=curr;
              curr=next;
          }
          // 1->2->3->4....
          head->next= reverseKGroup(next,k);
          return prev;
    }
};