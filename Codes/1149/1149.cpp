#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001][3];
int cst[1001][3];

int check(int i){
	if(arr[i][0] == cst[i][0])
		return 0;
	else if(arr[i][0] == cst[i][1])
		return 1;
	else
		return 2;
}
int main(){
	int n;
	cin >> n;

	for(int j = 1; j <= n; j++){
		for(int i = 0; i < 3; i++){
			int tmp;
			cin >> tmp;
			
			cst[j][i] = tmp;
		}
	}
	
	for(int i = 0; i < 3; i++)
		arr[1][i] = cst[1][i];
		
	for (int i = 2; i <= n; i++)
        for (int j = 0; j < 3; j++)
			arr[i][j] = cst[i][j] + min(arr[i-1][(j+1)%3], arr[i-1][(j+2)%3]);
		
	cout << min(arr[n][0], min(arr[n][1], arr[n][2])) << endl;
	
	return 0;
}
