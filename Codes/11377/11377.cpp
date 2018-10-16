#include <iostream>
#include <vector>
#include <cstring>

#define MAX_WORK 1000

using namespace std;


bool dfs(int n);
int bmatching();

vector<int> per[MAX_WORK];
bool visited[MAX_WORK];
int work[MAX_WORK] = {-1};

int n, m, k;
	
int main(){
	int temp;

	//input
	cin >> n >> m >> k;
	
	for(int i = 1; i <= n; i++){
		cin >> temp;
		
		for(int j = 0; j < temp; j++){
			int val;
			cin >> val;
			per[i].push_back(val);
		}
	}
	//calc
	int ans = bmatching();
	
	cout << ans << endl;
	
	return 0;
}

bool dfs(int num){
	int w;
    visited[num] = true;
    
    for(int i = 0; i < per[num].size(); i++){
    	w = per[num][i];
    	
        if(work[w] == 0 || !visited[work[w]] && dfs(work[w])){
        	work[w] = num;
            return true;
        }
    }
    
    return false;
}

int bmatching()
{
    int p;
    int ans = 0;
 
    for (p = 1; p <= n; p++) {
        memset(visited, false, sizeof(visited));
        if(dfs(p)) {
		ans++;
	}
    }
    
    for (p = 1; p <= n && k > 0; p++) {
        memset(visited, false, sizeof(visited));
        if (dfs(p)) {
            ans++;
            k--;
        }
    }
 
    return ans;
}
