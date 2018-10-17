#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	int f = 1723;
	int D;
	
	cin >> D;
	
	int calc = f / pow(10, abs(D - 4)); 
	
	calc %= 10;
	
	cout<< calc <<endl;
}
