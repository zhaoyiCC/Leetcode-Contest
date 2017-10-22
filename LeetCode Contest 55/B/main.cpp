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
int ans, n , m;
class Solution {
public:
    int f[1010][1010], n, m;
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
    int minimumDeleteSum(string s1, string s2) {
        memset(f, 0, sizeof(f));
        n = s1.size();
        m = s2.size();
        rep (i,1,n)
            f[i][0] = f[i-1][0] + s1[i-1];
        rep (i,1,m)
            f[0][i] = f[0][i-1] + s2[i-1];

        rep (i, 1, n){
            rep (j, 1, m){
                if (s1[i-1]==s2[j-1]){
                    f[i][j] = f[i-1][j-1];
                }else{
                    f[i][j] = min(f[i-1][j]+s1[i-1], f[i][j-1]+s2[j-1]);
                }

            }
        }
        return f[n][m];
    }
};



int main() {
    string s1, s2;
    cin >> s1;
    cin >> s2;
    ans = 0;
    Solution s;
    ans = s.minimumDeleteSum(s1, s2);
    cout << ans << endl;

    return 0;
}
