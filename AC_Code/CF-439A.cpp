#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int t,n,h,d;
    cin>>n>>d;
    int time[105]={0};
    // 5min joke
    int sum=0;
    int total=0;
    for(int i=0;i<n;i++){
        cin>>time[i];
        sum+=time[i];
    }
    if( (sum+10*(n-1))>d){
        cout<<-1<<'\n';
    }
    else{
        cout<< (d-sum)/5<<'\n';
    }
    return 0;
}
