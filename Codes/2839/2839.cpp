#include <iostream>

using namespace std;
int main(){
	int N;
	
	cin >> N;
	
	int f = N /5;
	
	for(int i = f; i >= 0; i--){
		if((N - (i * 5)) % 3 == 0){
			cout << (N - (i * 5)) / 3 + i  << endl;
			return 0;
		}
	}
	
	cout << -1 << endl;
	return 0;
}
