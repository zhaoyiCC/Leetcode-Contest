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
#include <cstdlib>

typedef long long ll;

using namespace std;

const int N = 10010;
int ans, n , m, k, a[N];

#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
#define rep2(i,a,b) for (int i = (a); i >= (b); --i)
class Solution {
public:
    const static int maxn = 2010;
    int mx, mi[maxn];
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        int maxi = -1;
        int n = arr.size();
        mi[n] = 1e9;
        rep2 (i,n-1,0)
            mi[i] = min(arr[i], mi[i+1]);
        
        mx = arr[0];
        rep (i,0,n-1){
            if (i == n-1 || mx <= mi[i+1]){
                ans++;
                if (i != n-1)
                    mx = arr[i+1];
            }else{
                if (i != n-1)
                    mx = max(mx, arr[i+1]);
            }
        }
        return ans;
    }
};

class Solution2 {
public:
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
    bool b[100];
    int n;
    int ans = 1, cnt = 0;
    vector<int> a;
    bool check(){
        vector<int> p;
        p = a;
        int last = 0;
        rep (i,0,n-1){
            if (b[i]){
                sort(p.begin()+last, p.begin()+i+1);
                last=i+1;
            }
        }
        rep (i,0,n-1){
            if (p[i]!=i){
                return false;
            }
        }
        return true;
    }
    void dfs(int k){
        if (k > n-1){
            if (check()){
                if (cnt > ans)
                    ans = cnt;
            }
            return ;
        }
        b[k] = false;
        dfs(k+1);
        cnt++;
        b[k] = true;
        dfs(k+1);
        cnt--;
    }
    int maxChunksToSorted(vector<int>& arr) {
        a = arr;
        memset(b,false,sizeof(b));
        n = arr.size();
        
        dfs(0);
        
        return ans;
    }
};

int main(){
    vector<int> v;
    cin >> n;
    rep (i,1,n){
        cin >> a[i];
        v.push_back(a[i]);
    }
    ans = 0;
    Solution s;
    cout << s.maxChunksToSorted(v) << endl;
    return 0;
}
