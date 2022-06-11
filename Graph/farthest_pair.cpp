#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>
#define ll long long
#define ld long double
using namespace std;
struct pt{
    int x,y;
    pt(){};
    pt(int _x,int _y){
        x=_x;y=_y;
    }
    pt operator-( pt &a){
        return pt(x-a.x,y-a.y);
    }
};
vector<pt>p;
vector<pt>stk;
int cross( pt &a,  pt &b, pt &c){
    pt lhs=b-a,rhs=c-a;
    return lhs.x*rhs.y-lhs.y*rhs.x;
}
bool cmp(const pt &a,const pt &b){
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}
int dis(const pt &a,const pt &b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
void hull(){
    sort(p.begin(), p.end(),cmp);//依照x大小排序
    stk.push_back(p[0]);
    stk.push_back(p[1]);

    int top=2;
    for(int i=2;i<p.size();i++){
        while(top>=2 && cross(stk[top-2], stk[top-1],p[i])<=0){//使得stk內維持兩個點以上，並維護連續3個點的外積>0(逆時鐘旋轉)
            top--;
            stk.pop_back();
        }
        top++;
        stk.push_back(p[i]);
    }
    int rec=top+1;
    for(int i=p.size()-2;i>=0;i--){
        while(top>=rec&&cross(stk[top-2], stk[top-1], p[i])<=0){
            top--;
            stk.pop_back();
        }
        top++;
        stk.push_back(p[i]);
    }
    stk.pop_back();//考慮逆時針做完凸包後，最左端點被重複計算
    top--;
    stk.resize(top);
    return ;
}
int farthestdis(){
    int rec=0;
    for(int i=0;i<stk.size();i++){
        int j=i+1;
        while( dis(stk[i],stk[j])<dis(stk[i],stk[ (j+1)%stk.size() ]) ){
            j= (j+1)%stk.size();
        }
        rec=max(rec,dis(stk[i],stk[j]));
    }
    return rec;
}
int main(){
    int c;
    cin>>c;
    int m,n;
    for(int i=1;i<=c;i++){
        cin>>m>>n;
        p.push_back(pt(m,n));
    }
    hull();//尋找凸包
    int ans=farthestdis();//尋找最遠點對

    cout<<fixed<<setprecision(10)<<sqrt(ans)<<'\n';
}
