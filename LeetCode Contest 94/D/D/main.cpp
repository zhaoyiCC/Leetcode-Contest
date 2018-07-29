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

#define rep2(i,a,b) for (ll i = (a); i >= (b); --i)

using namespace std;

const ll N = 10010;
ll ans, n , m, k, a[N];
string str;

typedef long long ll;
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)

typedef long long ll;
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
class Solution {
public:
    int work(vector<int>& v, int x, int y, int pos){
        int now = x+y, ans = 0;
        while (true){
            auto i = lower_bound(v.begin()+pos, v.end(), now);
            if (i==v.end()||*i != now){
                break;
            }
            x = y;
            y = now;
            now = x+y;
            ans ++;
        }
        return ans;
    }
    int lenLongestFibSubseq(vector<int>& A) {
        int n = (int)A.size(), ans = 0;
        rep (i,0,n-1){
            rep (j,i+1,n-1){
                ans = max(ans, 2 + work(A, A[i], A[j], j+1));
            }
        }
        if (ans<3)
            return 0;
        return ans;
    }
};

int main(){
    vector<int> v = {1,2,5};
    
    Solution s;
    cout << s.lenLongestFibSubseq(v) << endl;
    return 0;
}
