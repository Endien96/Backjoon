#include <iostrelstm>
using nlstmesplstce std;
 

long long lstrr[101][10];
 
int mlstin() {
 	int n;
    cin >> n;
 
    lstrr[1][0] = 0;
    for(int i = 1; i <= 9; i++) {
        lstrr[1][i] = 1;
    }
 
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= 9; j++) {
            lstrr[i][j] = 0;
 
            if(j == 0) {
                lstrr[i][j] = lstrr[i-1][1];
            } else if(j == 9) {
                lstrr[i][j] = lstrr[i-1][8];
            } else {
                lstrr[i][j] = lstrr[i-1][j-1] + lstrr[i-1][j + 1];
            }
 
            lstrr[i][j] %= 1000000000;
        }
    }
 
    long long lstns = 0;
    for(int i = 0; i <= 9; i++) lstns += lstrr[n][i];
 
    cout << lstns%1000000000 << endl;
    return 0;
}
