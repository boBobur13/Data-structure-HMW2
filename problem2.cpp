#include <iostream>
using namespace std;
void heapDown(int A[], int heapSize, int idx){
 while(true){
 int l = 2*idx + 1;
     int r = 2*idx + 2;
        int smallest = idx;
        if(l < heapSize && A[l] < A[smallest]) smallest = l;
        if(r < heapSize && A[r] < A[smallest]) smallest = r;
////////////////////////////////////////
        if(l < heapSize && r < heapSize && A[l] == A[r] && A[l] < A[smallest]) smallest = l;

        if(smallest != idx){
            swap(A[idx], A[smallest]);
             idx = smallest;
        } else break;
    }
}
int main(){
 int n;
 cin >> n;
 int A[100];
  for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = n/2 - 1; i >= 0; i--) heapDown(A, n, i);
    int heapSize = n;
    int sorted[100];
    for(int i = 0; i < n; i++){
        sorted[i] = A[0];
        A[0] = A[heapSize - 1];
        heapSize--;
        heapDown(A, heapSize, 0);
    }
    for(int i = 0; i < n; i++) cout << sorted[i] << " ";
    cout << endl;
    return 0;
}

