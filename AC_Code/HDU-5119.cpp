#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1 << 20;

ll dp[10][maxn];
ll k[50];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for(int _ = 1; _ <= T; ++_) {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; ++i) {
            cin >> k[i];
        }
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < maxn; ++j) {
                dp[i & 1][j] = dp[(i - 1) & 1][j] + dp[(i - 1) & 1][j ^ k[i]];
            }
        }
        ll ans = 0;
        for(int i = m; i < maxn; ++i) {
            ans += dp[n & 1][i];
        }
        cout << "Case #" << _ << ": " << ans << endl;
    }
    return 0;
}
