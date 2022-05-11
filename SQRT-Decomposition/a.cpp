#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#define ll long long
#define op cin.tie(0);ios::sync_with_stdio(0);
using namespace std;
int n,q;
int u,v,x,y,w;
const int mx=1e4+10;
struct e{
    int to,weight;
};
vector<e> edge[mx];
int main(){
    op
    cin>>n>>q;
    for(int i=0;i<n-1;i++){
        cin>>u>>v>>w;
        edge[u].push_back(e{v,w});
        edge[v].push_back(e{u,w});
    }
    
}