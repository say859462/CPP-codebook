const ll P = 75577;
const ll MOD = 998244353;
string s;
ll Hash[MXN];    //Hash[i] 為字串 [0,i] 的 hash值
Hash[0]=s[0];
ll _p[MXN];
void build(const string& s){
    for(int i=i; i<s.size(); i++){
        Hash[i]=(Hash[i-1]*p%mod+s[i])%mod;
    }
}
bool check(int l,int r){
  ll rec=Hash[r]-Hash[l-1]*_p[r-l+1]%mod;
  if(rec<0)rec+=mod;
  return rec;
}
int main(){
  _p[0]=1;
  for(int i=1;i<MXN;i++){
    _p[i]=_p[i-1]*p%mod;
  }
  
}
