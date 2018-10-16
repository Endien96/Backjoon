#include <iostream>

using namespace std;

#define MAX_NUM 100
#define MAX_TEST 50

int main(){
	int T;
	cin >> T;
	
	int v[MAX_NUM] = {};
	int f[MAX_NUM] = {};
	int c[MAX_NUM] = {};
	
	int count[MAX_TEST] = {};
	
	for(int i = 0 ; i < T; i++){
		int N, D;
		count[i] = 0;
		
		cin >> N >> D;
		
		for(int j = 0; j < N; j++)
			cin >> v[j] >> f[j] >> c[j];
		
		
		for(int j = 0; j < N; j++)
			if((float)f[j] / (float)c[j] * v[j] >= D)
				count[i]++;
	}
	
	for(int i = 0; i < T; i++)
		cout << count[i] << endl;
		
	return 0;
}
