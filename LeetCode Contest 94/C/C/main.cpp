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
    bool mywork(vector<int>& a, int k, int H){
        int res = 0;
        for (auto i: a){
            res += (i / k) + ((i % k) != 0);
        }
        return (res <= H);
    }
    int minEatingSpeed(vector<int>& piles, int H) {
        if (piles.size() == 0)
            return 0;
        int l = 1, r = 1e9, mid, ans;
        while (l<=r){
            mid = (l+r) >> 1;
            if (mywork(piles, mid, H)){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<int> v= {30,11,23,4,20};
    cout << s.minEatingSpeed(v, 6) << endl;
    return 0;
}
