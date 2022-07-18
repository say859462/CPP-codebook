#include <bits/stdc++.h>
using namespace std;
struct pt{
    int x,y;
    pt(){}
    pt(int _x,int _y){x=_x;y=_y;}
    bool operator<(const pt& p)const{
        if(x==p.x)return y<p.y;
        return x<p.x;
    }
};
map<pair<pt,pt>,int>mp;
bool check(int x,int y,int size){
    for(int i=0;i<size;i++){
        if(!mp.count(make_pair(pt(x,y+i),pt(x,y+1+i))))return false;
    }
    for(int i=0;i<size;i++){
        if(!mp.count(make_pair(pt(x+i,y),pt(x+i+1,y))))return false;
    }
    for(int i=0;i<size;i++){
        if(!mp.count(make_pair(pt(x+size,y+i),pt(x+size,y+1+i))))return false;
    }
    for(int i=0;i<size;i++){
        if(!mp.count(make_pair(pt(x+i,y+size),pt(x+i+1,y+size))))return false;
    }
    return true;
}
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int n,m;//n*n square,m interconnect lines
    char c;
    int a,b;
    int cnt=1;
    while(cin>>n>>m){
        mp.clear();
        if(cnt!=1)cout<<'\n'<<"**********************************"<<'\n'<<'\n';
        for(int i=0;i<m;i++){
            cin>>c>>a>>b;
            if(c=='H'){
                mp[make_pair(pt(a,b),pt(a,b+1))]=1;
            }
            else{
                mp[make_pair(pt(b,a),pt(b+1,a))]=1;
            }
        }
        
        int size[10]={0};
        for(int i=1;i<=n-1;i++){//size i square
            for(int j=1;i+j<=n;j++){
                for(int k=1;k+i<=n;k++){//dot (j,k)
                    if(check(j,k,i)){
                        size[i]++;
                    }
                }
            }
        }
        bool flag=1;
        cout<<"Problem #"<<cnt++<<'\n'<<'\n';
        for(int i=1;i<=n;i++){
            if(!size[i])continue;
            else{
                flag=0;
                cout<<size[i]<<" square (s) of size "<<i<<'\n';
            }
        }
        if(flag){
            cout<<"No completed squares can be found."<<'\n';
        }
    }
    return 0;
}
