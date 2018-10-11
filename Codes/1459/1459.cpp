#include <iostream>
#include <algorithm>
using namespace std;long long x,y,w,s;main(){cin>>x>>y>>w>>s;long long mod=(x+y)%2;if(x<y)swap(x,y);cout<<min((x+y)*w,min((x-mod)*s+mod*w,y*s+(x-y)*w));return 0;}

