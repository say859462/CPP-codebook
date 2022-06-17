#include <iostream>
#include <algorithm>
using namespace std;
int main(){

    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);

    string top,down;

    while(cin>>down>>top){

        int len1=down.size();
        int len2=top.size();
        int ans=len1+len2;

        //對上塊進行右平移，每移動一次就做一次判斷，若厚度相加>3代表不合法(兩個齒重疊)，反之則計算最小長度。

        for(int i=0;i<len1;i++){//當前平移位置
            int k=i;//與下塊做計算的起始位置
            bool flag=0;
            for(int j=0;j<len2;j++){
                if( (down[k]-'0'+top[j]-'0') <= 3 ){
                    k++;
                    if(k==len1){//代表上塊長度較長，至少需要 i+len2的長度
                        ans=min(ans,i+len2);
                        flag=1;
                        break;
                    }
                    else if(j==len2-1){
                        ans=min(ans,len1);
                        flag=1;
                        break;
                    }
                }
                else break;
            }
            if(flag)break;
        }
        //下塊左平移
        for(int i=0;i<len2;i++){
            int k=i;
            bool flag=0;
            for(int j=0;j<len1;j++){
                if( (down[j]-'0'+top[k]-'0') <=3){
                    k++;
                    if(k==len2){
                        ans=min(ans,i+len1);
                        flag=1;
                        break;
                    }
                    else if(j==len1-1){
                        ans=min(ans,len2);
                        flag=1;
                        break;
                    }
                }
                else break;
            }
            if(flag)break;
        }

        cout<<ans<<'\n';
    }

    return 0;

}
