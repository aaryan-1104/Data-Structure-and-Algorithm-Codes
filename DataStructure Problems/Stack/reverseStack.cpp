#include <iostream>
using namespace std;
#include <stack>
void insertAtBottom(stack<int> &st,int x){
    
    if(st.empty()){
        st.push(x);
        return;
    }
    
    int topx=st.top();
    st.pop();
    insertAtBottom(st,x);
    st.push(topx);
}
void reverseStack(stack<int> &st){
    if(st.empty()){
        return;
    }
    int x=st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st,x);
    return;
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    // while(!st.empty()){
    //     cout<<st.top()<<endl;
    //     st.pop();
    // }
    reverseStack(st);
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
}