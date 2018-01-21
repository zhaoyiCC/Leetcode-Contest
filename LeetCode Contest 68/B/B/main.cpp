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
    string reorganizeString(string S) {
        vector<int> mp(26);
        int n = S.size();
        for (char c: S) ++mp[c-'a'];
        vector<pair<int, char>> charCounts;
        for (int i = 0; i < 26; ++i) {
            if (mp[i] > (n+1)/2) return "";
            if (mp[i]) charCounts.push_back({mp[i], i+'a'});
        }
        sort(charCounts.rbegin(), charCounts.rend());
        string strSorted;
        for (auto& p: charCounts)
            strSorted += string(p.first, p.second);
        string ans;
        for (int i = 0, j = (n-1)/2+1; i <= (n-1)/2; ++i, ++j) {
            ans += strSorted[i];
            if (j < n) ans += strSorted[j];
        }
        return ans;
    }
};
class Solution2 {
public:
    #define rep(i,a,b) for (int i = (a); i <= (b); ++i)
    static bool cmp(pair<char,int> p, pair<char,int> q){
        return p.second > q.second;
    }
    string reorganizeString(string S) {
        map<char,int> mp;
        size_t n = S.size();
        rep (i,0,n-1){
            mp[S[i]]++;
        }
        vector<pair<char,int>> v;
        for (auto it: mp){
            v.push_back(make_pair(it.first,it.second));
            if (it.second > n-it.second+1){
                return "";
            }
        }
        sort(v.begin(), v.end(), cmp);
        string ans = "";
        int last = 1;
        rep (i,0,v.size()-1){
            if (i == 0){
                rep (j,1,v[0].second){
                    ans = ans+v[0].first;
                }
                continue;
            }
            rep (j,0,v[i].second-1){
//                cout << v[i].first << endl;
                string tmp = "0";
                tmp[0] = v[i].first;
//                cout << tmp << endl;
                if (last > ans.size())
                    last = 1;
                ans.insert(last,tmp );
                last+=2;
            }
        }
        return ans;
    }
};

int main(){
    string s;
    cin >> s;
    Solution sss;
    cout << sss.reorganizeString(s) << endl;
    return 0;
}
