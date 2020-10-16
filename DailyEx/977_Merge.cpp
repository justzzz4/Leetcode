#include<iostream>
#include<vector>
using namespace std;

// 根据负数的平方降序排列，非负数的平方升序排列，得出两个数组，再对两个数组进行归并

class Solution {
public:
	vector<int> sortedSquares(vector<int>& A) {
		// partion表示最后一个负数的下标
		int partion = -1;
		for (int i = 0; i < A.size();i++) {
			int num = A[i];
			if (num < 0) partion++;
			A[i] = num * num;
		}
		int Posi = partion + 1;
		vector<int>ans;
		// 对两个数组迭代
		while (partion >= 0 && Posi < A.size()) {
			if (A[partion] < A[Posi]) {
				ans.push_back(A[partion]);
				partion--;
			}
			else {
				ans.push_back(A[Posi]);
				Posi++;
			}
		}
		while (partion >= 0) {
			ans.push_back(A[partion]);
			partion--;
		}
		while (Posi < A.size()) {
			ans.push_back(A[Posi]);
			Posi++;
		}
		return ans;
	}
};