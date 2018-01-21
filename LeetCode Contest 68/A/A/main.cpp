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

class Solution {
public:
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
    #define rep2(i,a,b) for (int i = (a); i >= (b); --i)
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0)
            return true;
        int m = matrix[0].size();
        
        int x, y;
        rep2 (i,n-1,0){
            x = matrix[i][0];
            y = 0-i;
            
            rep (p,0,n-1)
            rep (q,0,m-1)
            {
                if (p>i && q-p==y && matrix[p][q] != x)
                    return false;
            }
        }
        
        rep (j,0,m-1){
            x = matrix[0][j];
            y = j-0;
            
            rep (p,0,n-1)
            rep (q,0,m-1)
            {
                if (q>j&& q-p==y && matrix[p][q] != x)
                    return false;
            }
        }
        return true;
    }
};

int main(){
    vector<int> v;
    cin >> n;
    rep (i,1,n){
        cin >> a[i];
    }
    ans = 0;
    Solution s;
    
    return 0;
}
