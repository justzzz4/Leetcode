#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(char a,char b){
        return (int)a < (int)b;
    }

    bool isAnagram(string s, string t) {
        if(s == t)return true;
        if(s.size()!=t.size())return false;
        vector<char> str1;
        vector<char> str2;
        for(auto x : s){
            str1.push_back(x);
        }
        for(auto x : t){
            str2.push_back(x);
        }
        
        sort(str1.begin(),str1.end(),cmp);
        sort(str2.begin(),str2.end(),cmp);
        for(int i = 0; i<str1.size();i++){
            if(str1[i]!=str2[i]) return false;
        }
        return true;
        
    }
};