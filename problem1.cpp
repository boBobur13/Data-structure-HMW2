#include <iostream>
using namespace std;
int main() {
   int n,i;
    cin>>n;
    int A[100];
    for(i=0;i<n;i++) cin>>A[i];
    int idx;
    cin>>idx;
    int done=0;
    while(!done){
        int l=2*idx+1;
        int r=2*idx+2;
        int smallest = idx;
        if ( l<n && A[l] < A[smallest] ) smallest=l;
        if ( r<n && A[r] <A [smallest] ) smallest=r;
        if ( smallest!=idx ){int t=A[idx];A[idx] =A[smallest] ;A[smallest]=t ;idx=smallest;}
        else done=1;
    }
    for(i=0;i<n;i++) cout<<A[i]<<" ";
    cout<<endl;
    return 0;
}
