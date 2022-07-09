#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    //採用生成的方式求出，若一個數x為醜數 則2x 3x 5x仍為醜數
    //利用set自動排序並且去重
    set<ll>s;s.insert(1);
    set<ll>::iterator it=s.begin();
    for(int i=0;i<1500;i++){
        ll x=*it;
        s.insert(2*x);s.insert(3*x);s.insert(5*x);
        it++;
    }
    it--;
    cout << "The 1500'th ugly number is " << *it << "." << endl; 
    return 0;
}
