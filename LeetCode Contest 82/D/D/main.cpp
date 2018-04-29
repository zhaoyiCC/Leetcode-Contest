//
//  main.cpp
//  A
//
//  Created by ohazyi on 2017/10/1.
//  Copyright © 2017年 ohazyi. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>

typedef long long ll;

#define rep2(i,a,b) for (ll i = (a); i >= (b); --i)

using namespace std;

const ll N = 10010;
ll ans, n , m, k, a[N];
string str;

typedef long long ll;
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
class Solution {
    public:
    int n, m;
    vector<vector<int>> a;
    bool vis[55][55];
    int f[55][55];
    int xx[4]={1,-1,0,0};
    int yy[4]={0,0,1,-1};
    bool mycheck(int x,int y){
        return (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y]);
    }
    int dfs(int x, int y){
        int ans = 1;
        vis[x][y] = true;
        rep (i,0,3){
            int nx = x+xx[i];
            int ny = y+yy[i];
            if (mycheck(nx, ny) && a[nx][ny]){
                ans += dfs(nx, ny);
            }
        }
        return ans;
    }
    int largestIsland(vector<vector<int>>& aa) {
        a = aa;
        n = (int)a.size();
        m = (int)a[0].size();
        memset(vis, false, sizeof(vis));
        int ans = 0;
        rep (i,0,n-1)
        rep (j,0,m-1)
        if (!vis[i][j] && a[i][j] ==1){
            ans = max(dfs(i, j), ans);
        }
        rep (i,0,n-1){
            rep (j,0,m-1){
                if (a[i][j] == 0){
                    a[i][j] = 1;
                    memset(vis, false, sizeof(vis));
                    rep (i,0,n-1)
                    rep (j,0,m-1)
                    if (!vis[i][j]&& a[i][j] ==1){
                        ans = max(dfs(i, j), ans);
                    }
                    a[i][j] = 0;
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int> > v;
    vector<int> v1 = {0,0};
    vector<int> v2 = {0,0};
    v = {v1,v2};
    Solution s;
    cout << s.largestIsland(v) << endl;
    return 0;
}
