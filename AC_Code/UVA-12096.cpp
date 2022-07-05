#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <stack>
using namespace std;
map< set<int> , int >ID;//紀錄集合所對應的編號
vector<set<int>> s;//編號所對應的集合
int getid(set<int>x){
    if(ID.count(x))
        return ID[x];
    else
        s.push_back(x);//加入集合
    ID[x]=s.size()-1;
    return ID[x];
}
int main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int t,n;
    string cmd;
    cin>>t;
    while(t--){
        ID.clear();s.clear();
        cin>>n;
        stack<int>stk;//當前集合編號
        while(n--){
            cin>>cmd;
            
            if(cmd=="PUSH"){
                set<int>ss;//新增集合並給予編號
                int id=getid(ss);
                stk.push(id);
            }
            else if(cmd=="DUP"){
                stk.push(stk.top());//複製最頂端的集合
            }
            else{
                set<int>first=s[stk.top()];
                stk.pop();
                set<int>second=s[stk.top()];
                stk.pop();
                set<int>result;
                if(cmd=="UNION"){
                    result=second;
                    set<int>::iterator i=first.begin();
                    for(;i!=first.end();i++){
                        result.insert(*i);
                    }
                }
                if(cmd=="INTERSECT"){
                    set<int>::iterator ptr1=first.begin();
                    for(;ptr1!=first.end();ptr1++){
                        set<int>::iterator ptr2=second.begin();
                        for(;ptr2!=second.end();ptr2++){
                            if(*ptr1==*ptr2){
                                result.insert(*ptr1);
                            }
                        }
                    }
                }
                if(cmd=="ADD"){
                    result=second;
                    result.insert(getid(first));
                }
                stk.push(getid(result));
            }
            cout<<s[stk.top()].size()<<'\n';
        }
        cout<<"***"<<'\n';
    }   
    return 0;
}
