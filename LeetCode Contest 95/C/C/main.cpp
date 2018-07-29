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
#define rep2(i,a,b) for (ll i = (a); i >= (b); --i)
class Solution {
public:
    int gcd(int x, int y){
        if (x < y)
            swap(x, y);
        int t;
        while (y != 0){
            t = y;
            y = x % y;
            x = t;
        }
        return x;
    }
    int gid(int x, int y){
        return (x*y/gcd(x,y));
    }
    int nthMagicalNumber(int N, int A, int B) {
        int mod = (1e9+7);
        if ((A % B)==0){
            return (ll)(B)*(ll)(N)%mod;
        }
        if ((B % A)==0){
            return (ll)(A)*(ll)(N)%mod;
        }
        int h = gid(A, B);
        int seg = h/A+h/B-1;
        int x = (N-1)/seg;
        N %= seg;
        if (N==0)
            N = seg;
        N--;
        priority_queue<int> q;
        vector<int> v;
        int now = A;
        while (now <= h){
            v.push_back(now);
            now += A;
        }
        now = B;
        while (now <= h){
            v.push_back(now);
            now += B;
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        int ans = ((ll)x*(ll)h+(ll)v[N]) % mod;
        return ans;
    }
};

int main(){
    
    Solution s;
    rep (i,263,859){
        cout << i << " " << s.nthMagicalNumber(i, 30, 759) << endl;
    }
    return 0;
}
