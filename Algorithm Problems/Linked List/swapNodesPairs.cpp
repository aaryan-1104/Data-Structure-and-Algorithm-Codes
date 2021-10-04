#include<iostream>
using namespace std;
#include<algorithm>
#include <vector>
class node{
	public:
	int data;
	node* next;
	node(int val){
		data=val;
		next=NULL;
	}
};

void insertAtTail(node* &head,int val){
	node* n=new node(val);
	if(head==NULL){
		head=n;
		return;
	}
	node* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=n;
}

void display(node* &head){
	node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<endl;
		temp=temp->next;
	}
}

node* swapPairs(node* head) {
        if (head == NULL || head->next==NULL){
            return head; // Base case for 0 or 1 element
        }
        
        node* temp;
        // Swap first pair
        temp = head->next;
        head->next = temp->next;
        temp->next = head;
        head = temp; // to maintain the head pointer to the first element
            
        // Call the method recursively for the rest of the list
        head->next->next = swapPairs(head->next->next);
        return head;
}

int main(){
int n;
cin>>n;
cout<<endl;
int val;
node* head=NULL;
for(int i=0;i<n;i++){
	cin>>val;
	cout<<endl;
	insertAtTail(head,val);
}

display(head);
swapPairs(head);
display(head);

return 0;
}


