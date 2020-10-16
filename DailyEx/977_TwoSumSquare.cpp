#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 没有利用题目中的原来数据已经按照非降序排列好，负数的平方为降序，非负数的平方为非降序。
class Solution {
public:

    bool cmp(int a,int b){
        return a <= b;
    }

    vector<int> sortedSquares(vector<int>& A) {
        if(A.size() == 0) return A;
        vector<int>ans;
        for(int i : A){
            ans.push_back(i*i);
        }

        sort(ans.begin(),ans.end(),cmp);
        return ans;
    }

};