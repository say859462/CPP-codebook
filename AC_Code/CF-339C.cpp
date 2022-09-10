#include<cstdio>
#include<cstring>
#include<cctype>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<sstream>
#include<iterator>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<list>
typedef long long ll;
typedef unsigned long long llu;
const int maxn = 100000 + 10;
const int inf = 0x3f3f3f3f;
const double pi = acos(-1.0);
const double eps = 1e-8;
using namespace std;
 
int g[2];
char s[100];
int vis[maxn];
int ans[maxn];
int m;
bool dfs(int pan,int pos,int last){
    if (pos > m){
        return true;
    }
    int t = last;
    for (int i = 1; i <= 10; ++i){
        if (!vis[i])continue;
        if (g[pan] + i > g[pan^1] && i != last){
            last = i;
            g[pan] += i;
            if (dfs(pan^1,pos+1,last)){
                ans[pos] = i;
                return true;
            }
            g[pan]-=i;
            last = t;
        }
    }
//    if (pos == m-1)return true;
    return false;
}
int main(){
    while(scanf("%s",s) == 1){
 
        memset(g,0,sizeof g);
        memset(vis,0,sizeof vis);
        scanf("%d",&m);
        int len = 10;
        int cnt = 0;
        for (int i =0 ; i < len; ++i){
            if (s[i] == '1')vis[i+1] = 1;
        }
        if (!dfs(0,1,-1))printf("NO\n");
        else {
            printf("YES\n");
            int len = m;
            for (int i = 1; i <= len; ++i){
                if (i> 1)printf(" ");
                printf("%d",ans[i]);
            }
            printf("\n");
 
        }
 
    }
    return 0;
}
 
