#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 状态定义的挺好，就是状态转移方程没写出来
        // s[j]表示凑成金额j所需的最少硬币数，状态转移方程 s[j] = min{s[j - c] + 1} 其中c为硬币金额，需要遍历
        if(amount == 0) return 0;
        int* DP = new int[amount + 1]();
        DP[0] = 0;

        for(int i = 1; i<= amount; i++){
            int minCoins = INT_MAX;
            for(auto x : coins){
                int min = INT_MAX;
                if(i - x >= 0 && DP[i-x] != -1) min = DP[i - x];
                if(min < minCoins) minCoins = min;
            }
            if(minCoins != INT_MAX)DP[i] = minCoins + 1;
            else DP[i] = -1;
        }
        return DP[amount];
    }
};