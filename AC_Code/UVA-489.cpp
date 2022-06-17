#include <iostream>
#include <set>
using namespace std;
int main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int n;
    string ans,guess;
    while(cin>>n && n!=-1){
        cin>>ans>>guess;
        set<char>tmp;
        set<char>check;
        for(int i=0;i<ans.size();i++) tmp.insert(ans[i]);
        int cnt=0;
        int cur=0;
        for(int i=0;i<guess.size();i++){
            if(cnt==7||check.size()==tmp.size())break;
            if(tmp.find(guess[i])!=tmp.end()) check.insert(guess[i]);
            else cnt++;
        }
        cout<<"Round "<<n<<'\n';
        if(cnt==7)cout<<"You lose."<<'\n';
        else if(tmp.size()==check.size())cout<<"You win."<<'\n';
        else cout<<"You chickened out."<<'\n';
    }
    return 0;
}
