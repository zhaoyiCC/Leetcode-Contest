//
//  main.cpp
//  A
//
//  Created by ohazyi on 2017/9/24.
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
    typedef long long ll;
     #define rep(i,a,b) for (int i = (a); i <= (b); ++i)
     #define rep2(i,a,b) for (int i = (a); i >= (b); --i)

    
    ll ans=0;
    int calPoints(vector<string>& ops) {
        vector<ll> a;
        string str;
        int siz, num;
        vector<ll>::iterator it;
        rep (i,0,(int)ops.size() - 1){
            siz = a.size();
            str = ops[i];
            if (str=="D"){
                a.push_back(a[siz-1]*2);
            }else if (str=="+"){
                a.push_back(a[siz-1]+a[siz-2]);
            }else if (str=="C"){
                it = a.end();
                it--;
                a.erase(it);
            }else{
                int start = 0;
                int neg = 1;
                if (ops[i][0]=='-'){
                    start = 1;
                    neg = -1;
                }
                num = 0;
                rep (j,start,(int)(ops[i].size())-1){
                    num = num*10+ops[i][j]-'0';
                }
                a.push_back(num*neg);
            }
        }
        rep (i,0,(int)a.size()-1){
            ans+=a[i];
        }
        return ans;
    }
};

int main() {
    vector<string> v;
    cin >> n ;
    string z;
    rep (i, 1, n){
        cin >> z;
        v.push_back(z);
    }

    ans = 0;

    Solution s;
    ans = s.calPoints(v);
    cout << ans << endl;
    return 0;
}
