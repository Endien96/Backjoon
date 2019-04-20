#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int cst[100001];
int main(){
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++)
		cin >> cst[i];
		
	arr[1] = cst[1];
	for(int i = 2; i <= n; i++){
		if(arr[i-1] < 0)
			arr[i] = cst[i];
		else
			arr[i] = arr[i-1] + cst[i];
	}
	
	int max = arr[1];
	for(int i = 2; i <= n; i++)
		max = max > arr[i] ? max : arr[i];
	
	cout << max;
	
	return 0;
}
