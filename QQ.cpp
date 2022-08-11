#include <bits/stdc++.h>
using namespace std;
const int mx = 5e4 + 5;

struct Treap
{
    Treap *l, *r;
    int val, sz, pri;
    Treap()
    {
        pri = rand(); //維持Treap平衡
        l = r = nullptr;
    };
    Treap(int x)
    {
        val = x;
        sz = 1;
        pri = rand();
        l = r = nullptr;
    }
};
Treap addr[800000];
int cal = 0;
Treap *newnode()
{
    addr[cal].l = addr[cal].r = nullptr;
    return &addr[cal++];
}
int lowbit(int x) { return x & (-x); }
int Size(Treap *x)
{
    return x ? x->sz : 0;
}

void pull(Treap *x)
{
    x->sz = Size(x->l) + Size(x->r) + 1;
    return;
}

Treap *merge(Treap *a, Treap *b)
{ // Treap a所有key需均<=Treap b
    if (!a || !b)
        return a ? a : b;
    if (a->pri > b->pri)
    {
        a->r = merge(a->r, b);
        pull(a);
        return a;
    }
    else
    {
        b->l = merge(a, b->l);
        pull(b);
        return b;
    }
}
void split(Treap *x, int k, Treap *&a, Treap *&b)
{ //將Treap x依照k值大小 <=k的子樹分割給a >k則給b
    if (!x)
    {
        a = b = nullptr;
    }
    else if (x->val <= k)
    {
        a = x;
        split(x->r, k, a->r, b);
        pull(a);
    }
    else
    {
        b = x;
        split(x->l, k, a, b->l);
        pull(b);
    }
}
Treap *insert(Treap *root, int key)
{
    Treap *x = newnode();
    x->val = key;
    Treap *l, *r;
    split(root, key, l, r);
    return merge(merge(l, x), r);
}
Treap *erase(Treap *root, int key)
{
    Treap *l, *mid, *r;
    split(root, key, l, r);    //<=key給l,>key給r
    split(l, key - 1, l, mid); //<key給l ==key給mid(l只儲存<=key的值)
    return merge(merge(merge(l,mid->l),mid->r), r);//只需移除一個元素 故移除端點元素 其餘子傑點去做merge後回傳
}
struct query
{
    int l, r, k;
};
vector<query> Q;
Treap *bit[mx];
vector<int> num;
int rec[mx] = {0};
void update(int pos, int val, int mode)
{
    if (mode)
    {
        while (pos < mx)
        {
            bit[pos] = insert(bit[pos], val);
            pos += lowbit(pos);
        }
    }
    else
    {
        while (pos < mx)
        {
            bit[pos] = erase(bit[pos], val);
            pos += lowbit(pos);
        }
    }
    return;
}
int cut(Treap *root, int ql, int qr)
{
    Treap *l, *mid, *r;
    split(root, qr, l, r);    // l=[1,qr] r=[qr+1,n]
    split(l, ql - 1, mid, l); // l=[ql,qr] mid=q[1~ql-1]
    int ans = Size(l);
    root = merge(merge(mid, l), r);
    return ans;
}
int check(int pos, int l, int r)
{
    int rec = 0;
    while (pos)
    {
        rec += cut(bit[pos], l, r);
        pos -= lowbit(pos);
    }
    return rec;
}
int id(int val)
{
    return lower_bound(num.begin(), num.end(), val) - num.begin() + 1;
}
int query(int ql, int qr, int k)
{
    int l = 1, r = mx;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid, ql, qr) < k)
        {
            l = mid + 1;
        }
        else
            r = mid;
    }
    return r;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t, n, q, x;
    char cmd;
    cin >> t;
    while (t--)
    {

        for (int i = 0; i < mx; i++)
        {
            bit[i] = nullptr;
        }
        cal = 0;
        num.clear();
        Q.clear();
        cin >> n >> q;
        num.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> num[i];
            rec[i] = num[i];
        }
        while (q--)
        {
            cin >> cmd;
            int l, r, k, pos;
            if (cmd == 'Q')
            {
                cin >> l >> r >> k;
                Q.push_back({l, r, k});
            }
            else
            {
                cin >> pos >> k;
                num.push_back(k);
                Q.push_back({0, pos, k});
            }
        }
        sort(num.begin(), num.end());
        num.erase(unique(num.begin(), num.end()), num.end());
        for (int i = 0; i < n; i++)
        {
            rec[i] = id(rec[i]);
            update(rec[i], i + 1, 1);
        }
        for (int i = 0; i < Q.size(); i++)
        {
            if (Q[i].l == 0)
            { //更換操作
                int pos = Q[i].r;
                update(rec[pos - 1], pos, 0);
                update(id(Q[i].k), pos, 1);
                rec[pos - 1] = id(Q[i].k);
            }
            else
            {
                cout << num[query(Q[i].l, Q[i].r, Q[i].k) - 1] << '\n';
            }
        }
    }
    return 0;
}
