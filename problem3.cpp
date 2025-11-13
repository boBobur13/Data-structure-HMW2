#include <iostream>
using namespace std;
int main() {
   int A[100], sizePQ=0;
   int q;
    cin>>q;
    for(int i=0;i<q;i++){
        string cmd;
        cin>>cmd;
        if(cmd=="insert"){
            int x;
            cin>>x;
            A[sizePQ]=x;
            sizePQ++;
        }
        else if (cmd=="get"){
            if(sizePQ==0) cout<<"EMPTY"<<endl;
            else{
                int maxVal=A[0];
                for(int j=1;j<sizePQ;j++) if(A[j]>maxVal) maxVal=A[j];
                cout<<maxVal<<endl;
            }
        }
        else if(cmd=="extract"){
            if(sizePQ==0) cout<<"EMPTY"<<endl;
            else{
                int maxVal=A[0], pos=0;
                for(int j=1;j<sizePQ;j++){
                    if(A[j]>=maxVal){maxVal=A[j]; pos=j;}
                }
                cout<<maxVal<<endl;
                for(int j=pos;j<sizePQ-1;j++) A[j]=A[j+1];
                sizePQ--;
            }
        }
        else if(cmd=="size") cout<<sizePQ<<endl;
    }
    return 0;
}
