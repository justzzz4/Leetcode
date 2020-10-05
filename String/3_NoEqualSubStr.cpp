#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<char> substr;
    int lengthOfLongestSubstring(string s)
    {
        if(s.size() == 0) return 0;
        if(s.size() == 1) return 1;
        int maxsize = 0;
        for (int j = 0; j < s.size() - 1; j++)
        {   
            // 定义起始位置
            int begin = j;
            int end = j;
            substr.push_back(s[j]);
            for (int i = j+1; i < s.size(); i++)
            {
                // substr中没有重复字母
                auto it = find(substr.begin(),substr.end(),s[i]);
                if ( it == substr.end() )
                {
                    end++;
                    substr.push_back(s[i]);
                    // 如果字符串到达末尾，再判断一次
                    if(i == s.size()-1){
                        int size = end - begin + 1;
                        maxsize = size > maxsize ? size : maxsize;
                    }
                }
                else
                {
                    int size = end - begin + 1;
                    maxsize = size > maxsize ? size : maxsize;
                    substr.clear();
                    break;
                }
            }
            
        }
        return maxsize;
    }
};

