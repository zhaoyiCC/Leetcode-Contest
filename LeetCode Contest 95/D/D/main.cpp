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
#define rep(i,a,b) for (ll i = (a); i <= (b); ++i)
ll f[102][10010], g[102][10010];
class Solution {
public:
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        ll n = (ll)group.size();
        if (n==0)
            return 0;
        ll res = 0;
        ll tot = 0;
        for (auto i: profit){
            tot+=i;
        }
        cout << tot << endl;
        memset(g,0,sizeof(g));
        memset(f,0,sizeof(f));
        f[0][0] = g[0][0] = 1;
        rep (i,1,n){
            rep (j,0,G){
                rep (k,0,tot){
                    if (j < group[i-1] || k < profit[i-1]){
                    }else{
                        f[j][k] += g[j-group[i-1]][k-profit[i-1]];
                    }
                }
            }
            memcpy(g, f, sizeof(f));
        }
        rep (j,0,G){
            rep (k,P,tot)
            res += f[j][k];
        }
        int mod = 1e9+7;
        return res%mod;
    }
};
/*
class Solution {
public:
    int f[110][110][110];
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        int n = (int)group.size();
        if (n==0)
            return 0;
        int ans = 0, res = 0;
        int tot = 0;
        for (auto i: profit){
            tot+=i;
        }
        cout << tot << endl;
        memset(f,0,sizeof(f));
        f[0][0][0] = 1;
        rep (i,0,n){
            f[i][0][0] = 1;
        }
        rep (i,1,n){
            rep (j,0,G){
                rep (k,0,tot){
                    f[i][j][k] = f[i-1][j][k];
                    if (j < group[i-1] || k < profit[i-1]){
                    }else{
                        f[i][j][k] += f[i-1][j-group[i-1]][k-profit[i-1]];
                    }
                }
            }
        }
        rep (j,0,G){
            rep (k,P,tot)
            res += f[n][j][k];
        }
        return res;
    }
};
*/
int main(){
    vector<int> g = {2,3,5};
    vector<int> p = {6,7,8};
    Solution s;
    cout << s.profitableSchemes(10,5, g, p) << endl;
    return 0;
}
