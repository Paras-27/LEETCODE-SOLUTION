//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};


// } Driver Code Ends
/*
// structure of the node is as follows

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
class Solution
{
    public:
    void insert_at_head(struct Node * &head,int data){
        if(head==NULL){
            head=new Node(data);
            return;
        }
        
        Node* n= new Node(data);
        n->next=head;
        head=n;
    }
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        // code here
        set<int>st;
        Node *temp1=head1;
        Node *temp2=head2;
        while(temp1!=NULL){
            st.insert(temp1->data);
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            st.insert(temp2->data);
            temp2=temp2->next;
        }
        vector<int>res;
        for(auto ele:st){
            res.push_back(ele);
        }
        sort(res.begin(),res.end());
        reverse(res.begin(),res.end());
        Node *temp=NULL;
        for(auto ele:res){
            insert_at_head(temp,ele);
        }
        return temp;
    }
};


//{ Driver Code Starts.

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution obj;
        Node* head = obj.makeUnion(first,second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends