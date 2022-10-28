void sub(){
    if(SZ(a)<SZ(b) || (a<b&&SZ(a)==SZ(b))) {
        swap(a,b);
        neg=1;
    }
    for(int i=0;i<SZ(a);i++){
        num1[i]=a[SZ(a)-1-i]-'0';
    }
    for(int i=0;i<SZ(b);i++){
        num2[i]=b[SZ(b)-i-1]-'0';
    }
    len=SZ(a);
    for(int i=0;i<len;i++){
        if(num1[i]-num2[i]<0){
            num1[i+1]--;
            num1[i]+=10;
        }
        ans[i]=num1[i]-num2[i];
    }
    while(len>1 && ans[len-1]==0)len--;//去除前導0
    if(neg && !(len==1&&ans[0]==0))cout<< '-';
    for(int i=len-1;i>=0;i--)cout<<ans[i];
    cout<<endl;
    return ;
}
