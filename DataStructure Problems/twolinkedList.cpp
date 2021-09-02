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

node* mergeLists(node* &head1, node* &head2) {
    node* temp1=head1;
    node* temp2=head2;
    node* tempNode= new node(-1); 
    node* temp=tempNode;
    // if(head1==NULL){
    //     if(head2!=NULL){
    //     return head2;}
    // }
    // if(head2==NULL){
    //     if(head1!=NULL){
    //     return head1;}
    // }
    while(temp1!=NULL&&temp2!=NULL){
     if(temp1->data<temp2->data){
        temp->next=temp1;
        temp1=temp1->next;
		temp=temp->next;
     }
     else{
         temp->next=temp2;
         temp2=temp2->next;
		temp=temp->next;

     }   
    }
    while(temp1!=NULL){
        temp->next=temp1;
        temp1=temp1->next;
		temp=temp->next;

    }
    
    while(temp2!=NULL){
        temp->next=temp2;
        temp2=temp2->next;
		temp=temp->next;

    }    
    return tempNode->next;
}

//     node* result;
// if(head1->data<head2->data){
//     result=head1;
//     result->next=mergeLists(head1->next,head2);
// }
// else{
//      result=head2;
//     result->next=mergeLists(head1,head2->next);
// }
// return result;

void display(node* &head){
	node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<endl;
		temp=temp->next;
	}
}

int findMergeNode(node* &head1, node* &head2) {
    node* temp1=head1;
    node* temp2=head2;
    int c1=0;
    int c2=0;
    while(temp1!=NULL){
        temp1=temp1->next;
        c1++;
    }
    
	while(temp2!=NULL){
        temp2=temp2->next;
        c2++;
    }
    
	int d;
    node* temp11;
    node* temp22;
    
	if(c1>c2){
        d=c1-c2;
       temp11=head1;
       temp22=head2; 
    }
    else{
        d=c2-c1;
       temp11=head2;
       temp22=head1;
    }

    while(d!=0){
        temp11=temp11->next;
        d--;
    }

    for(int i=0;i<=c1;i++){
        if(temp11==temp22){
            return temp11->data;
        }
        temp11=temp11->next;
        temp22=temp22->next;   
    }
    return -1;
}

int main(){
int n1,n2;
int val;
cin>>n1;
cout<<endl;
node* head1=NULL;
for(int i=0;i<n1;i++){
	cin>>val;
	cout<<endl;
	insertAtTail(head1,val);
}
cin>>n2;
cout<<endl;
node* head2=NULL;
for(int i=0;i<n2;i++){
	cin>>val;
	cout<<endl;
	insertAtTail(head2,val);
}

// int position;
// cin>>position;
// deleteNode(head,position);
// reverse(head);
// node* newHead=mergeLists(head1,head2);
// display(newHead);

// displayReverse(head);
return 0;
}