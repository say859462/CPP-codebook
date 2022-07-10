#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
     vector<string>s;
     int n;
     while(cin>>n){
        s.clear();
        s.resize(n);
        int mxlen=0;
        for(int i=0;i<n;i++){
            cin>>s[i];
            mxlen=max(mxlen,(int)s[i].size());
        }
        sort(s.begin(),s.end());
        for(int i=0;i<60;i++)cout<<"-";cout<<'\n';
        int cols=(60-mxlen)/(mxlen+2)+1;//計算列數 每行長度最多60 除了最右側字串長度為mxlen 其餘為mxlen+2 故總長度扣除掉最右側/其餘字串至少需要的長度再加上最右側字串(+1) 可以得到每行能有幾列字串
        int rows=(s.size()+(cols-1))/cols;//取ceiling
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                int idx=j*rows+i;//優先列印列
                //考慮是否列印最後一列字串 且 idx必須在數量內
                if(idx<s.size())
                    cout<<std::left<<(j==cols-1?setw(mxlen):setw(mxlen+2))<<s[idx];
            }
            cout<<'\n';
        }
     }
     return 0;
}
