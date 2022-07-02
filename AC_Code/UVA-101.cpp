#include <bits/stdc++.h>
using namespace std;
int n, f[30];
vector<int> h[30];
void clear(int a){
    int fa=f[a];
    int pos=0; while(pos<h[fa].size()&&h[fa][pos]!=a) ++pos;
    int newSize=++pos;
    while(pos<h[fa].size()) h[h[fa][pos]].push_back(h[fa][pos]), f[h[fa][pos]]=h[fa][pos], ++pos;
    h[fa].resize(newSize);
}
void move(int a, int b){
    int fa=f[a], fb=f[b];
    int pos=0; while(pos<h[fa].size()&&h[fa][pos]!=a) ++pos;
    int newSize=pos;
    while(pos<h[fa].size()) h[fb].push_back(h[fa][pos]), f[h[fa][pos]]=fb, ++pos;
    h[fa].resize(newSize);
}
int main(){
    cin>>n;
    for (int i=0; i<n; ++i) h[i].push_back(i), f[i]=i;
    string cmd1, cmd2; int a, b;
    while(cin>>cmd1>>a>>cmd2>>b){
        if (f[a]==f[b]) continue;
        if (cmd1=="move") clear(a);
        if (cmd2=="onto") clear(b);
        move(a, b);
    }
    for (int i=0; i<n; ++i){
        cout<<i<<":";
        for (int j=0; j<h[i].size(); ++j)
            cout<<" "<<h[i][j];
        cout<<endl;
    }
    return 0;
}
