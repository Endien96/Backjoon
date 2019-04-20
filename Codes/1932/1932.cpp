#include <iostream>
#include <algorithm>
using namespace std;

long long arr[501][501];
int cst[501][501];
int main(){
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1;j <= i; j++){
			int tmp;
			cin >> tmp;
			
			cst[i][j] = tmp;
		}
	}
	
	arr[1][1] = cst[1][1];
	for(int i = 2; i <= n; i++){
		arr[i][1] = arr[i-1][1] + cst[i][1];
		
		arr[i][i] = arr[i-1][i-1] + cst[i][i];
		
		for(int j = 2; j < i; j++){
			arr[i][j] = max(arr[i-1][j-1], arr[i-1][j]) + cst[i][j];
		}
	}
	
	int max = 0; //쓰레기값! 
	for(int i = 1; i <= n; i++)
		max = max > arr[n][i] ? max : arr[n][i];
		
	cout << max << endl;
	 
	return 0;
}
