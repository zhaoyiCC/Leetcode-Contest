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

typedef long long ll;
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
#define rep2(i,a,b) for (int i = (a); i >= (b); --i)
class Solution {
    public:
    bool b[10100];
    void dfs(int k, vector<vector<int>>& a){
        b[k] = true;
        for (auto i: a[k]){
            if (!b[i]){
                dfs(i, a);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        memset(b, false, sizeof(b));
        int n = rooms.size();
        if (n==0){
            return true;
        }
        int m = rooms[0].size();
        dfs(0, rooms);
        rep (i,0,n-1){
            if (!b[i]){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution s;
    vector<int> v= {73,106,39,6,26,15,30,100,71,35,46,112,6,60,110};
//    {20, 30, 100, 110, 120};
    cout << s.numFriendRequests(v) << endl;
    return 0;
}
