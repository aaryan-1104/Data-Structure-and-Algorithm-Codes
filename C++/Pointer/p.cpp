#include<iostream>
using namespace std;
#include<climits>

void increment(int *a, int *b){
    *a=*a+1;
    *b=*b+1;
}

int main(){

    int a=2;
    int b=5;
    int *bptr=&b;
    increment(&a, bptr);

    cout<<a<<" "<<b<<endl;
/*    int ar=10; 
    int *aptr;
    aptr=&ar;
    cout<<*aptr<<endl;

    int a[]={1,2,3,4,5};
    cout<<*a<<endl;  //it cannot be directly modified using a loop

    int *ptr;
    ptr=a;
    for(int i=0;i<5;i++){
        cout<<*ptr<<endl;
        cout<<*(a+i)<<endl;
        ptr++;
        
    }*/
    return 0;

}
