#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#define ll long long
using namespace std;
double mm[15][35]={0};//mantissa
ll ee[15][35]={0};//exponent

//M*2^E=A*10^B
//   B=logM+Elog2(integer)    A=10^(logM+Elog2-B) (float-point)
void init(){
    //0.111111*2^(11111)2  0.(M)*2^(E)
    for(int M=0;M<=9;M++){
        for(int E=1;E<=30;E++){
            ll e=pow(2,E)-1;//當指數為E時，對應到的指數二進位形式
            double m=1-pow(2,-(M+1));//same  above
            ll b=log10(m)+e*log10(2);
            double a=pow(10,log10(m)+e*log10(2)-b);

            ee[M][E]=b;//轉換為十進位的模樣
            mm[M][E]=a;

        }
    }

    return ;
}

int main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    string num;
    init();
    while(cin>>num){
        if(num=="0e0")break;
        string Float,exp;
        double FF,Ex;
        bool flag=0;

        for(int i=0;i<num.size();i++){//擷取福點數 以及 指數
            if(num[i]=='e'){
                for(int j=i+1;j<num.size();j++){
                    exp+=num[j];
                }
                flag=1;
            }
            Float+=num[i];
            if(flag)break;
        }
        bool ff=0;

        FF=stof(Float);Ex=stoi(exp);//字串轉換

        for(int i=0;i<=9;i++){//窮舉M E所有可能
            for(int j=1;j<=30;j++){
                if(ee[i][j]==Ex&&abs(mm[i][j]-FF)<1e-4){
                    cout<<i<<" "<<j<<'\n';
                    ff=1;
                    break;
                }
            }
            if(ff)break;
        }
    }
    return 0;
}
