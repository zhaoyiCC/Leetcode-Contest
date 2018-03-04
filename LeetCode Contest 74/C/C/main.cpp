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
    int bbb[50010];
    ll numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int n = (int)A.size();
        ll ans = 0;
        int i = 0;
        
        
        rep (p,0,n-1){
//            i = p;
//            while(i < n)
            if (p >= i)
                i = p;
            
            {
                int mx = A[i];
                int j= i;
                ll tot = 0;
                while (i < n && mx >= L && mx <= R){
                    i++;
                    
                    tot++;
                    if (i < n)
                        mx = max(mx, A[i]);
                }
//                ans+=(tot)*(tot+1)/2LL;
//                if (i==j)
//                    i++;
            }
            if (!(A[p]>=L && A[p] <= R))
//
            {
                int q = p;
//                if (A[p]<L)
                {
//                    rep (q,p+1,i-1)
                    while (q < n)
                    {
                        if (A[q] > R)
                            break;
                        if (A[q] >= L && A[q] <= R){
                            bbb[q]++;
                            break;
                        }
                        q++;
                    }
                }
            }else
            if (i-p>=0)
                ans+=(i-p)*(1+bbb[p]);
        }
        return ans;
    }
    
};

int main(){
    vector<int> v={73,55,36,5,55,14,9,7,72,52};
    Solution s;
    cout << s.numSubarrayBoundedMax(v, 32,69);
    return 0;
}
