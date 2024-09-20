vector<int> lps(string pat)
{
    
    int n =pat.size();
    vector<int> pi(n);
    int len = 0;
    pi[0] = 0;
    int i =1;
    
    while(i<n){
        if(pat[i] == pat[len]){
            len++;
            pi[i] = len;
            i++;
        }else{
            if(len!=0){
                len = pi[len-1];
            }else{
                pi[i] = 0;
                i++;
            }
        }
    }

    return pi;
}
