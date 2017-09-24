//
//  main.cpp
//  2
//
//  Created by ohazyi on 2017/9/10.
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
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
#define rep2(i,a,b) for (int i = (a); i >= (b); --i)

using namespace std;

const int N = 10010;
int ans, n , m, a[N];
class MagicDictionary {
public:
    
    vector<string> v;
    /** Initialize your data structure here. */
    MagicDictionary() {
        v.clear();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        v = dict;
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
//        cout << v.size()<<"gg";
        if (v.size() == 0)
            return false;
        int l = word.size();
        int cnt;
        for (int i = 0; i < (int)v.size(); ++i){
//            cout << v[i] << endl;
            cnt = 0;∑
            if (l == v[i].size()){
                for (int j = 0; j < l; ++j){
                    if (word[j] != v[i][j]){
                        cnt++;
                    }
                }
            }
            if (cnt == 1){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */

int main() {

    cin >> n;
    vector<string> v;
    string s;
    rep (i,1,n){
        cin >> s;
        v.push_back(s);
    }
    MagicDictionary md;
    md.buildDict(v);
    cin >> m;
    rep (i,1,m){
        cin >> s;
        cout << md.search(s);
    }

}
