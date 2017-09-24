//
//  main.cpp
//  D
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
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
#define rep2(i,a,b) for (int i = (a); i >= (b); --i)
class Solution {
public:

    int day[20010];
    int ans = 1e9;
    int kEmptySlots(vector<int>& flowers, int k) {
        rep (i,0,(int)flowers.size()-1){
            day[flowers[i]] = i+1;
        }
        int l = 1;
        int r = l+k+1;
        rep (i,2,(int)flowers.size()){
            if (i==l)
                continue;
            if (i == r){
                ans = min(ans, max(day[l], day[r]));
                l = r;
                r = l+k+1;
                continue;
            }
            if (day[i]<=day[l]||day[i]<=day[r]){
                l = i;
                r = l+k+1;
            }
        }
        if (ans==1e9)
            return -1;
        return ans;
    }
};

int main() {

    cin >> n  >> m;
    vector<int> v;
    rep (i, 1, n){
        scanf("%d",&a[i]);
        v.push_back(a[i]);
    }

    ans = 0;
    Solution s;
    ans = s.kEmptySlots(v, m);
    cout << ans << endl;

    return 0;
}
