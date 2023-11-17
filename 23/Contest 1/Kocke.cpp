#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>
#include <cassert>
#include <set>
#include <climits>
#include <deque>
#include <map>
#include <queue>

const int MOD = 1e9 + 7;
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int64_t pref[2][2][n + 2][2]; //cut the size
    for (int i = 0; i < 2; i++) {
        for (int k = 0; k < 2; k++) {
            for (int l = 0; l <= n + 1; l++) {
                pref[i][k][l][0] = 0;
                pref[i][k][l][1] = 0;
            }
        }
    }
    int64_t ans = 0;
    for (int sz = 2; sz <= m; sz++) {
        int s = sz % 2;
        for (int moves = 0; moves <= n + 1; moves++) {
            for (int pos = 0; pos <= 1; pos++) {
                pref[s][pos][moves][0] = 0;
                pref[s][pos][moves][1] = 0;
            }
        }
        for (int moves = sz; moves <= n; moves++) {
            for (int pos = 0; pos <= 1; pos++) {
                if (sz == 2) {
                    if (moves == 2) {
                        pref[s][pos][moves + 1][moves % 2] = 1;
                        ans += (m - sz + 1);
                    } else {
                        pref[s][pos][moves + 1][0] = 1, pref[s][pos][moves + 1][1] = 0;
                    }
                    continue;
                }
                int64_t res = (pref[!s][1 - pos][moves - sz + 2][(moves + sz + 1) % 2] + pref[!s][pos][moves][(moves + 1) % 2]) % MOD;
                ans += (res * (m - sz + 1)) % MOD;
                ans %= MOD;
                pref[s][pos][moves + 1][moves % 2] = (pref[s][pos][moves][moves % 2] + res) % MOD;
                pref[s][pos][moves + 1][1 - moves % 2] = pref[s][pos][moves][1 - moves % 2];
            }
        }
    }
    cout << ans;
}
