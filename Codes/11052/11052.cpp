#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int p[10001];
int main(){
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++)
		cin >> arr[i];
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			p[i] = max(p[i], p[i-j] + arr[j]);
		}
	}
	
	cout << p[n];
	
	return 0;
}
