#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        if(n==1)cout<<9;
        else if(n==2)cout<<98;
        else{
            cout<<9;
            for(int i=1;i<n;i++){
                cout<<(i+7)%10;
            }
        }
        cout<<'\n';
    }
    return 0;
}
