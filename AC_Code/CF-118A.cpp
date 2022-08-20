#include <bits/stdc++.h>
using namespace std;
string vowels="aoyeui";
bool check(char x){
	for(int i=0;i<vowels.size();i++){
		if(x==vowels[i])return true;
	}
	return false;
}
int main(){
	cin.tie(0);ios::sync_with_stdio(0);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		s[i]=tolower(s[i]);
	}
	vector<char>ans;
	for(int i=0;i<s.size();i++){
		if(check(s[i]))continue;
		ans.push_back('.');
		ans.push_back(s[i]);
	}
	for(int i=0;i<ans.size();i++)cout<<ans[i];
	return 0;
}
