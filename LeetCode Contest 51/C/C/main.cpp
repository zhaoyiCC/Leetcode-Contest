//
//  main.cpp
//  C
//
//  Created by ohazyi on 2017/9/24.
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

const int N = 10010;
int ans, n , m, a[N];
class Solution {
public:
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
#define rep2(i,a,b) for (int i = (a); i >= (b); --i)

    bool vis[2010], b[2010];
    vector<int> v[2010], e[2010];
    int n, tot;
    Solution(){
        memset(vis,false,sizeof(vis));
    }
    void dfs(int spec,int k){
        b[k] = true;
        tot++;
        int p,q;
        rep (i,0,(int)v[k].size()-1){
            p = v[k][i];
            q = e[k][i];
            if (q != spec && !b[p]){
                dfs(spec, p);
            }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n = edges.size();
        int x,y,m;
        rep (i,0,(int)edges.size()-1){
            x = edges[i][0];
            y = edges[i][1];
            v[x].push_back(y);
            e[x].push_back(i);
            v[y].push_back(x);
            e[y].push_back(i);
            if (v[x].size()>=2){
                m = x;
            }
        }
        rep2 (i,(int)edges.size()-1,0){
            memset(b,false,sizeof(b));
            tot = 0;
            dfs(i,m);
            if(tot==n){
                return edges[i];
            }
        }
        return edges[0];
    }
};

int main() {

    vector<vector<int>> eee;
    cin >> n;
    int x,y;
    rep (i, 1, n){
        scanf("%d%d",&x,&y);
        eee.push_back({x,y});
    }

    vector<int> ans;
    Solution s;
    ans =s.findRedundantConnection(eee);
    cout << ans[0] <<  " "<<ans[1]<< endl;

    return 0;
}
