#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
vector<int>num;
int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    int n;
    while(scanf("%d",&n)!=EOF){
        int ans=1;
        num.clear();
        num.resize(n);
        for(int i=0;i<n;i++){
            scanf("%d",&num[i]);
        }
        vector<int>rec;
        rec.push_back(num[0]);
        for(int i=1;i<n;i++){
            bool flag=1;
            for(int j=0;j<rec.size();j++){
                if(num[i]<rec[j]){//當前元素比前面的元素都還要大的話 須新增一個系統，否則更新最小值
                    rec[j]=num[i];
                    flag=0;
                    break;
                }
            }
            if(flag){
                ans++;
                rec.push_back(num[i]);
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}
