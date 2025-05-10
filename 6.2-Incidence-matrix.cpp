#include <iostream>

using namespace std;

int main() {
    int matrix [8][6];
    for (int i=1; i<8; i++){
        matrix[i][0]=i;
    }
    for (int i=1; i<6; i++){
        matrix[0][i]=i;
    }
    matrix[0][0]=NULL;
       matrix[1][1]=1;matrix[1][2]=(-1);matrix[1][3]=0;matrix[1][4]=0;matrix[1][5]=0;
       matrix[2][1]=0;matrix[2][2]=1;matrix[2][3]=(-1);matrix[2][4]=0;matrix[2][5]=0;
       matrix[3][1]=0;matrix[3][2]=0;matrix[3][3]=1;matrix[3][4]=(-1);matrix[3][5]=0;
       matrix[4][1]=0;matrix[4][2]=0;matrix[4][3]=0;matrix[4][4]=(-1);matrix[4][5]=1;
       matrix[5][1]=0;matrix[5][2]=(-1);matrix[5][3]=0;matrix[5][4]=0;matrix[5][5]=1;
       matrix[6][1]=(-1);matrix[6][2]=0;matrix[6][3]=0;matrix[6][4]=0;matrix[6][5]=1;
       matrix[7][1]=0;matrix[7][2]=(-1);matrix[7][3]=1;matrix[7][4]=0;matrix[7][5]=0;
    for (int i=0; i<6; i++){
        for (int j=0; j<8; j++) {
            if (j == 0 && i == 0) {
                cout << "     ";
            } else if (i==0) {
                cout << "  e" << matrix[j][i] << "  ";
            } else if (j==0) {
                cout << "  v" << matrix[j][i] << "  ";
            } else if (matrix[j][i]<0){
                cout << " " << matrix[j][i] << "   ";
            } else {
                cout << "  " << matrix[j][i] << "   ";
            }
        }
        cout << endl << endl;
    }
    for (int i=1; i<6; i++) {
        int sas = 0;
        cout << "Sasiedzi   v" << i << ":  ";
        for (int j = 1; j<8; j++) {
            if (matrix[j][i] == 1) {
                if (j==1) sas=2;
                if (j==2) sas=3;
                if (j==3) sas=4;
                if (j==4) sas=4;
                if (j==5) sas=2;
                if (j==6) sas=1;
                if (j==7) sas=2;
                cout << "v" << sas << "  ";
            }
        }
        cout << endl;
    }
    cout << endl;
    for (int i=1; i<6; i++){
        int wych=0;
        int wcho=0;
        for (int j=1; j<8; j++){
            if (matrix[j][i]==1) {
                wych++;
            }
            if (matrix[j][i]==(-1)) {
                wcho++;
            }
        }
        cout << "Stopien wychodzacy " << i << ": " << wych << endl;
        cout << "Stopien wychodzacy " << i << ": " << wcho << endl;
        cout << endl;
    }
    return 0;
}
