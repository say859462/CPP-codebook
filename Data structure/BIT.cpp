#include <iostream>
using namespace std;
int BIT[mx];
int lowbit(int x){
  return x&(-x);
}
int query(int x){
    int ret=0;
    while(x){ // 當不為 0 時
        ret += BIT[x];  // 回傳值加上BIT[x]
        x -= lowbit(x); // 每次減掉自己的lowbit
    }
    return ret;
}
void update(int x,int v){
    while(x<=n){
        bit[x] += v;
        x += lowbit(x);
    }
}
/*update(l, v);
update(r+1, -v); 修改區間BIT[L,R]*/
int main(){

}
