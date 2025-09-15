#include "bits/stdc++.h"
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define F first
#define S second
#define endl '\n'

const int MOD = 1e9;
const int INF = 1e9;
const ll LINF = 1e18;

double dis(pdd a, pdd b)
{
    return sqrt((a.F - b.F) * (a.F - b.F) + (a.S - b.S) * (a.S - b.S));
}

bool cmpX(pdd a, pdd b)
{
    if (a.F == b.F)
        return a.S < b.S;
    return a.F < b.F;
}

bool cmpY(pdd a, pdd b)
{
    if (a.S == b.S)
        return a.F < b.F;
    return a.S < b.S;
}

double div(vector<pdd> &ptsX, vector<pdd> &ptsY)
{
    int n = ptsX.size();
    // points less than 3 , brute force calculate the cloeset pair
    if (n <= 3)
    {
        double ans = INF;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                ans = min(ans, dis(ptsX[i], ptsX[j]));
            }
        }

        return ans;
    }

    int mid = n >> 1;
    pdd midPoint = ptsX[mid];
    vector<pdd> leftX(ptsX.begin(), ptsX.begin() + mid);
    vector<pdd> rightX(ptsX.begin() + mid, ptsX.end());
    vector<pdd> leftY, rightY;


    // partition the points in Y sorted array
    for (auto pt : ptsY)
    {
        if (pt.F < midPoint.F || (pt.F == midPoint.F && pt.S < midPoint.S))
            leftY.pb(pt);
        else
            rightY.pb(pt);
    }

    double d1 = div(leftX, leftY);
    double d2 = div(rightX, rightY);
    double d = min(d1, d2);

    // merge step

    vector<pdd> strip;
    for (auto pt : ptsY)
    {
        if (abs(pt.F - midPoint.F) < d)
            strip.pb(pt);
    }

    for (int i = 0; i < strip.size(); i++)
    {
        for (int j = i + 1; j < min((int)strip.size(), i + 7); j++)
        {
            d = min(d, dis(strip[i], strip[j]));
        }
    }

    return d;
}
double solve()
{

    int n;
    vector<pdd> ptsX;
    vector<pdd> ptsY;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        double x, y;
        cin >> x >> y;
        ptsX.pb({x, y});
        ptsY.pb({x, y});
    }

    sort(all(ptsX), cmpX);
    sort(all(ptsY), cmpY);
    return div(ptsX, ptsY);
}
int main()
{
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
        cout << fixed << setprecision(6) << solve() << endl;

    return 0;
}
