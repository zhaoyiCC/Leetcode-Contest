//
//  main.cpp
//  B
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

class Solution {
public:
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
    vector<int> a;
    int k;
    double minmaxGasDist(vector<int>& stations, int K) {
        double ans = 0, l, r, mid;
        a = stations;
        k = K;
        int n =(int)a.size();
        l = 0;
        r = a[n-1]-a[0];
        int tot;
        while (r-l>=1e-6){
            tot = 0;
            mid = (l+r)/2.0;
            rep (i,0,n-2){
                tot += 1.0*(a[i+1]-a[i])/mid;
            }
            if (tot <= k){
                r = mid;
            }else{
                l = mid;
            }
        }
        return l;
    }
};

int main(){
    vector<int> v={1,2,3,4,5,6,7,8,9,10};
    ans = 0;
    Solution s;
    int k = 9;
    cout << s.minmaxGasDist(v, k);
    return 0;
}
