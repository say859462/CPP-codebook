class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code here
            vector<int> pi = lps(pat);
            vector<int> ans;
            
            int m = pat.size();
            int n = txt.size();
            
            int i=0,j=0;
            
            while(j<n){
                if(pat[i] == txt[j]){
                    i++,j++;
                }
                
                if(i == m){
                    ans.push_back(j-m+1);
                    i = pi[i-1];
                }
                else if(j<n && pat[i]!=txt[j]){
                    //mismatch after i matches
                    if(i!=0)
                        i = pi[i-1]; //try prefix of pattern
                    else
                        j++; //not match at the beginning of pattern move main str ptr to nrxt
                }
                
            }
            

            
            return ans;
        }
        
        
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
};
