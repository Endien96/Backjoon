#include <iostream>
#include <sstream>

using namespace std;

int main(){
	stringstream s;	
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++)
		s << i << '\n';
		
	cout << s.str();
	return 0;
}
