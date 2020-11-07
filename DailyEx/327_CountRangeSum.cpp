#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if(nums.size() == 0) return 0;
        int size = nums.size();
        int* arr = new int[size]();
        int ans = 0;
        for(int i =0; i<size; i++){
            arr[i] = nums[i];
        }
        for(int i =0; i<size; i++){
            long int sum = 0;
            for(int j=i; j<size; j++){
                sum += arr[j];
                if(sum >= lower && sum <= upper) ans++;
            }
        }
        return ans;
    }
};

/*
    官方题解：归并排序
    前缀和数组 preSum

*/