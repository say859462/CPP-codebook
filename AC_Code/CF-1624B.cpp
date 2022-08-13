#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int t;
    cin>>t;
    ll a,b,c,d;
    while(t--){
        cin>>a>>b>>c;
        d=b-a;
        if(b+d==c){
            cout<<"YES"<<'\n';
            continue;
        }
        //a b
        d=b-a;
        if( (b+d)%c==0 &&c!=0 &&(b+d)>=c){
            cout<<"YES"<<'\n';
            continue;
        }
        //a c
        if( (c+a)%2==0 ){
            if( ((c+a)/2)%b==0 && b!=0 &&((c+a)/2)>=b){
                cout<<"YES"<<'\n';
                continue;
            }
        }

        //b c
        d=c-b;
        if( (b-d)%a==0 && a!=0 && (b-d)>=a){
            cout<<"YES"<<'\n';
            continue;
        }
        cout<<"NO"<<'\n';
    }
    return 0;
}
