#include <bits/stdc++.h>
using namespace std;

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define IO_FAST \
    cin.tie(0); \
    ios::sync_with_stdio(0)

#define EPS 1e-3
#define cl(x) ((x << 1))
#define cr(x) ((x << 1) + 1)
#define lowbit(x) (x & -x)
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define endl '\n'
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define pi acos(-1)
#define all(a) (a).begin(), (a).end()
#define rall(a) a.rbegin(), a.rend()
#define sz(x) (int)(x).size()
#define pq priority_queue // default priority higher first
#define ff first
#define ss second
#define FOR(l, r) for (int i = (int)l; i <= (int)r; i++)
#define FORR(l, r) for (int i = (int)r; i >= (int)l; i--)
#define ms(a, b, c) memset(a, b, c)
#define br cout << "\n"
#define EACH(x, a) for (auto &x : a)

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template <typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*
    插入t.insert();
    删除t.erase();
    求k在树中是第几大:t.order_of_key();
    求树中的第k大:t.find_by_order();
    前驱:t.lower_bound();
    后继t.upper_bound();
    a.join(b)b并入a 前提是两棵树的key的取值范围不相交
    a.split(v,b)key小于等于v的元素属于a，其余的属于b
    T.lower_bound   (x)   >=x的min的迭代器
    T.upper_bound((x)  >x的min的迭代器
    T.find_by_order(k) 有k个数比它小的数
*/
const int mod = 1e9 + 9;
const int MXN = 2e5 + 5;
int n, m, x, y;
// comparator
// struct cmp
// {
//     bool operator()(pii const &a, pii const &b) const
//     {
//         return a.first == b.first ? a.second < b.second : a.first > b.first;
//     }
// };

void solve()
{

    return;
}
int main()
{

    // freopen("input.txt","r",stdin);    // 讀 file.in 檔
    // freopen("output.txt","w",stdout);  // 寫入 file.out 檔
    IO_FAST;
    int t = 1;
    // cin >> t;
    FOR(1, t)
    {
        solve();
    }

    return 0;
}
