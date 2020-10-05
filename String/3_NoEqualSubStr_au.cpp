#include <iostream>
#include <string>
#include <vector>
using namespace std;

//该题是字符串处理中的滑动窗口，窗口左边依次向右滑动一格，窗口的右端从上次
// end的地方开始向右扩展窗口，从而避免了许多子串的重复判断。
// 也就是 从k开始到Rk位置的字符串，当Rk+1与前面字符串重复时
// k+1 到 Rk的子串一定是无重复的子串，那么就可以直接与Rk + 1进行判断。 

class Solution
{
public:
	vector<char> substr;
	int lengthOfLongestSubstring(string s)
	{
		if(s.size() <= 1) return s.size();
		int maxsize = 0; int begin = 0; int end = 0;
		for (int j = 0; j < s.size() - 1; j++)
		{
			// 定义开始位置，开始位置依次加一，即滑动窗口左侧依次向右滑动一位
			begin = j;
			
			
            // 当子串序列为空时，向子串序列里添加字符
			if (substr.size() == 0) substr.push_back(s[begin]);
            if (begin > end) end = begin;

			for (int i = end + 1; i < s.size(); i++)
			{
				// substr中没有重复字母
				if (find(substr.begin(), substr.end(), s[i]) == substr.end())
				{
					end++;
					substr.push_back(s[i]);
					// 如果字符串到达末尾，再判断一次
					if (i == s.size() - 1) {
						int size = end - begin + 1;
						maxsize = size > maxsize ? size : maxsize;
					}
				}
				else
				{
					int size = end - begin + 1;
					maxsize = size > maxsize ? size : maxsize;
					// 删除开头第一个元素
					if (substr.size() != 0) substr.erase(substr.begin());
					break;
				}
			}

		}
		return maxsize;
	}
};


