#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>
#include <cassert>
#include <set>
#include <deque>
#include <map>
typedef long long ll;
using namespace std;
string remove (string s) {
    string str = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '|') {
            str += s[i];
        }
    }
    return str;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> grid;
    for (int i = 0; i < 13; i++) {
        string s;
        cin >> s;
        if (s[0] != '+') {
            grid.push_back(remove(s));
        }
    }
    for (int i = 0; i < grid.size(); i++) {
        set<char> mySet;
        for (int j = 0; j < grid.size(); j++) {
            if (grid[i][j] == '.') {
                continue;
            }
            if (mySet.count(grid[i][j])) {
                cout << "GRESKA";
                exit(0);
            }
            mySet.insert(grid[i][j]);
        }
        mySet.clear();
        for (int j = 0; j < grid.size(); j++) {
            if (grid[j][i] == '.') {
                continue;
            }
            if (mySet.count(grid[j][i])) {
                cout << "GRESKA";
                exit(0);
            }
            mySet.insert(grid[j][i]);
        }
    }
    for (int i = 0; i < grid.size(); i += 3) {
        for (int j = 0; j < grid.size(); j += 3) {
            set<char> mySet;
            for (int dx = 0; dx <= 2; dx++) {
                for (int dy = 0; dy <= 2; dy++) {
                    if (grid[i + dx][j + dy] == '.') {
                        continue;
                    }
                    if (mySet.count(grid[i + dx][j + dy])) {
                        cout << "GRESKA";
                        exit(0);
                    }
                    mySet.insert(grid[i + dx][j + dy]);
                }
            }
        }
    }
    cout << "OK";
}
