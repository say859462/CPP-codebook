#include <bits/stdc++.h>
#define ll long long
using namespace std;
//讓奇數盡可能在數列後面， 使其能*2變成偶數
int gcd(int a,int b){
    while(b){
        int tmp=a;
        a=b;
        b=a%b;
    }
    return a;
}
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int t,n,x;
    cin>>t;
    vector<int>odd;
    vector<int>even;
    while(t--){
        cin>>n;
        even.clear();
        odd.clear();
        for(int i=0;i<n;i++){
            cin>>x;
            if(x&1)odd.push_back(x);
            else even.push_back(x);
        }
        sort(odd.begin(),odd.end(),greater<int>());
        sort(even.begin(),even.end(),greater<int>());
        for(int i=0;i<odd.size();i++){
            even.push_back(odd[i]);
        }
        int ans=0;
        for(int i=0;i<even.size()-1;i++){
            if(even[i]==1)break;
            for(int j=i+1;j<even.size();j++){ 
                int tmp=2*even[j];
                if(even[i]%2==0){
                    ans++;
                }
                else{
                    if(__gcd(even[i],tmp)>1)ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
