struct trie{
    trie *nxt[2];  // 差別
    int cnt;    //紀錄有多少個數字以此節點結尾
    int sz;     //有多少數字的前綴包括此節點
    trie():cnt(0),sz(0){
        memset(nxt,0,sizeof(nxt));
    }
};
 
//創建新的字典樹
trie *root = new trie();

void insert(int x){
    trie *now = root;  // 每次從根結點出發
    for(int i=30;i>=0;i--)
        now->sz++;
        if(now->nxt[x>>i&1] == NULL){
            now->nxt[x>>i&1] = new trie();
        }
        now = now->nxt[x>>i&1];  //走到下一個字母
    }
    now->cnt++;
    now->sz++;
}
ll query(int x)//依題目要求更改
{
    ll ans = 0;
    trie *now = root;
    for (int i = 30; i >= 0; i--)
    {
        //bool j = x & (1 << i) ? 0 : 1;
        if (now->next[j] != NULL && now->next[j]->cnt > 0)
        {
            ans += (1 << i);
            now = now->next[j];
        }
        else
            now = now->next[j ^ 1];
    }
    return ans;
}
