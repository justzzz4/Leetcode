#include <iostream>
#include <vector>
using namespace std;

// 简单思路为遍历两个数组合并成一个，然后返回中位数，复杂度为 m+n
// 或者不合并，维护两个指针即可

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int size = nums1.size() + nums2.size();
        int mid = (nums1.size() + nums2.size()) / 2;

        // 特殊情况：当有数组为空时
        if(nums1.size() == 0 || nums2.size() ==0 ){
            if(nums1.size() == 0 && nums2.size() == 0){
                return 0;
            }
            if(nums1.size() == 0){
                // nums2 
                if(nums2.size() == 1) return nums2[0];
                if(size % 2 == 0) return (nums2[mid - 1] +nums2[mid]) /2.0;
                else return (nums2[mid]);
            }
            if(nums2.size() == 0){
                // nums1
                if(nums1.size() == 1) return nums1[0];
                if(size % 2 == 0) return (nums1[mid - 1] +nums1[mid]) /2.0;
                else return (nums1[mid]);
            }
        }
        
        // 奇数对应的指针为 mid 偶数对应的指针为 mid - 1 和 mid
        int ptr1 = 0;
        int ptr2 = 0;
        double mid_1;
        for (int i = 0; i < mid; i++)
        {
            if (ptr1 < nums1.size() && ptr2 < nums2.size())
            {
                // 如果两个数组都没有到末尾
                if (nums1[ptr1] < nums2[ptr2])
                {
                    mid_1 = nums1[ptr1];
                    ptr1++;
                }
                else
                {
                    mid_1 = nums2[ptr2];
                    ptr2++;
                }
            }
            else
            {
                if (ptr1 >= nums1.size())
                {
                    mid_1 = nums2[ptr2];
                    ptr2++;
                }
                if (ptr2 >= nums2.size())
                {
                    mid_1 = nums1[ptr1];
                    ptr1++;
                }
            }
        }
        double mid_0;
        if (ptr1 < nums1.size() && ptr2 < nums2.size()) mid_0 = nums1[ptr1] < nums2[ptr2]?nums1[ptr1]:nums2[ptr2];
        else {
            if (ptr1 >= nums1.size())
                {
                    mid_0 = nums2[ptr2];
                }
                if (ptr2 >= nums2.size())
                {
                    mid_0 = nums1[ptr1];
                }
        }
        if(size % 2 == 0) return (mid_1 + mid_0) /2.0;
        else return (mid_0);
    }
};
