#include <iostream>

using namespace std;

int main() {
    int matrix [6][6];
    matrix [0][0] = NULL;
    for (int i=1; i<6; i++){
        matrix[i][0]=i;
    }
    for (int i=1; i<6; i++){
        matrix[0][i]=i;
    }
    matrix[0][0]=NULL;
    matrix[1][1]=0;matrix[1][2]=0;matrix[1][3]=0;matrix[1][4]=0;matrix[1][5]=1;
    matrix[2][1]=1;matrix[2][2]=0;matrix[2][3]=1;matrix[2][4]=0;matrix[2][5]=1;
    matrix[3][1]=0;matrix[3][2]=1;matrix[3][3]=0;matrix[3][4]=0;matrix[3][5]=0;
    matrix[4][1]=0;matrix[4][2]=0;matrix[4][3]=1;matrix[4][4]=0;matrix[4][5]=1;
    matrix[5][1]=0;matrix[5][2]=0;matrix[5][3]=0;matrix[5][4]=0;matrix[5][5]=0;
    for (int i=0; i<6; i++){
        for (int j=0; j<6; j++) {
            if (j == 0 && i == 0) {
                cout << "     ";
            } else if (i==0) {
                cout << "  v" << matrix[j][i] << "  ";
            } else if (j==0) {
                cout << "  v" << matrix[j][i] << "  ";
            } else {
                cout << "  " << matrix[j][i] << "   ";
            }
        }
        cout << endl << endl;
    }
    for (int i=1; i<6; i++){
        int sum=0;
        cout << "Sasiedzi   v" << i << ":  ";
        for (int j=1; j<6; j++){
            if (matrix[j][i]==1) {
                sum = j - 1;
                cout << "v" << sum << "  ";
            }
        }
        cout << endl;
    }
    cout << endl;
    for (int i=1; i<6; i++){
        int wych=0;
        int wcho=0;
        for (int j=1; j<6; j++){
            if (matrix[j][i]==1) {
                wych++;
            }
        }
        for (int j=1; j<6; j++){
            if (matrix[i][j]==1) {
                wcho++;
            }
        }
        cout << "Stopien wychodzacy " << i << ": " << wych << endl;
        cout << "Stopien wychodzacy " << i << ": " << wcho << endl;
        cout << endl;
    }
    return 0;
}
