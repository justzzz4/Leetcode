#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int low = 0; int high = nums.size()-1;
        if(nums[low] == 1) return 0;
        if(nums[high] == high) return high+1;
        while(low <= high){
            int mid = low+high/2;
            // 索引值小于所对应的值，说明第一部分数组在前面
            if( mid != nums[mid]) high = mid -1;
            else { low = mid +1;}
        }
        return low;
    }
};