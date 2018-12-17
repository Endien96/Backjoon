#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;
int main(){
	stringstream s;
	int n;
	
	int x1, y1, r1;
	int x2, y2, r2;
	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x1 >> y1 >> r1;
		cin >> x2 >> y2 >> r2;
		
		if(x1 == x2 && y1 == y2 && r1 == r2){
			s << '-1' << '\n';
			continue;
		}
		else if(x1 == x2 && y1 == y2 && r1 != r2){
			s << '0' << '\n';
			continue;
		}
		
		if(pow(x2 - x1, 2) + pow(y2 - y1, 2) < pow(r1 + r2, 2))
			s << '2' << '\n';
		else if (pow(x2 - x1, 2) + pow(y2 - y1, 2) == pow(r1 + r2, 2))
			s << '1' << '\n';
		else
			s << '0' << '\n';
	}
	
	cout << s.str();
	return 0;
}
