#include<iostream>
#include<vector>
using namespace std;

// 可以进行一次买卖的股票收益问题，暴力方法最后一个用例超时
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int size = (prices.size() <= 10000)?prices.size():10000;
        for(int i = 0;i<size; i++){
            for(int j = i; j<size; j++){
                max = (max>(prices[j] - prices[i]))?max:(prices[j] - prices[i]);
            }
        }
        return max;
    }
};