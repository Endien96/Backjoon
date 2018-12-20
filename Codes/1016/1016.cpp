#include <iostream> 
using namespace std; 
bool check[1000001]; 

int main() { 
	long long min, max; 
	cin >> min >> max; 
	for (long long i = 2; i * i <= max; i++){ 
		long long st = min / (i * i); 
		if (st * i * i != min) st++; 
		
		for (long long j = st; i * i * j <= max; j++) { 
			check[i * i * j - min] = true; 
		} 
	} 
	
	int count = 0; 
	
	for (int i = 0; i < max - min + 1; i++) { 
		if (!check[i]) count++; 
	} 
	
	cout << count << endl; 
	return 0; 
} 
