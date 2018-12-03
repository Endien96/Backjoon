#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

void func3(int bit) {
	cout << bit << " ";
}

void func2(int root, int max, int n, int bit) {
	cout << root << " ";

	int left = root - pow(2, max - n);
	int right = root - 2 * pow(2, max - n);

	if (n > 2) {
		func2(left, max, n - 1, bit);
		func2(right, max, n - 1, bit + pow(2, max - n));
	}
	else {
		cout << bit << " ";
		cout << bit + pow(2, max - n) << " ";
	}
		
}

void func(int n) {
	int t = pow(2, n) - 1;
	
	if(n > 1)	
		func2(t, n, n, 1);
	else
		switch (n) {
		case 1:
			cout << "1";
			break;
		}
}

int main() {
	int n;
	cin >> n;

	func(n);
	cout << endl;

	return 0;
}
