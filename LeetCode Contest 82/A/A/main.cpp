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
    bool checkVowel(char c){
        char ch;
        ch = tolower(c);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    string toP(string s){
        string ans = s;
        if (s.size() == 0){
            return s;
        }
        int n = (int)s.size();
        if (checkVowel(s[0])){
            ans += "ma";
        }else{
            ans = s.substr(1, n-1) + s[0] + "ma";
        }
        return ans;
    }
    string mulS(int k){
        string ss = "";
        rep (i,1,k){
            ss += "a";
        }
        return ss;
    }
    string toGoatLatin(string s) {
        string res = "", sing = "";
        int n = (int)s.size(), last = 0, cnt=0;
        auto pos = s.find(" ");
        while (pos < n && pos != string::npos){
            sing = s.substr(last, pos-last);
            if ((cnt++) > 0)
                res += " ";
            res += toP(sing)+mulS(cnt);
            last = (int)pos + 1;
            pos = s.find(" ", pos+1);
        }
        pos = n;
        sing = s.substr(last, pos-last);
        if ((cnt++) > 0)
        res += " ";
        res += toP(sing)+mulS(cnt);
        last = (int)pos + 1;
        pos = s.find(" ", pos+1);
//        Imaa peaksmaaa oatGmaaaa atinLmaaaaa
//        Imaa peaksmaaa oatGmaaaa atinLmaaaaa
//        heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa
//        heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa
        return res;
    }
};

int main(){
    Solution s;
    
    string zy = s.toGoatLatin("The quick brown fox jumped over the lazy dog");
    cout << zy << endl;
    return 0;
}
