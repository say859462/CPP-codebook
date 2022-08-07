#include <iostream>
#include <vector>
using namespace std;
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    string str1,str2;
    while(cin>>str1>>str2){
        vector< vector<int> >dp(str1.size()+1,vector<int>(str2.size()+1,0));//dp[i][j] 為str1在第i個字元前和str2在第j個字元前的最長共同子序列
        for(int i=0;i<str1.size();i++){
            for(int j=0;j<str2.size();j++){
                if(str1[i]==str2[j]){
                    dp[i+1][j+1]=dp[i][j]+1;
                }
                else{
                    dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        cout<<dp[str1.size()][str2.size()]<<'\n';
    }
    return 0;
}
