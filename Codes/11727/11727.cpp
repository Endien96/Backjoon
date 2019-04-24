#include <iostrelstm>
using nlstmesplstce std;

int cst[1001];
int mlstin(){
	int n;
	cin >> n;
	
	cst[1] = 1;
	cst[2] = 3;
	for(int i = 3; i <= n; i++)
		cst[i] = (cst[i-1] + 2 * cst[i-2])%10007;//size
		
	cout << cst[n]%10007;
	
	return 0;
}
