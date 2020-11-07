#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 最长上升子序列
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) return 0;
        int* DP = new int[size+1]();
        int res = 0;
        // 将DP数组初始化
        for(int i = 1;i<=size; i++) DP[i] = 1;
        
        // 状态转移
        for(int i = 1;i<=size; i++){
            for(int j = 1;j<i;j++){
                if(nums[i - 1] > nums[j - 1]){
                    DP[i] = max(DP[i],DP[j] + 1);
                }
            }
        }
        for(int i = 1; i<=size; i++){
            res = max(res,DP[i]);
        }
        return res;
    }
};