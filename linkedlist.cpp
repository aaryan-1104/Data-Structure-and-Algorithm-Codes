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

void insertAtHead(node* &head,int val){
	node* n=new node(val);
	node* temp=head;

	if(head==NULL){
		head=n;
		return;
	}
	n->next=head;
	head=n;
}

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

node* deleteNode(node* &head, int position) {
    if(position==0){
        if(head->next==NULL){
			delete head;
			return NULL;
		}
		else{
			node* toDelete=head;
			head=head->next;
			delete toDelete;
			return head;
		}
    }
    node* temp=head;
    int count=0;
    while(count!=position-1){
        temp=temp->next;
		count++;
    }
    node* toDelete=temp->next;
    temp->next=toDelete->next;
    delete toDelete;
    return head;
}

void display(node* &head){
	node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<endl;
		temp=temp->next;
	}
}

void displayReverse(node* &head){
	if(head==NULL){
		return;
	}
	node* temp=head;
	vector<int> tempa;
	while(temp!=NULL){
		tempa.push_back(temp->data);
		temp=temp->next;
	}
	reverse(tempa.begin(),tempa.end());
	for(auto i:tempa){
		cout<<i<<" ";
	}

}

node* reverse(node* &head){
    node* prev=NULL;
    node* temp=head;
    node* nextn;
    if(head==NULL){
        return head;
    }
    while(temp!=NULL){
        nextn=temp->next;
        temp->next=prev;
        prev=temp;
        temp=nextn;
        }
		head=prev;
    return head;
}

void getNode(node* &head, int pos){
	node* temp=head;
	int count=0;
	if(temp==NULL){
		return;
	}
	while(temp!=NULL){
		temp=temp->next;
		count++;
	}
	int x=0;
	while(x!=count-pos-1&&head!=NULL){
		head=head->next;
		x++;
	}
	cout<<head->data;
}

node* removeDuplicates(node* &head){
	node* temp=head->next;
	node* prev=head;
	node* toDelete=NULL;
	if(temp==NULL){
        return head;
    }
	while(temp!=NULL){
		if(temp->data==prev->data){
			toDelete=temp;
			prev->next=temp->next;
			temp=temp->next;
			delete toDelete;
		}
		else{
			prev=temp;
			temp=temp->next;
		}
	}
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
// int position;
// cin>>position;
node* newl=removeDuplicates(head);
display(newl);
// deleteNode(head,position);
// reverse(head);
// displayReverse(head);
// getNode(head,position);
return 0;
}
