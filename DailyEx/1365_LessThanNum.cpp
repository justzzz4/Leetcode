#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        if(nums.size() == 0) return nums;
        vector<int> ans;
        for(int i = 0 ; i < nums.size() ; i++){
            // 表示元素的值
            int ele = nums[i];
            int times = 0;
            for (int j = 0 ; j< nums.size() ; j++){
                if(nums[j] < ele) times++; 
            }
            ans.push_back(times);
        }
        return ans;
    }
};

/*

2、对原数据进行排序，并保存元素原来所在位置，并返回第一个比该元素小的元素下标
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<pair<int, int>> data;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            data.emplace_back(nums[i], i);
        }
        sort(data.begin(), data.end());

        vector<int> ret(n, 0);
        int prev = -1;
        for (int i = 0; i < n; i++) {
            if (prev == -1 || data[i].first != data[i - 1].first) {
                prev = i;
            }
            ret[data[i].second] = prev;
        }
        return ret;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/how-many-numbers-are-smaller-than-the-current-number/solution/you-duo-shao-xiao-yu-dang-qian-shu-zi-de-shu-zi--2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/