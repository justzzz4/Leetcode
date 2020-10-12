#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	
	// 将vector数组中的前几号元素删除
	void DeleteintInArray(vector<int>& nums, int size_)
	{
		for (int i = 0; i < size_; i++)
		{
			auto it = nums.begin();
			nums.erase(it);
		}
	}

	double getKElement(vector<int> nums1, vector<int> nums2, int k_)
	{
		// 1、确定k值，选择出 k/2 -1 数
		int k = k_;

		int ptr = k / 2 - 1;

		// 对应有空数组情况
		if (nums1.size() == 0 || nums2.size() == 0)
		{
			if (nums1.size() == 0)
			{
				return nums2[k - 1];
			}
			if (nums2.size() == 0)
			{
				return nums1[k - 1];
			}
		}

		// 如果 k = 1，那么返回两个数组首元素较小值
		if (k == 1)
		{
			return (nums1[0] < nums2[0] ? nums1[0] : nums2[0]);
		}

		int mid1;
		int mid2;
		int minus;
		// 指针越界情况处理
		if (ptr >= nums1.size() || ptr >= nums2.size())
		{
			if (ptr >= nums1.size())
			{
				mid1 = nums1[nums1.size() - 1];
				mid2 = nums2[ptr];
				if (mid1 <= mid2)
				{
					minus = nums1.size();
					DeleteintInArray(nums1, minus);
				}
				else
				{
					minus = k / 2;
					DeleteintInArray(nums2, minus);
				}
			}
			if (ptr >= nums2.size())
			{
				mid1 = nums1[ptr];
				mid2 = nums2[nums2.size() - 1];
				// minus = (mid1 <= mid2)? k/2 : nums2.size();
				if (mid1 <= mid2)
				{
					minus = k / 2;
					DeleteintInArray(nums1, minus);
				}
				else
				{
					minus = nums2.size();
					DeleteintInArray(nums2, minus);
				}
			}

			k = k - minus;
			return getKElement(nums1, nums2, k);
		}

		else
			// 如果不越界，取两个数组下标为 k/2 - 1 的元素
		{
			mid1 = nums1[ptr];
			mid2 = nums2[ptr];
			minus = k / 2;

			// 对取出元素进行比较,对数组的元素进行删减
			if (mid1 <= mid2)
				DeleteintInArray(nums1, minus);
			else
				DeleteintInArray(nums2, minus);

			k = k - minus;
			return getKElement(nums1, nums2, k);
		}
	}

	double findMedianSortedArrays(vector<int> & nums1, vector<int> & nums2)
	{
		int k;
		if ((nums1.size() + nums2.size()) % 2 == 0)
		{
			k = (nums1.size() + nums2.size()) / 2;
			return (getKElement(nums1, nums2, k) + getKElement(nums1, nums2, k + 1)) / 2.0;
		}
		else
		{
			k = (nums1.size() + nums2.size() + 1) / 2;
			return getKElement(nums1, nums2, k);
		}
	}
};
