#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int A[100];
    for(int i=0;i<n;i++) cin >> A[i];
  ////////////////////////////////////////////
   
  for(int i=n/2-1;i>=0;i--){
        int idx=i;
        while(true){
            int l=2*idx+1;
            int r=2*idx+2;
            int smallest=idx;
            if(l<n && A[l]<A[smallest]) smallest=l;
            if(r<n && A[r]<A[smallest]) smallest=r;
           
            if(smallest!=idx){
            int t= A[idx];
            A[idx]= A[smallest];
            A[smallest]=t;
            idx=smallest;
            }
            else break;
       }
    }
    /////////////////////////////////////////////
    int heapSize=n;
    int sorted[100];
    for(int i =0;i<n;i++){
        sorted[i]=A[0];
        A[0]= A[heapSize-1];
        heapSize--;
        int idx =0;
        while (true){
            int l =2*idx+1;
            int r =2*idx+2;
            int smallest=idx;
            if(l<heapSize && A[l]<A[smallest]) smallest =l;
            if(r<heapSize && A[r]<A[smallest]) smallest=r;
            if(smallest!=idx){int t=A[idx];A[idx]=A[smallest];A[smallest]=t; idx=smallest;}
            else break;
        }
    }

    for(int i= 0;i<n;i++) cout <<sorted[i]<<" ";
    cout<<endl;
    return 0;
}
