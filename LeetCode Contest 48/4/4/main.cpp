//
//  main.cpp
//  4
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

using namespace std;
const int N = 10010;
int a[N];

class Solution {
public:
    int n;
    int f[2011], cnt[2011];
    
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        memset(f,0,sizeof(f));
        n = nums.size();
        for (int i = 0; i < n; ++i)
            cnt[i] = 1;
        for (int i = 0; i < n; ++i){
            for (int j = i+1; j < n; ++j){
                if (nums[j] > nums[i]){
                    if (f[j] == f[i]+1){
                        cnt[j] += cnt[i];
                    }
                    if (f[j] < f[i]+1){
                        f[j] = f[i]+1;
                        cnt[j] = cnt[i];
                    }
                }
            }
        }
        int ans = 0;
        int tot = 0;
        for (int i = 0; i < n; ++i){
            if (f[i]==ans){
                tot+=cnt[i];
            }
            if (f[i] > ans){
                ans = f[i];
                tot = cnt[i];
            }
        }
//        cout << ans << endl;
        return tot;
    }
};
int main(){
    int n, x;
    cin >> n;
    vector<int> v;
    for (int i = 1; i <= n; ++i){
        cin >> x;
        v.push_back(x);
    }
    Solution s;
    int ans = s.findNumberOfLIS(v);
    cout << ans << endl;
    return 0;
}
