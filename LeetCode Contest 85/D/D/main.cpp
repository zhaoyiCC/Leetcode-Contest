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
/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int pairStr(string s1, string s2){
        int n = s1.size();
        int res = 0;
        rep (i,0,n-1){
            if (s1[i] == s2[i]){
                res++;
            }
        }
        return res;
    }
    
    void findSecretWord(vector<string>& ss, Master& master) {
        
        
        srand((unsigned)time(0));
        vector<string> zy;
        rep (i,1,10){
            
            int n = ss.size();
            int m = rand()%n;
            int x = master.guess(ss[m]);
            if (x==6){
                return ;
            }
            zy.clear();
            rep (i,0,n-1){
                if (i == m){
                    continue;
                }
                if (pairStr(ss[i], ss[m])==x){
                    zy.push_back(ss[i]);
                }
            }
            ss = zy;
        }
    }
};

int main(){
    vector<vector<int> > v;
    vector<int> v1 = {0,0};
    vector<int> v2 = {0,0};
    v = {v1,v2};
//    Solution s;
    cout << rand();
//    cout << s.largestIsland(v) << endl;
    return 0;
}
