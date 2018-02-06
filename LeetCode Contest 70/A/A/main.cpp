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
    int find(int n,int k){
        if (k==1){
            return 0;
        }
        if (n==1){
            return 0;
        }
        int kk = (k+1)/2;
        int h = find(n-1, kk);
        if (h == 0){
            if (k==kk*2)
                return 1;
            return 0;
        }
        if (k==kk*2)
            return 0;
        return 1;
    }
    int kthGrammar(int N, int K) {
        return find(N,K);
    }
};

int main(){
    vector<int> v;
    cin >> n >> m;
    Solution s;
    cout << s.kthGrammar(n, m);
    return 0;
}
