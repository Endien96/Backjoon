#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>

using namespace std;

int p_kth(std::vector<int> &a){
	vector< vector<int> > b(10);
	vector<int> c = a;
	
	int mod = 10;
	int dev = 1;
	
	int size = a.size();
	int stack=0;
	int ms=0;
	int s=0;
	
	for(int i = 0; i < c.size(); i++){
		s=0;
		while(c[i] != 0){
			s++;
			c[i] /= 10;
		}
		if(ms < s)
			ms = s;	
	}
	
	for (int i = 0; i < ms; i++) {
		for (int j = 0; j < size; j++) {
			int bucket = (a[j] % mod) / dev;
			b[bucket].push_back(a[j]);
			
			if(a[j] == 0)
				stack++;
		}

		if(stack == a.size())
			break;
		int pos = 0;
		a.clear();
		for (int j = 0; j < 10; j++) {
			int bsize = b[j].size();
			for (int h = 0; h < bsize; h++)
				a.push_back(b[j][h]);
				
			b[j].clear();
		}
		
		mod *= 10;
		dev *= 10;
	}

	return 0;
	
}

int n_kth(std::vector<int> &a){
	vector< vector<int> > b(10);
	
	for(int i = 0; i < a.size(); i++)
		a[i] = abs(a[i]);
		
	vector<int> c = a;
	int mod = 10;
	int dev = 1;
	
	int size = a.size();
	int stack=0;
	int ms=0;
	int s=0;
	
	for(int i = 0; i < c.size(); i++){
		s=0;
		while(c[i] != 0){
			s++;
			c[i] /= 10;
		}
		if(ms < s)
			ms = s;	
	}
	
	for (int i = 0; i < ms; i++) {
		for (int j = 0; j < size; j++) {
			int bucket = (a[j] % mod) / dev;
			b[bucket].push_back(a[j]);
			if(a[j] == 0)
				stack++;
		}

		if(stack == a.size())
			break;
			
		int pos = 0;
		a.clear();
		for (int j = 0; j < 10; j++) {
			int bsize = b[j].size();
			for (int h = 0; h < bsize; h++)
				a.push_back(b[j][h]);
			
			b[j].clear();
		}
		
		mod *= 10;
		dev *= 10;
	}
	
	for(int i = 0; i < size; i++)
		a[i] *= -1;
		
	vector<int> d(size);
	d = a;
	
	a.clear();
	for(int i = 1; i <= size; i++)
		a.push_back(d[size-i]);
		
	
	return 0;
}


int kth(std::vector<int> &a, int k) {
	std::vector<int> pos;
	std::vector<int> neg;
	
	for(int i = 0; i < a.size(); i++){
		if(a[i] < 0)
			neg.push_back(a[i]);
		else
			pos.push_back(a[i]);
	}
	
	p_kth(pos);
	n_kth(neg);
	
	for(int i = 0; i < pos.size(); i++)
		neg.push_back(pos[i]);
		
	
	return neg[k-1];
}

int main() {
	int n;
	vector<int> a;
	clock_t begin, end;
	
	srand((unsigned int)time(0));
	
	for (int i = 0; i < 50000; i++) {
		a.push_back(rand() * pow(-1, rand() % 2));
	}
	
	begin = clock();
	cout << kth(a, 2) << endl;
	end = clock();
	
	cout << (end - begin)/1000.0 << endl;
	return 0;
}


