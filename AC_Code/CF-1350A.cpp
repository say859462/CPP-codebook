#include <bits/stdc++.h>
using namespace std;
const int mx=1e6+5;
int lst[mx]={0};
vector<int>prime;
void init(){
    for(int i=2;i<mx;i++){
        if(!lst[i]){
            lst[i]=i;
            prime.push_back(i);
        }
        for(int j=2; i*j <mx;j++){
            if(lst[i*j])continue;
            lst[i*j]=i;
        }
    }
    return ;
}
//even->a+=2*k;
//odd-<prime?
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    init();
    int t,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(a%2==0){
            cout<<a+2*b<<'\n';
        }
        else{
            if(lst[a]==a){//prime
                cout<<a*2+(b-1)*2<<'\n';
            }
            else{
                int rec=0;
                for(int i=0;i<prime.size();i++){
                    if(a%prime[i]==0){
                        rec=prime[i];
                        break;
                    }
                }
                cout<<a+rec+2*(b-1)<<'\n';
            }
        }
    }
    return 0;
}
