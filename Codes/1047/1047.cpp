#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> size;
int main(){
	int n;
	
	int xm= 1000000, ym = 1000000;
	int xM = 0, yM = 0;
	
	cin >> n;
	for(int i = 0; i < n; i++){
		int x, y, s;
		cin >> x >> y >> s;
		
		if(x < xm)
			xm = x;
		
		if(y < ym)
			ym = y;
		
		if(x > xM)
			xM = x;
			
		if(y > yM)
			yM = y;
			
		size.push_back(s);
	}
	
	sort(size.begin(), size.end());
	
	int need = ((xM - xm) + (yM - ym))*2;
	bool state = false;
	int count = 0;
	for(int i = n-1; i>0; i--){
		if(need <= 0){
			cout << count << endl;
			state = true;
			break;
		}
		
		need -= size[i];
		count++;
	}
	
	if(!state)
		cout << 0 << endl;
		
	return 0;
}
