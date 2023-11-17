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
typedef long long ll;
using namespace std;
map<char,int> colors;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    colors['P'] = 0;
    colors['C'] = 1;
    colors['Z'] = 2;
    colors['N'] = 3;
    int myMap[n][m][3][3];
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m - 1; j++) {
            myMap[i][j][1][2] = colors[s[j]];
            myMap[i][j + 1][1][0] = colors[s[j]];
        }
    }
    for (int i = 0; i < n - 1; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            myMap[i][j][2][1] = colors[s[j]];
            myMap[i + 1][j][0][1] = colors[s[j]];
        }
    }
    int queries;
    cin >> queries;
    while (queries--) {
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        sx--, sy--;
        ex--, ey--;
        int best = 4;
        for (int mask = 1; mask < 15; mask++) {
            queue<pair<int, int>> q;
            bool vis[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    vis[i][j] = false;
                }
            }
            q.push({sx, sy});
            vis[sx][sy] = true;
            while (!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if (abs(dx) + abs(dy) == 1) {
                            int new_x = x + dx;
                            int new_y = y + dy;
                            if (new_x >= 0 and new_x < n and new_y >= 0 and new_y < m) {
                                if (mask & (1 << myMap[x][y][dx + 1][dy + 1])) {
                                    if (!vis[new_x][new_y]) {
                                        q.push({new_x, new_y});
                                        vis[new_x][new_y] = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (vis[ex][ey]) {
                best = min(best, __builtin_popcount(mask));
            }
        }
        cout << best << '\n';
    }
}
