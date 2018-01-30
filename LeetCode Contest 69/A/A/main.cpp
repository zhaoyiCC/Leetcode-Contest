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

#define rep2(i,a,b) for (int i = (a); i >= (b); --i)

using namespace std;

const int N = 10010;
int ans, n , m, k, a[N];

class Solution {
public:
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
    #define rep2(i,a,b) for (int i = (a); i >= (b); --i)
    int numJewelsInStones(string J, string S) {
        size_t n = J.size();
        size_t m = S.size();
        map<char, int> mp;
        rep (i,0,n-1){
            mp[J[i]]++;
        }
        int ans = 0;
        rep (i,0,m-1){
            if (mp[S[i]] > 0)
                ans++;
        }
        return ans;
    }
};

int main(){
    vector<int> v;
    cin >> n;
    rep (i,1,n){
        cin >> a[i];
    }
    ans = 0;
    Solution s;
    
    return 0;
}
