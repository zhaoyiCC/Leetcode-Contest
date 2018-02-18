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
    int n;
    vector<string> res;
    char zy[1010];
    string s;
    char work(char c){
        if (c>='a'&&c<='z')
            return c+'A'-'a';
        return c+'a'-'A';
    }
    void dfs(int k){
        if (k == n){
            string sss(zy);
            res.push_back(zy);
            return ;
        }
        if (isalpha(s[k])){
            zy[k] = s[k];
            dfs(k+1);
            zy[k] = work(s[k]);
            dfs(k+1);
        }else{
            zy[k] = s[k];
            dfs(k+1);
        }
    }
    vector<string> letterCasePermutation(string S) {
        s = S;
        n = (int)s.size();
        dfs(0);
        return res;
    }
};

int main(){
    cin >> str;
    Solution s;
    vector<string> pp;
    pp = s.letterCasePermutation(str);
    for (auto i: pp){
        cout << i << endl;
    }
    return 0;
}
