//
//  main.cpp
//  1
//
//  Created by ohazyi on 2017/9/10.
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

class Solution {
public:
    
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size()==0)
            return 0;
        int ans = 1;
        int tot = 1;
        for (int i = 1;  i <= (int)nums.size()-1; ++i){
            if (nums[i]> nums[i-1])
                tot++;
            else{
                tot = 1;
            }
            if (tot > ans)
                ans  = tot;
        }
        return ans;
    }
};

int main() {
    int n,x;
    vector<int> v;
    cin >> n;
    rep (i,1,n){
        cin >> x;
        v.push_back(x);
    }
    Solution s;
    cout << s.findLengthOfLCIS(v);
//    int ans = s.;
//    cout << ans << endl;
    return 0;
}
