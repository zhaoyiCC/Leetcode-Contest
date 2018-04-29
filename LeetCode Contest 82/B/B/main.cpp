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
    int numFriendRequests(vector<int>& a) {
        vector<int> age;
        age.clear();
        int num[1010];
        memset(num, 0, sizeof(num));
        for (auto i: a){
            num[i]++;
        }
        rep (i,1,120){
            if (num[i]){
                age.push_back(i);
            }
        }
        int n = (int) age.size();
        int ans = 0;
        rep (i,0,n-1){
            int j = age[i];
            if ((double)j > 0.5*(double)j+7.0)
            ans += num[j] * (num[j]-1);
        }
        rep (i, 0, n-1){
            rep (j,0,n-1){
                if (i != j){
                    if ((double)age[j] <= (double)0.5*(double)age[i]+7.0 || age[j] > age[i] || (age[j] > 100 && age[i] < 100)){
                        continue;
                    }
                    ans += num[age[i]] * num[age[j]];
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> v= {73,106,39,6,26,15,30,100,71,35,46,112,6,60,110};
//    {20, 30, 100, 110, 120};
    cout << s.numFriendRequests(v) << endl;
    return 0;
}
