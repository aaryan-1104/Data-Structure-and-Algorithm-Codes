#include <iostream>
using namespace std;
#include <climits>
//  const int NMAX = 1e7+2;
//  long long q[NMAX][3];
//  const int MAX = 1e7+2;
//  long long a[MAX];

// long long arrayManupulation(int n,int m,long long q[][3]){

//     for(int i=0;i<=n;i++){
//         a[i]=0;
//     }

//     long long maxans = -(1LL<<60);
//     for(int i=0;i<m;i++){
//         for(int k=q[i][0]-1;k<q[i][1];k++){
//             a[k]=a[k]+q[i][2];
//             maxans=max(maxans,a[k]);
//         }
//     }
//     return maxans;
// }
// int main(){
//     int n,m;
//     cin>>n>>m;

//     for(int i=0;i<m;i++){
//         for(int j=0;j<3;j++){
//             cin>>q[i][j];
//         }
//     }
//     cout<<arrayManupulation(n,m,q);
//    return 0;
// }

//optimized code
// #include <iostream>
// using namespace std;
// const int NMAX = 1e7+2;
// long long q[NMAX];
// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     for(int i=0;i<m;++i){
//         int x, y, k;
//         cin >> x >> y >> k;
//         q[x-1] = q[x-1]+ k;
//         q[y]= q[y] - k;
//     }
//     long long sum = 0,maxans=-(1LL<<60);
//     for(int i=0;i<n;++i){
//         sum = sum+q[i];
//         maxans = max(maxans,sum);
//     }
//     cout<<maxans;
//     return 0;
// }

