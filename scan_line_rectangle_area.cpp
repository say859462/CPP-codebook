#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int mx=1e6+10;
struct Line{
    ll x,y1,y2,state;
    Line(){}
    Line(ll a,ll b,ll c,ll d){
        x=a;y1=b;y2=c;state=d;
    }
    
}line[mx];
struct node{
    ll len,cnt;

}tree[mx<<2];
bool comp(Line a,Line b)
{
	if (a.x!=b.x)return a.x<b.x;
	else return a.y1<b.y1;
}
ll y[mx]={0};
void push(int idx,int l,int r){
    if(tree[idx].cnt){
        tree[idx].len=y[r]-y[l];
    }
    else{
        tree[idx].len=tree[idx<<1].len+tree[idx<<1|1].len;
    }
}
void update(int idx,int l,int r ,ll ql,ll qr,ll val){
    if(ql<=y[l] && y[r]<=qr){
        tree[idx].cnt+=val;
        push(idx,l,r);
        return ;
    }
    if(r-l==1)return ;//避免點區間
    if(qr<=y[l]||ql>=y[r])return ;
    ll mid=(l+r)>>1;
    if(ql < y[mid]) update(idx<<1,l,mid,ql,qr,val);
    if(qr > y[mid]) update(idx<<1|1,mid,r,ql,qr,val);
    push(idx,l,r);
    return ;
}
int main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    ll n;
    ll x1,y1,x2,y2;
    cin>>n;
    int cnt=1;
    for(int i=1;i<=n;i++){
        cin>>x1>>y1>>x2>>y2;
        y[cnt]=y1;
        line[cnt++]=Line(x1,y1,y2,1);
        y[cnt]=y2;
        line[cnt++]=Line(x2,y1,y2,-1);
    }
    cnt--;
    sort(y+1,y+cnt+1);
    sort(line+1,line+cnt+1,comp);
    int len=unique(y+1,y+1+cnt)-y-1;
   // cout<<len<<'\n';
    ll ans=0;
    for(int i=1;i<cnt;i++){
        update(1,1,len,line[i].y1,line[i].y2,line[i].state);
        ans+= tree[1].len *(line[i+1].x-line[i].x);
    }
    cout<<ans<<'\n';
    return 0;
}
