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
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    int grid[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }
    auto remove_front = [&] (deque<pair<int,int>>&d, int ind) {
        if (d.front().first == ind) {
            d.pop_front();
        }
    };
    auto add_back = [&] (deque<pair<int,int>>&d, int ind, int x) {
        while (!d.empty() && d.back().second < x) {
            d.pop_back();
        }
        d.push_back(make_pair(ind, x));
    };
    auto get_max = [&] (deque<pair<int,int>>&d) {
        return d.front().second;
    };
    int r, s;
    cin >> r >> s;
    int result[N][M];
    for (int i = 0; i < N; i++) {
        deque<pair<int,int>> d;
        for (int j = 0; j + s - 1 < M; j++) {
            if (j == 0) {
                for (int x = j; x <= j + s - 1; x++) {
                    add_back(d, x, grid[i][x]);
                }
            } else {
                remove_front(d, j - 1);
                add_back(d, j + s - 1, grid[i][j + s - 1]);
            }
            result[i][j] = get_max(d);
        }
    }
    int res[N][M];
    for (int j = 0; j + s - 1 < M; j++) {
        deque<pair<int,int>> d;
        for (int i = 0; i + r - 1 < N; i++) {
            if (i == 0) {
                for (int x = i; x <= i + r - 1; x++) {
                    add_back(d, x, result[x][j]);
                }
                res[i][j] = get_max(d);
            } else {
                remove_front(d, i - 1);
                add_back(d, i + r - 1, result[i + r - 1][j]);
                res[i][j] = get_max(d);
            }
        }
    }
    for (int i = 0; i + r - 1 < N; i++) {
        for (int j = 0; j + s - 1 < M; j++) {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
}
