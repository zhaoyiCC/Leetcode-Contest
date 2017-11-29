//
//  main.cpp
//  D
//
//  Created by ohazyi on 2017/10/2.
//  Copyright © 2017年 ohazyi. All rights reserved.
//  Test:
//  (let x 2 y (add 0 (let x 500 0)) (add 0 (add 0 (add x 3))))

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
#include <unordered_map>   

typedef long long ll;

using namespace std;

#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
#define rep2(i,a,b) for (int i = (b); i >= (a); --i)
class Solution {
public:
    map<string,int> mp[2010];//代表每一层的变量对应的值
    vector<int> vi;
    vector<string> vs;
    map<string,int> relation = {{"add ",1},{"mult",2},{"let ",3}};
    int tot = 0, mx = 0;
    
    int getValue(string& s, int level){
        if (s.size()==0){
            cout << "!!!\"\"!!!" << endl;
            return 0;
        }
        int sign = 1;
        if (s[0] == '-')
        {
            sign = -1;
            s = s.substr(1,s.size());
        }
        if (std::all_of(s.begin(), s.end(), ::isdigit)){//C++11 判断字符串是否是数字，允许前导0
            //cout << "value Int: " << atoi(s.c_str()) << endl;
            return sign * atoi(s.c_str());
        }
        for (int i = level-1; i >= 1; --i) //从内层外外层找定义的变量
        if (mp[i].count(s) != 0)
            return mp[i][s];
        cout << "!!!Not Exist!!!" << endl;
        return 0;
    }
    
    int letExpression(string& s, int level){
        mx = max(mx, level);
        string name;
        int num;
        vector<int> vi;
        int l = 0, r = 0;
        int n = s.size();
        
        int i = 5;
        //int j;//!!!wrong!!!不能强制转换，会把一个find出来的大数弄成-1
        size_t j;
        int type;
        while (true){//一直执行到expr为止
            
            if (s[i]=='('){//代表是执行到了expr, 因为expr不会出现子表达式
                type = 1;
                break;
            }
            
            j = s.find(" ",i);
            if (j == string::npos){
                //cout << j << "   " << s.find(" ",i) << endl;
            //if (j!=string::npos){
            //if (j == -1 || j > n){//找不到空格 代表是一个单个的标识符名字，即也执行到了expr了
                type = 2;
                break;
            }
            name = s.substr(i, j-1-i+1);
            
            i = j+1;
            if (s[i] != '('){//代表没有子结构
                j = s.find(" ",i);
                string subs = s.substr(i,j-1-i+1);
                num = getValue(subs, level);
                i = j+1;
            }else{
                l = 1;
                r = 0;
                j = i+1;
                while (l > r){
                    if (s[j]=='(')
                        l++;
                    if (s[j]==')')
                        r++;
                    j++;
                }
                
                string subs = s.substr(i,j-1-i+1);
                switch (relation[subs.substr(1,4)]) {
                    case 1 : num = addExpression(subs, level+1); break;
                    case 2 : num = multExpression(subs, level+1); break;
                    case 3 : num = letExpression(subs, level+1); break;
                        //default: num = 0;
                }
                i = j+1;//j is a space
            }
            cout << "map" << level << " " << name << " : " << num << endl;
            mp[level][name] = num;
        }
        string subs = s.substr(i, n-2-i+1);
        if (type == 2)
            return getValue(subs, level);
        int ans = 0;
        switch (relation[subs.substr(1,4)]) {
            case 1 : ans = addExpression(subs, level+1); break;
            case 2 : ans = multExpression(subs, level+1); break;
            case 3 : ans = letExpression(subs, level+1); break;
                //default: num = 0;
        }
        mp[level].erase(mp[level].begin(),mp[level].end());
        return ans;
    }
    
    int addExpression(string& s,int level){ //add xxx
        string name;
        int num1 = 0, num2 = 0;
        vector<int> vi;
        int l = 0, r = 0;
        int n = s.size();
        
        int i = 5, j;
        if (s[i] != '('){//代表没有子结构
            j = s.find(" ",i);
            string subs = s.substr(i,j-1-i+1);
            num1 = getValue(subs, level);
        }else{
            l = 1;
            r = 0;
            j = i+1;
            while (l > r){
                if (s[j]=='(')
                    l++;
                if (s[j]==')')
                    r++;
                j++;
            }
            string subs = s.substr(i,j-1-i+1);
            switch (relation[subs.substr(1,4)]) {
                case 1 : num1 = addExpression(subs, level+1); break;
                case 2 : num1 = multExpression(subs, level+1); break;
                case 3 : num1 = letExpression(subs, level+1); break;
                    //default: num = 0;
            }
        }
        
        i = j+1;
        if (s[i] != '('){//代表没有子结构
            j = s.find(")",i);
            string subs = s.substr(i,j-1-i+1);
            num2 = getValue(subs, level);
        }else{
            l = 1;
            r = 0;
            j = i+1;
            while (l > r){
                if (s[j]=='(')
                    l++;
                if (s[j]==')')
                    r++;
                j++;
            }
            string subs = s.substr(i,j-1-i+1);
            switch (relation[subs.substr(1,4)]) {
                case 1 : num2 = addExpression(subs, level+1); break;
                case 2 : num2 = multExpression(subs, level+1); break;
                case 3 : num2 = letExpression(subs, level+1); break;
                //default: num = 0;
            }
        }
        cout << s << " ::: " << num1 << " + " << num2 << endl;
        return num1+num2;
    }
    
    int multExpression(string& s,int level){
        if (s=="(mult x5 -7)"){
            int jj =  1;
            jj++;
        }
        string name;
        int num1 = 0, num2 = 0;
        vector<int> vi;
        int l = 0, r = 0;
        int n = s.size();
        
        int i = 6, j;
        if (s[i] != '('){//代表没有子结构
            j = s.find(" ",i);
            string subs = s.substr(i,j-1-i+1);
            num1 = getValue(subs, level);
        }else{
            l = 1;
            r = 0;
            j = i+1;
            while (l > r){
                if (s[j]=='(')
                    l++;
                if (s[j]==')')
                    r++;
                j++;
            }
            string subs = s.substr(i,j-1-i+1);
            switch (relation[subs.substr(1,4)]) {
                case 1 : num1 = addExpression(subs, level+1); break;
                case 2 : num1 = multExpression(subs, level+1); break;
                case 3 : num1 = letExpression(subs, level+1); break;
                    //default: num = 0;
            }
        }
        
        i = j+1;
        if (s[i] != '('){//代表没有子结构
            j = s.find(")",i);
            string subs = s.substr(i,j-1-i+1);
            num2 = getValue(subs, level);
        }else{
            l = 1;
            r = 0;
            j = i+1;
            while (l > r){
                if (s[j]=='(')
                    l++;
                if (s[j]==')')
                    r++;
                j++;
            }
            string subs = s.substr(i,j-1-i+1);
            switch (relation[subs.substr(1,4)]) {
                case 1 : num2 = addExpression(subs, level+1); break;
                case 2 : num2 = multExpression(subs, level+1); break;
                case 3 : num2 = letExpression(subs, level+1); break;
                    //default: num = 0;
            }
        }
        cout << s << " ::: " << num1 << " * " << num2 << endl;
        return num1*num2;
    }

    int evaluate(string expression) {
        
        int ans = 0;
        switch (relation[expression.substr(1,4)]) {
            case 1 : ans = addExpression(expression, 1); break;
            case 2 : ans = multExpression(expression, 1); break;
            case 3 : ans = letExpression(expression, 1); break;
                //default: num = 0;
        }
        return ans;
    
    }
};

class Solution2 {
public:
    int evaluate(string expression) {
        map<string,int> myMap;
        return help(expression,myMap);
    }
    
    int help(string expression,map<string,int> myMap) {
        if ((expression[0] == '-') || (expression[0] >= '0' && expression[0] <= '9'))
            return stoi(expression);
        else if (expression[0] != '(')
            return myMap[expression];
        //to get rid of the first '(' and the last ')'
        string s = expression.substr(1,expression.size()-2);
        int start = 0;
        string word = parse(s,start);
        if (word == "let") {
            while (true) {
                string variable = parse(s,start);
                //if there is no more expression, simply evaluate the variable
                if (start > s.size())
                    return help(variable,myMap);
                string temp = parse(s,start);
                myMap[variable] = help(temp,myMap);
            }
        }
        else if (word == "add"){
            int ans1 = help(parse(s,start),myMap);
            int ans2 = help(parse(s,start),myMap);
            cout << s << " ::: " << ans1 << " + " << ans2 << endl;
            return ans1+ ans2;
            
        }
        else if (word == "mult"){
            int ans1 = help(parse(s,start),myMap);
            int ans2 = help(parse(s,start),myMap);
            cout << s << " ::: " << ans1 << " * " << ans2 << endl;
            return ans1*ans2;
        }
        cout << "@@@" << endl;
        return -1;
    }
    
    //function to seperate each expression
    string parse(string &s,int &start) {
        int end = start+1, temp = start, count = 1;
        if (s[start] == '(') {
            while (count != 0) {
                if (s[end] == '(')
                    count++;
                else if (s[end] == ')')
                    count--;
                end++;
            }
        }
        else {
            while (end < s.size() && s[end] != ' ')
                end++;
        }
        start = end+1;
        return s.substr(temp,end-temp);
    }
};
class Solution3 {
private:
    unordered_map<string, int> hash; //内部实现了哈希表的Map，查找速度比map块，O(1)vsO(logn)
    
    string getNext(string& e, int& idx) { //前面一个引用是为了因为我们无需修改e，减少拷贝赋值的是空开销；后面一个引用相当于一个变参，我们之后继续用这个改变后的变参
        string ret = "";
        int cnt = 0;
        while (e[idx] != ' ' || cnt != 0) { //遇到一个完整的括号就匹配结束，或者遇到下一个不在括号里的空格
            ret += e[idx];
            if (e[idx] == '(') cnt ++;
            if (e[idx] == ')') cnt --;
            idx ++;
        }
        idx ++;
        return ret; //把这一部分的字符串值返回
    }
    
    int calculate(string e) {
        if (e[0] != '(') {  //代表没有子结构，是一个整数或者
            if (hash.count(e) > 0) return hash[e];  //已经存过的标识符就直接去map里找
            return stoi(e); //字符串转数字的值
        }
        e.back() = ' ';
        if (e[1] == 'l') {
            auto bak = hash;
            int p = 5;
            while (true) {
                string a = getNext(e, p);
                if (p >= e.size()) {
                    int ret = calculate(a);
                    hash = bak; //！！！每一层次做完这个层次自己定义的变量就可以舍弃了
                    return ret;
                }
                string b = getNext(e, p);
                hash[a] = calculate(b);
            }
        } else {
            int p = (e[1] == 'a' ? 5 : 6);
            string a = getNext(e, p), b = getNext(e, p);
            if (e[1] == 'a') {
                return calculate(a) + calculate(b);
            } else {
                return calculate(a) * calculate(b);
            }
        }
    }
    
public:
    int evaluate(string expression) {
        hash.clear();
        return calculate(expression);
    }
};


class Solution4 {
    int eval(string s, map<string, int> p) {
        int n = s.length(), i, j, k, a, d, a1, a2, ans;
        vector<string> ss;
        
        if (s == "") return 0;
        if ((s[0] >= '0') && (s[0] <= '9')) return stoi(s);
        if (s[0] == '-') return stoi(s);
        if (s[0] == '+') return stoi(s);
        if ((s[0] >= 'a') && (s[0] <= 'z')) return p[s];
        
        // solve sub problems
        s[s.length() - 1] = ' ';
        for (i = 1; i < s.length(); i++) { //先把字符串拆分成各个部分
            if (s[i] == '(') {
                d = 0;
                for (j = i; j < s.length(); j++) {
                    if (s[j] == '(') d++;
                    if (s[j] == ')') {
                        d--;
                        if (d == 0) {
                            ss.push_back(s.substr(i, j - i + 1));
                            i = j;
                            break;
                        }
                    }
                }
            }
            else if (s[i] != ' ') {
                for (j = i + 1; (j < s.length()) && s[j] != ' '; j++);
                ss.push_back(s.substr(i, j - i));
                i = j;
            }
        }
        
        if (ss[0] == "let") {
            for (i = 1; i < ss.size() - 1; i += 2) {
                d = eval(ss[i + 1], p);
                p[ss[i]] = d;
            }
            ans = eval(ss[ss.size() - 1], p);
        }
        
        if (ss[0] == "add") {
            a1 = eval(ss[1], p);
            a2 = eval(ss[2], p);
            ans = a1 + a2;
        }
        
        if (ss[0] == "mult") {
            a1 = eval(ss[1], p);
            a2 = eval(ss[2], p);
            ans = a1 * a2;
        }
        
        return ans;
    }
public:
    int evaluate(string s) {
        map<string, int> p;
        return eval(s, p);
    }
};

const int N = 10010;
int ans, n , k, a[N];


int main() {
    
    cout << string::npos << endl;
//    string str;
//    str = "x123";
//    cout << str.find(" ",1);
//    if (std::all_of(str.begin(), str.end(), ::isdigit))
//    cout << atoi(str.c_str())<< endl;
    string str;
    getline(cin, str);

    ans = 0;
    Solution s;
    ans = s.evaluate(str);
    cout << ans << endl;
    
    return 0;
}
