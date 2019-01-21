#include <iostream>

int num[1000001];
using namespace std;
int main(){
	long long min, max;
	long long cnt;
	
	cin >> min >> max;
	for(long long i = 2; i*i < max; i++){
		long long x = min / (i*i);
        if (min % (i*i) != 0)
            x++;
 
        while (x*(i*i) <= max){
            num[x*(i*i) - min] = 1;
            x++;
        }
	}
	
	for (int i = 0; i <= max - min; i++){
        if (num[i] == 0)
            cnt++;
    }
    
    cout << cnt << endl;
}
