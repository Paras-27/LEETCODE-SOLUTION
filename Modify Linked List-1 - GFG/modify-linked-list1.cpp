//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
class Solution{
    public:
    Node* reverseLL(Node*n,Node*prev)
    {
        if(n==NULL) return prev;
        Node*nexNode=n->next;
        n->next=prev;
        prev=n;
        return reverseLL(nexNode,prev);
    }
    struct Node* modifyTheList(struct Node *head)
    {
        Node*fast=head,*slow=head,*prev=NULL;
        while(fast!=NULL and fast->next!=NULL)
        {
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
        prev->next=reverseLL(slow,NULL);
        Node*curr=head,*nxt=prev->next;
        while(curr!=prev->next)
        {
            int val=curr->data;
            curr->data=nxt->data-val;
            nxt->data=val;
            curr=curr->next;
            nxt=nxt->next;
        }
        Node*revN=prev->next;
        prev->next=reverseLL(revN,NULL);
        return head;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends