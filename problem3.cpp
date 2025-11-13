#include <iostream>
using namespace std;

int main() {
    int A[100];
    int sizePQ = 0;
    int q;
    cin >> q;
    cin.ignore();

    for(int i = 0; i < q; i++){
        string cmd;
        getline(cin, cmd);

        if(cmd.substr(0,6) == "insert"){
            int x = stoi(cmd.substr(7));
            A[sizePQ] = x;
            sizePQ++;
        }
        else if(cmd == "get max"){
            if(sizePQ == 0) cout << "EMPTY" << endl;
            else{
                int maxVal = A[0];
                for(int j = 1; j < sizePQ; j++)
                    if(A[j] > maxVal) maxVal = A[j];
                cout << maxVal << endl;
            }
        }
        else if(cmd == "extract max"){
            if(sizePQ == 0) cout << "EMPTY" << endl;
            else{
                int maxVal = A[0], pos = 0;
                for(int j = 1; j < sizePQ; j++){
                    if(A[j] > maxVal){
                        maxVal = A[j];
                        pos = j;
                    }
                }
                cout << maxVal << endl;
                for(int j = pos; j < sizePQ-1; j++) A[j] = A[j+1];
                sizePQ--;
            }
        }
        else if(cmd == "size") cout << sizePQ << endl;
    }

    return 0;
}
