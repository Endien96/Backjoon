#include <iostream>
#include <algorithm>
using namespace std;

int arr[301];
int scr[301];

int main(){
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		int sc;
		cin >> sc;
		
		scr[i] = sc;
	}
	
	arr[1] = scr[1];
	arr[2] = arr[1] + scr[2];
	arr[3] = max(arr[1], scr[2]) + scr[3];
	
	for(int i = 4; i <= n; i++){
		arr[i] = max(arr[i-2], arr[i-3] + scr[i-1]) + scr[i];
	}
	
	cout << arr[n] << endl;
	
	return 0;
}
