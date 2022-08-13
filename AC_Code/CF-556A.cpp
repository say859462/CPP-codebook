#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int n;
    cin>>n;
    int zero=0,one=0;
    char k;
    for(int i=0;i<n;i++){
        cin>>k;
        if(k=='0')zero++;
        else one++;
    }
    cout<<abs(one-zero)<<'\n';
    return 0;
}
