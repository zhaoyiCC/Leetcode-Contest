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

class Solution{
typedef long long ll;
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
public:
    ll mod = 1e9;
    ll numTilings(ll N) {
        ll mod = 1e9+7;
        ll ans = 0;
        ll f[1010];
        f[0] = f[1] = 1;
        rep (i,2,N){
            f[i] = (f[i-1]+f[i-2]) % mod;
            rep (j,0,i-3){
                f[i] = (f[i] + 2*f[j]) % mod;
            }
            cout << i << " " << f[i] << endl;
        }
        return f[N];
    }
};

int main(){
    vector<ll> v;
    
    Solution s;
    
    cout << s.numTilings(5) << endl;
    return 0;
}
