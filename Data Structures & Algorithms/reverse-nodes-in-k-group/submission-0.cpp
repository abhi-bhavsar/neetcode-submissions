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
    vector<ListNode*> reverse(ListNode*head,int k) {
        ListNode*prev = NULL ;
        ListNode*curr = head ;
        ListNode*nxt = NULL  ;
        if(head->next){
        nxt = head->next ;}
        while(curr!=NULL && k>0) {
            nxt = curr->next  ;
            curr->next = prev ;
            prev = curr ; 
            curr = nxt ;
            k-- ;
        }
        return {prev,head,nxt} ;
    }
    bool getKthNode(ListNode*curr,int k) {
       
        while(curr!=NULL && k>0) {
            curr = curr->next ;
            k-- ;
        }
         return k==0 ;   
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
       
    
        if(!getKthNode(head,k)) {return head;}
        ListNode*dummy = new ListNode(0,NULL) ;
        vector<ListNode*>v = reverse(head,k) ;
        dummy->next = v[0] ;  // new head ;
        ListNode*curr = v[1];   // new tail 
        ListNode*nxt = v[2] ;  // new start
        while(nxt!=NULL && getKthNode(nxt,k)) {
            
            vector<ListNode*>v2 = reverse(nxt,k) ;
            ListNode*temp = v2[1] ;
            ListNode*prev = v2[0] ;
            nxt = v2[2] ; 
            curr->next = prev ;
            curr = temp ;
        }
        curr->next = nxt ;
        return dummy->next ;
    }
};
