//
//  main.cpp
//  C
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
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
#define rep2(i,a,b) for (int i = (a); i >= (b); --i)

using namespace std;

const int N = 10010;
int ans, n , m, a[N];
//不要用vector同时迭代器增加与删除，因为一旦删除导致迭代器失效很麻烦！！！
//这个时候能用pop_back()就用pop_back()，因为它的行为一定是在你的控制范围内的！！！
class Solution {
public:
    #define rep(i,a,b) for (int i = (a); i <= (b); ++i)
    vector<int> asteroidCollision(vector<int>& a) {
        int n = a.size();
        vector<int> ans;
        rep (i,0,n-1){
            if (a[i] >= 0){
                ans.push_back(a[i]);
                continue;
            }
            bool zy = true;
            while (!ans.empty() && ans.back() > 0){
                if (ans.back()<-a[i])
                    ans.pop_back();
                else if (ans.back() == -a[i]){
                    ans.pop_back();
                    zy = false;
                    break;
                }else{
                    zy = false;
                    break;
                }
            }
            if (zy)
                ans.push_back(a[i]);
        }
        return ans;
    }
};

int main() {
    vector<int> p = {1,2,3,4,5,6};
    auto it = p.end()-2;
    cout << *it << endl;
    it = p.erase(it);
    cout << *it << endl;
    cout << *(it+1) << endl;
    int x;
    vector<int> v;
    cin >> n;
    rep (i,1,n){
        cin >> x;
        v.push_back(x);
    }
    
    Solution s;
    vector<int> vans;
    vans = s.asteroidCollision(v);
    rep (i,0,(int)vans.size()-1)
        cout << vans[i] << " ";
    cout << endl;
    return 0;
}
