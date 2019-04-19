#include <stdio.h>
#include <stdlib.h>

int cnt0;
int cnt1;
int mem[40] = {1, 1, };

int fibonacci(int n) {
	switch(n){
		case 0:
			cnt0++;
			return mem[n];
		case 1:
			cnt1++;
			return mem[n];
		default:
			if(mem[n] > 0) return mem[n];
			else return fibonacci(n-1) + fibonacci(n-2);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int i = 0;
	
	for(i = 0; i < n; i++){
		int m;
		scanf("%d", &m);
		
		fibonacci(m);
		printf("%d %d\n", cnt0, cnt1);
		cnt0 = cnt1 = 0;
		
		printf("%d\n", mem[3]);
	}	
	
	return 0;
}
