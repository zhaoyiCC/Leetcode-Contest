//
//  main.cpp
//  D
//
//  Created by ohazyi on 2017/10/15.
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
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
#define rep2(i,a,b) for (int i = (a); i >= (b); --i)

using namespace std;

const int N = 300100;
const int M = 27;
vector<int> v[N];
int ans, n , m, x, a[N], b[N];
bool vis[N];
char c[N];
int f[N][M];
int color[N];
void dfs(int k){
    if (vis[k])
        return ;
    int h;
    color[k] = -1;
    for (auto i: v[k]){
        if (color[i] == -1){
            cout << -1 << endl;
            exit(0);
        }
        if (!vis[i]){
            dfs(i);
        }
    
        rep (j,0,25){
//            if (c[i]-'a' == j)
//                h = 1;
//            else
//                h = 0;
            if (f[i][j] >= f[k][j])
                f[k][j] = f[i][j];
        }
    }
    f[k][c[k]-'a']++;
    vis[k] = true;
    color[k] = 1;
}
int main() {
    cin >> n >> m;
    rep (i,1,n){
        cin >> c[i];
    }
    rep (i,1,m){
        cin >> a[i] >> b[i];
        v[a[i]].push_back(b[i]);
    }
    memset(vis,false,sizeof(vis));
    memset(color,0,sizeof(color));
    rep (i,1,n){
        if (!vis[i]){
            dfs(i);
        }
    }
    
    ans = 0;
    rep (i,1,n){
        rep (j,0,25){
            if (f[i][j] > ans)
                ans = f[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}
