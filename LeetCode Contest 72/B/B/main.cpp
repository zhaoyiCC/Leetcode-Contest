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

#define rep2(i,a,b) for (int i = (a); i >= (b); --i)

using namespace std;

const int N = 10010;
int ans, n , m, k, a[N];
string str;

class Solution {
public:
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
#define rep2(i,a,b) for (int i = (a); i >= (b); --i)
    int n, vis[1010];
    bool dfs(int k, int color, vector<vector<int>>& graph){
        vis[k] = color;
        for (auto i: graph[k]){
            if (vis[i] == color){
                return false;
            }
            if (vis[i] == -1){
                if (!dfs(i, 1-color, graph))
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        memset(vis,-1,sizeof(vis));
        n = (int)graph.size();
        rep (i,0,n-1){
            if (vis[i] == -1){
                if (!dfs(i, 1, graph))
                    return false;
            }
        }
        return true;
    }
};

int main(){
    vector<int> v;
    cin >> n >> m;
    rep (i,1,n){
        cin >> a[i];
        v.push_back(a[i]);
    }
    Solution s;
    
    return 0;
}
