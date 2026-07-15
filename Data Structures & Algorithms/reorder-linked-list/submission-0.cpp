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
    void reorderList(ListNode* head) {

        if(!head || !head->next || !head->next->next){return ;}
        
        ListNode*fast = head ;
        ListNode*slow = head ;

        // finding middle
        while(fast!=NULL && fast->next!=NULL ){
            fast = fast->next->next ;
            slow = slow->next ;
        }
        ListNode*curr = slow->next  ; 
        ListNode*prev = NULL;
        slow->next = NULL ;
        // reversing the middle next half
        while(curr!=NULL) {
            ListNode*nxt = curr->next ;
            curr->next = prev ;
            prev = curr ;
            curr = nxt ;
        }
        // concatenating the remaining
    
        ListNode*second = prev ;
        ListNode*first = head ;

        while(second!=NULL ) {
            ListNode*temp1 = first->next; 
            ListNode*temp2 = second->next ;

            first->next = second ;
            second->next = temp1 ; 

            first = temp1 ;
            second = temp2;
        }
        
    }
};
