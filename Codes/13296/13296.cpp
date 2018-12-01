#include <iostream>

using namespace std;
int main(){
	int n, m, p;
	int square[20][20];
	
	cin >> n >> m >> p;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		
			cin >> square[i][j];
		
	int temp;	
	
	for(int t1 = 1; t1 < n*m; t1++){
		if(func(t1)){
			cout << 1;
			cout << t1 << end;
			
			return 0;
		}
			for(int t2 = 1; t2 < n*m; t2++){
			if(func(t2)){
				cout << 2;
				cout << t1 << t2 << end;
				
				return 0;
			}
			
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << square[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Complete" << endl;
	
	return 0;
}

bool func(temp){
if(temp == -1)
			break;
		
		int col = temp / 5;
		int row = temp % 5;
		
		if(row == 0){
			col--;
			row = 5;
		}
		for(int j = 0; j < n; j++){
			square[j][row-1] = square[j][row-1] >= p ? 1 : (square[j][row-1] + 1);
		}
		square[col][row-1]--;
		for(int j = 0; j < m; j++){
			square[col][j] = square[col][j] >= p ? 1 : (square[col][j] + 1);
		}
	
}
