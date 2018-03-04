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
    string customSortString(string S, string T) {
        string s=S, t=T;
        int n = (int)S.size();
        int m = (int)T.size();
        int d[110];
        memset(d,0,sizeof(d));
        bool b[110][110];
        memset(b,false,sizeof(b));
        int vis[110];
        memset(vis,0,sizeof(vis));
        for (auto i: t){
            vis[i-'a']++;
        }
        rep (i,0,n-1){
            rep (j,i+1,n-1){
                if (s[i] == s[j])
                    continue;
                int x = s[i]-'a';
                int y = s[j]-'a';
                if (b[y][x])
                    continue;
                d[y]++;
                b[x][y] = true;
            }
        }
        string res;
        while (true){
            bool zy = true;
            rep (i,0,25){
                if (vis[i] > 0 && d[i] == 0){
                    rep (j,1,vis[i]){
                        res+=(i+'a');
                    }
                    rep (j,0,25){
                        if (j != i && b[i][j]){
                            d[j]--;
                        }
                    }
                    zy = false;
                    vis[i] = -1;
                    break;
                }
            }
            if (zy)
                return res;
        }
        return res;
    }
};

int main(){
    vector<int> v;
    Solution s;
    cout << s.customSortString("cba", "abcd");
    return 0;
}
