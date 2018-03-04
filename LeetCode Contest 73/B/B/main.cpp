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
string str;

class Solution {
public:
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
#define rep2(i,a,b) for (int i = (a); i >= (b); --i)
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int n = (int)ghosts.size();
        int ans = abs(target[0]) + abs(target[1]);
        rep (i,0,n-1){
            int x = abs(ghosts[i][0]-target[0]) + abs(ghosts[i][1]-target[1]);
            if (x <= ans)
                return false;
        }
        return true;
    }
};

int main(){
    vector<int> v;
    cin >> n >> m;
    rep (i,1,n){
        cin >> a[i];
        v.push_back(a[i]);
    }
    Solution s;
    
    return 0;
}
