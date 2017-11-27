//
//  main.cpp
//  B_rectify
//
//  Created by ohazyi on 2017/11/26.
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
class Solution {
public:
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
    map<pair<string,string>, bool> mp;
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size())
            return false;
        rep (i,0,(int)pairs.size()-1){
            mp[pairs[i]] = true;
        }
        rep (i,0,(int)words1.size()-1){
            if (words1[i]!=words2[i]&&!mp[make_pair(words1[i],words2[i])]&&!mp[make_pair(words1[i],words2[i])])
                return false;
        }
        return true;
    }
};

int main() {

    cin >> n >> m;
    rep (i, 1, n){
        scanf("%d",&a[i]);
    }

    ans = 0;

    cout << ans << endl;

    return 0;
}
