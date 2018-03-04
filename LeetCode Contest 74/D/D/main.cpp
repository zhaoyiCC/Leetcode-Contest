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
#define rep2(i,a,b) for (int i = (a); i >= (b); --i)
class Solution {
public:
    int countZero(int x){
        int res = 0;
        while (x != 0){
            res += x/5;
            x/=5;
        }
        return res;
    }
    int findRange(int K){
        int ans=0, l, r, mid;
        if (K < 0)
            return 0;
        l = 0;
        r = 1e9;
        while (l <= r){
            mid = l + (r-l)/2;
//            cout << mid << " " << countZero(mid) << endl;
            if (countZero(mid) <= K){
                ans = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return ans+1;
    }
    int preimageSizeFZF(int K) {
        return findRange(K)-findRange(K-1);
    }
};

int main(){
    vector<ll> v;
    
    Solution s;
    cout << s.preimageSizeFZF(1000000);
    return 0;
}
