#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        // 奇数对应的为中位数，偶数对应的为中位后一
        if(s.size() == 0 || s.size() == 1) return;
        int mid = s.size() % 2== 0? s.size()/2 - 1:s.size()/2;
        int i = 0;
        while( i <= mid){
            char c = s[i];
            s[i] = s[s.size()-1-i];
            s[s.size()-1-i] = c; 
            i++;
        }
    }
};
