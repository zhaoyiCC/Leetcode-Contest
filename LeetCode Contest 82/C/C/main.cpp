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
    int f[100010];
    int N = 10010;
    int n;
    int getmax(int k){
        int zmax = 0;
        while (k > 0)
        {
            zmax = max(zmax,f[k]);
            k -= k & (-k);
        }
        return zmax;
    }
    void add(int k,int x){
        while (k <= n){
            f[k] = max(f[k],x);
            k+=(k & (-k));
        }
    }
    int maxProfitAssignment(vector<int>& a, vector<int>& b, vector<int>& c) {
        vector<pair<int, int> > vv;
        n = (int)a.size();
        rep (i,0,n-1){
            vv.push_back(make_pair(-a[i], b[i]));
        }
        
        sort(vv.begin(), vv.end());
        vector<int> na;
        rep (j,0,n-1){
            auto i = vv[j];
            na.push_back(i.first);
            add(n-j, i.second);
        }
        int ans = 0;
        for (auto i: c){
            int j = lower_bound(na.begin(), na.end(), -i)-na.begin();
            cout << j << " " << n-j << endl;
            int mx = 0;
            if (j < n){
//                rep (k,j,n-1){
//                    mx = max(mx, vv[k].second);
//                }
                mx = getmax(n-j);
                ans += mx;//vv[j].second;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> v1={68,35,52,47,86};//85,47,57}; //2,4,6,8,10};
    vector<int> v2 = {67,17,1,81,3};//24,66,99};//10,20,30,40,50};
    vector<int> v3 = {92,10,85,84,82};//40,25,25};//4,5,6,7};
    Solution s;
    cout << s.maxProfitAssignment(v1, v2, v3) << endl;
    return 0;
}
