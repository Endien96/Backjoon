#include <iostream>
#include <algorithm>
using namespace std;

long long arr[10001];
int cst[10001];
int main(){
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		int tmp;
		cin >> tmp;
		
		cst[i] = tmp;
	}
	
	arr[1] = cst[1];
	arr[2] = arr[1] + cst[2];
	
	for(int i = 3; i <= n; i++)
		arr[i] = max(max(arr[i-2] + cst[i], arr[i-3] + cst[i-1]+cst[i]), arr[i-1]);
	
	
	cout << max(max(arr[n], arr[n-1]), arr[n-2]);
	
	return 0;
} 
