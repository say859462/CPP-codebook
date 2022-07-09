#include <bits/stdc++.h>
using namespace std;
map<int,int>team;
int t;
int cnt=1;
int k,num;
int tmp;
string cmd;
int main(){
    //cin.tie(0);ios::sync_with_stdio(0);
    while(cin>>t){
        if(!t)break;
        team.clear();
        queue<int>q,q2[2000];
        for(int i=0;i<t;i++){
            scanf("%d",&k);
            for(int j=0;j<k;j++){
                scanf("%d",&num);
                team[num]=i;
            }
        }
        printf("Scenario #%d\n",cnt++);
        while(cin>>cmd&&cmd!="STOP"){
            if(cmd=="ENQUEUE"){
                cin>>tmp;
                if(q2[team[tmp]].empty()){
                    q.push(team[tmp]);
                }
                q2[team[tmp]].push(tmp);
            }
            else{
                printf("%d\n",q2[q.front()].front());
                q2[q.front()].pop();
                if(q2[q.front()].empty())q.pop();//若最前隊列已經空了 則除去隊伍之中
            }
        }
        cout<<'\n';
    }
    return 0;
}
