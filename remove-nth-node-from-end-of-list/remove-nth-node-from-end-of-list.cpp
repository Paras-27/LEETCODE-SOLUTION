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
    int length(ListNode*head){
        int len=0;
        while(head!=NULL){
            head=head->next;
            len++;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=length(head)-n,j=0;
        if(len==0){
            return head->next;
        }
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL && j<len){
            j++;
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        return  head;
    }
};