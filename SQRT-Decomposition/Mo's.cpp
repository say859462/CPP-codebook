#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
struct qu{
  int l,r,id;
};

bool cmp(const qu &a,const qu &b){
  int len=sqrt(n);
  if(a.l/len==b.l/len){
    return a.r<b.r;
  }
  return a.l<b.l;
}

void add(int x){}
void sub(int x){}
vector<query> q;
void add(int index){ return ; }    
void sub(int index){ return ; }    
void solve(){
    sort(q.begin(),q.end());
    for(int i=0,l=-1,r=0;i<n;i++){
        while(l>q[i].l)    add(--l);
        while(r<q[i].r)    add(++r);    //記得要先做新增元素的
        while(l<q[i].l)    sub(l++);    //再做移除元素的
        while(r>q[i].r)    sub(r--);
        ans[q[i].id] = num;             
  }    
}
