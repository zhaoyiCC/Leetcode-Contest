//
//  main.cpp
//  D
//
//  Created by ohazyi on 2017/10/2.
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

using namespace std;

class Solution {
public:
    #define rep(i,a,b) for (int i = (a); i <= (b); ++i)
    typedef long long ll;
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0)
            return 0;
        int ans = 0;
        int n = nums.size();
        int now = 0;
        ll val = 1;
        rep (i,0,n-1){
            now = max(now, i);
            while (now <= n-1 && val*nums[now] < (ll)k){
                val *= (ll)nums[now];
                now++;
            }
            ans += max(now-i, 0);
            if (i < now)
                val /= (ll)nums[i];
        }
        return ans;
    }
};


const int N = 50010;
int ans, n , k, a[N];

int main() {
    //freopen("1.txt", "r", stdin);
    vector<int> v;
    cin >> n >> k;
    rep (i, 1, n){
        scanf("%d",&a[i]);
        v.push_back(a[i]);
    }

    ans = 0;
    Solution s;
    ans = s.numSubarrayProductLessThanK(v, k);
    cout << ans << endl;
    return 0;
}
