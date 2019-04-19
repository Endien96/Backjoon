#include <iostream>
#include <algorithm>

using namespace std;

int buy[50];
int need[1023];

int main() {
	int n;
	cin >> n;
	
	int sum = 0;
	int cnt = 0;

	for (int i = 0; i < n; i++) {	
		cin >> buy[i];
		sum += buy[i];
	}
	
	cin >> n;
	
	int sum2 = 0;
	for (int i = 0; i < n; i++){
		cin >> need[i];
		sum2 += need[i];
	}
	cout << sum << endl;
	cout << sum2 << endl;

	sort(need, need + n);

	for (int i = 0; i < n; i++) {
		if (sum <= 0){
			cnt--;
			break;
		}

		cnt++;
		sum -= need[i];
	}

	
	cout << cnt << endl;
	
	return 0;
}
