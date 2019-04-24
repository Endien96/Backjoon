#include <iostream>
#include <cstring>
using namespace std;

int arr[31][31];
int main() {
	int t;

	cin >> t;
 
    for (int tc = 0; tc < t; tc++) {
    	int n, m;
		cin >> n >> m;
		
		for(int i = 1; i <= n; i++)
			memset(arr[i], 0, sizeof(int) * m);
			
        for (int j = 1; j <= m; j++) {
            arr[1][j] = j;
            
            for (int i = 2; i <= j; i++) 
                arr[i][j] = arr[i - 1][j - 1] + arr[i][j - 1];
        }
    	
    	cout << arr[n][m] << endl;
	}
 
    return 0;
}
