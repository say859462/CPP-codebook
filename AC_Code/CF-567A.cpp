#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int t,n,k;
    cin>>n;
    vector<int>num;
    num.resize(n);
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    vector< pair<int,int> > ans;
    ans.push_back(make_pair(abs(num[num.size()-1]-num[0]),abs(num[0]-num[1])));
    for(int i=1;i<n-1;i++){
        int mx=0;
        int mn=0x3f3f3f3f;
        mx=max(abs(num[i]-num[0]),abs(num[i]-num[num.size()-1]));
        mn=min(abs(num[i]-num[i+1]),abs(num[i]-num[i-1]));
        ans.push_back(make_pair(mx,mn));
    }
    int tail=num.size()-1;
    ans.push_back(make_pair(num[tail]-num[0],num[tail]-num[tail-1]));
    for(int i=0;i<n;i++){
        cout<<ans[i].second<<" "<<ans[i].first<<'\n';
    }
    return 0;
}
