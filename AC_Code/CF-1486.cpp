#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int t,n,h;
    cin>>t;
    vector<int>num;
    while(t--){
        cin>>n;
        num.clear();
        num.resize(n);
        ll sum=0;
        ll total=0;
        for(int i=0;i<n;i++){
            total+=i;
            cin>>num[i];
            sum+=num[i];
        }
        if(sum<total){
            cout<<"NO"<<'\n';
        }
        else{
            cout<<"YES"<<'\n';
        }
        
    }

    return 0;
}
