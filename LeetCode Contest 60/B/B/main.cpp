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


//思路1： 和之前的那个值做比较，如果不相等就代表不是一个序列下来的，否则就是同一颜色。
class Solution {
public:
    #define rep(i,a,b) for (int i = (a); i <= (b); ++i)
    multimap<string,string> mp;
    map<string, bool> m, m1, m2;
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size())
            return false;
        
        if (pairs.size() ==0){
            if (words1 == words2){
                return true;
            }
            return false;
        }
        int n = pairs.size();
        rep (i,0,n-1){
            
            //cout << pairs[i].first << "  " << pairs[i].second << endl;
            //mp[pairs[i].first] = pairs[i].second;
            //mp[pairs[i].second] = pairs[i].first;
            mp.insert(pairs[i]);
            mp.insert(make_pair(pairs[i].second,pairs[i].first));
        }
        
        rep (i,0,(int)words1.size()-1){
            m[words1[i]] = true;
            m1[words1[i]] = true;
        }
        rep (i,0,(int)words2.size()-1){
            
            m[words2[i]] = true;
            m2[words2[i]] = true;
        }
        
        bool zy;
        string s;
        rep (i,0,(int)words1.size()-1){
            
            zy = false;
            //cout << words1[i] << "::: "<< mp[words1[i]] << endl;
            cout<< s<< endl;
            if (i==3){
                int jjl;
                jjl = 1;
            }
            s = words1[i];
            if (s == words2[i])
                zy = true;
            else
            for (auto pos = mp.lower_bound(s);pos != mp.upper_bound(s); ++pos)
            {
                cout << "    " << pos->second << endl;
                if (pos->second == "")
                    continue;
                if (pos->second == words2[i])
                {
                    zy = true;
                    break;
                }
            }
            if (!zy)
                return false;
        }
        rep (i,0,(int)words2.size()-1){
            zy = false;
            //cout << words2[i] << "::: "<< mp[words2[i]] << endl;
            s = words2[i];
            if (s == words1[i])
                zy = true;
            else
            for (auto pos = mp.lower_bound(s);pos != mp.upper_bound(s); ++pos)
            {
                //cout << "    " << pos->second << endl;
                if (pos->second == "")
                    continue;
                if (pos->second == words1[i])
                {
                    zy = true;
                    break;
                }
            }
            if (!zy)
                return false;
        }
        return true;
        
    }
};

int main(){
    freopen("/Users/Mr.ZY/Desktop/1.txt","r",stdin);
    vector<string> v1,v2;
    vector<pair<string,string>> v;
    cin >> n;
    cin >>m>>k;
    string s,sx,sy;
    rep (i,1,n){
        cin >> s;
        v1.push_back(s);
    }
    rep(j,1,m){
        cin >> s;
        v2.push_back(s);
    }
    
    rep (_,1,k){
        cin >> sx>> sy;
        v.push_back(make_pair(sx,sy));
    }
    
    Solution sss;
    if (sss.areSentencesSimilar(v1, v2, v))
        cout << "YES";
    else
        cout << "NO" << endl;

    return 0;
}
