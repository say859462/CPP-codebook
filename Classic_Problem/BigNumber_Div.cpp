int t1[200005]={0};//紀錄字串數
int t2[200005]={0};//紀錄商
string divide(string a,int b){
    memset(t1,0,sizeof(t1));
    memset(t2,0,sizeof(t2));
    string re="";
    for(int i=0;i<SZ(a);i++)t1[i+1]=a[i]-'0';
    int remain=0;
    for(int i=1;i<=SZ(a);i++){
        t2[i]=(remain*10+t1[i])/b;
        remain=(remain*10+t1[i])%b;
    }
    int lc=1;
    while(t2[lc]==0 && lc<SZ(a))++lc;//刪除前導0
    for(int i=lc;i<=SZ(a);i++)re.PB(t2[i]+'0');
    return re;
}
