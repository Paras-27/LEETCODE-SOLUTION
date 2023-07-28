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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        ListNode *store= head;
        ListNode *temp= head->next;
        ListNode *tempn;
        while(temp!=NULL){
            tempn=temp->next;
            temp->next=head;
            head=temp;
            temp=tempn;
        }
        store->next=NULL;
        return head;
    }
};