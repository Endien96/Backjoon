#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

#define MAX_SIZE 1001
 
using namespace std;
char block[1000];
 
int dp[1000];
int n;
 
int dfs(int pos);

int main() {
    cin >> n;
    
    for (int i = 1; i <= n; i++)
        cin >> block[i];
    
 
    memset(dp, -1, sizeof(dp));
 
    int ans = dfs(1);
    cout << (ans == MAX_SIZE ? -1 : ans);
 
    return 0;
}
 
int dfs(int pos) {
    if (pos == n) 
		return 0;
 
    int temp = dp[pos];
    if (temp != -1) 
		return temp;
		
    temp = MAX_SIZE;
    
    for (int i = pos; i <= n; i++) 
    	switch(block[pos]){
    		case 'B':
    			if(block[i] == 'O')
	    			temp = min(temp, dfs(i) + (int)pow(i - pos, 2));
    			break;
    		case 'O':
    			if(block[i] == 'J')
	    			temp = min(temp, dfs(i) + (int)pow(i - pos, 2));
    			break;
    		case 'J':
    			if(block[i] == 'B')
	    			temp = min(temp, dfs(i) + (int)pow(i - pos, 2));
    			break;
			}
 
    return temp;
}
 
