//spider order array
//transpose of square matrix
//matrix multiplication 
//optimized search in 2d array    c-- small , r++ big
//character array

//largest word     <<cin.getline() and cin.ignore for clearing the buffer
#include<iostream>
using namespace std;

int main(){
    char a[100]="apple";
    int n;
    cin>>n;
    cin.ignore();
    cin.getline(a, n);
    cin.ignore();

    int currlen=0, maxlen=0, st=0, maxst=0;
    int i=0;
    while(i<n){
        if(a[i]==' ' || a[i]=='\0'){
            if(currlen>maxlen){
                maxlen=currlen;
                maxst=st;
            }
            st=i+1;
            currlen=0;
        }
        else{
            currlen++;
        }
        if(a[i]=='\0'){
            break;
        }
        i++;
    }
    cout<<a<<endl;
    cout<<maxlen<<endl;
    for(int i=0;i<maxlen;i++){
        cout<<a[maxst+i];
    }
    return 0;
}