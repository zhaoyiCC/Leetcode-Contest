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

typedef long long ll;

using namespace std;

#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
#define rep2(i,a,b) for (int i = (b); i >= (a); --i)
class Solution {
public:
    int n, fl[20010], fr[20010], sum[20010], l[20010], r[20010];
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        n = nums.size();
        sum[0] = nums[0];
        rep (i,1,n-1){
            sum[i] = sum[i-1] + nums[i];
        }
        int maxtot = sum[k-1];
        int lpos = 0;
        rep (i,k,n-k-1){
            l[i] = lpos;
            fl[i] = maxtot;
            if (sum[i]-sum[i-k]>maxtot){
                maxtot = sum[i] - sum[i-k];
                lpos = i-k+1;
            }
        }
        maxtot = sum[n-1]-sum[n-k-1];
        int rpos = n-k;
        rep2 (i,k,n-2*k){
            r[i] = rpos;
            fr[i] = maxtot;
            if (sum[i+2*k-2] - sum[i+k-2]>maxtot){
                maxtot = sum[i+2*k-2] - sum[i+k-2];
                rpos = i+k-1;
            }
        }
        vector<int> zy;
        int ans = 0;
        rep (i,k,n-k-1){
            if (sum[i+k-1]-sum[i-1] + fl[i]+fr[i]  > ans){
                ans = sum[i+k-1] - sum[i-1]+fl[i]+fr[i];
                zy = {l[i],i,r[i]};
            }
        }
        return zy;
    }
};

const int N = 10010;
int ans, n , k, a[N];


int main() {

    vector<int> v;
    cin >> n >> k;
    rep (i, 1, n){
        scanf("%d",&a[i]);
        v.push_back(a[i]);
    }

    ans = 0;
    Solution s;
    vector<int> res;
    res = s.maxSumOfThreeSubarrays(v, k);
    cout << res[0] << " " << res[1] << " " << res[2] <<endl;
    
    return 0;
}
