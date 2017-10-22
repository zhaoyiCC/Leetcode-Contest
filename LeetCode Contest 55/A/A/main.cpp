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


#define rep2(i,a,b) for (int i = (b); i >= (a); --i)
class Solution {
public:
    #define rep(i,a,b) for (int i = (a); i <= (b); ++i)
    typedef long long ll;
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> a;
        a.push_back(1e9);

        ll ans = 0;
        int n = prices.size();
        rep (i,0,n-1){
            a.push_back(prices[i]);
        }
        a.push_back(0);
        int l=-1, r;

        rep (i,1,n){

            if (l==-1&&a[i]<=a[i-1]&&a[i]<=a[i+1]){
                l = i;
            }
             if (l != -1 && a[i]>a[i-1]&&a[i]>=a[i+1]){
                    cout << l << " "<<i <<endl;
                ans += a[i] - a[l] -fee;
                l = -1;
            }
        }
        return ans;
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
    ans = s.maxProfit(v, k);
    cout << ans << endl;
    return 0;
}
