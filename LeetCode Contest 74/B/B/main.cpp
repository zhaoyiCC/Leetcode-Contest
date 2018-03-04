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
    int numMatchingSubseq(string S, vector<string> words) {
        vector<int> vec[27];
        rep (i,0,(int)S.size() - 1){
            vec[S[i]-'a'].push_back(i);
        }
        int pos, ans = 0;
        for (auto word: words){
            pos = -1;
            bool zy = true;
            for (auto i: word){
                vector<int>::iterator h = upper_bound(vec[i-'a'].begin(), vec[i-'a'].end(), pos);
                
                if (h != vec[i-'a'].end()){
                    pos = *h;
                }else{
                    zy = false;
                    break;
                }
            }
            if (zy){
                ans++;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    cout << s.numMatchingSubseq("abcde", {"a", "bb", "acd", "ace"}) << endl;
    return 0;
}
