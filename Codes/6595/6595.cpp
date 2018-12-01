#include <iostream>
#include <vector>

#define MAX 100000

using namespace std;

vector<int> vec;
vector<int> pos;
vector<int> temp;
int n;

int func();
void qsort(vector<int>& v, int s, int e);

int main(){
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		int tp;
		cin >> tp;
		
		vec.push_back(tp);
	}
	
	cout << func() << endl;
}

int func(){
	int smallest = 1000000001;
	pos.push_back(-1);
	for(int i = 0; i < n; i++){
		if(vec[i] < smallest){
			smallest = vec[i];
			pos.push_back(i);
		}
	}
	int sum = n * smallest;
	
	while(true){
		if(pos.size() == n) return sum;
		
		qsort(pos, 0, pos.size());
		
		smallest = 1000000001;
		for(int j = 0; j < pos.size(); j++){
			for(int i = pos[0]; i < pos[1]; i++){
				if(vec[i] < smallest){
					smallest =vec[i];
					temp.push_back(i);
				}
			}
			int t = (pos[1] - pos[0] - 1) * smallest;
			if(t > sum) 
				sum = t;
		}
	}
}

void qsort(vector<int>& v, int s, int e){
	int pivot = v[s];
	int bs = s, be = e;
	
	while(s < e){
		while(pivot <= v[e] && s < e)
			e--;
		
		if(s > e)
			break;
		
		while(pivot >= v[s] && s < e)
			s++;
		
		if(s > e)
			break;
			
		swap(v[s], v[e]);
	}
	
	swap(v[bs], v[s]);
	
	if(bs < s)
		qsort(v, bs, s-1);
	if(be > e)
		qsort(v, s+1, be);
}
