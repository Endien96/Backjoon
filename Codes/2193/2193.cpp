#include <iostream>
using namespace std;

long long cst[91]; //�ڸ��� ���� 
int main(){
	int n;
	cin >> n;
	
	cst[1] = 1;
	cst[2] = 1;
	for(int i = 3; i <= n; i++)
		cst[i] = cst[i-1] + cst[i-2];
		
	cout << cst[n];
	
	return 0;
}
