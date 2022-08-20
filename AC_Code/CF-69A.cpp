#include <bits/stdc++.h>
#define ll long long
#define rep(x) for(int i=0;i<x;i++)
using namespace std;

int main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int n;
	cin>>n;
	int a,b,c;
	int sum1=0,sum2=0,sum3=0;
	rep(n){
		cin>>a>>b>>c;
		sum1+=a;sum2+=b;sum3+=c;
	}
	if(!sum1 && !sum2 && !sum3)cout<<"YES"<<'\n';
	else cout<<"NO"<<'\n';
	return 0;
}
