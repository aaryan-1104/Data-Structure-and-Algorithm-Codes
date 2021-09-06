#include<iostream>
using namespace std;
#include<vector>
#define N 100
class stack{
    int *arr;
    int top;
    public:
    stack(){
        arr=new int[N];
        top=-1;
    }
    void push(int x){
        if(top==N){
            cout<<"Stack is Overflow!!"<<endl;
            return;
        }
        top++;
        arr[top]=x;
    }
    void pop(){
        if(top==-1){
            cout<<"Stack is Empty!!"<<endl;
            return;
        }
        top--;
    }
    int Top(){
        if(top==-1){
            cout<<"Stack is Empty!!"<<endl;
            return -1;
        }
        return arr[top];        
    }
    bool empty(){
        if(top==-1){
            return true;
        }
        return false;
    }
};

int main(){
    stack st;
    st.push(4);
    st.push(6);
    st.push(1);
    cout<<st.Top()<<" ";
    st.pop();
    cout<<st.Top()<<" ";
    cout<<st.empty();
    return 0;
}