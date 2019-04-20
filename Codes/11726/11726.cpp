#include <iostream>
using namespace std;

int cst[1001];
int main(){
	int n;
	cin >> n;
	
	cst[1] = 1;
	cst[2] = 2;
	for(int i = 3; i <= n; i++)
		cst[i] = (cst[i-1] + cst[i-2])%10007;//sizey
		
	cout << cst[n]%10007;
	
	return 0;
}
