#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	cin.tie(0);ios::sync_with_stdio(0);
	ll a,b,c;
	cin>>a>>b>>c;
	cout<< ((a+c-1)/c) * ((b+c-1)/c)<<'\n';
	return 0;
}
