#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


// 我觉得这道题似乎有点小题大做。。
// 只是简单地对各个数字进行计数感觉没必要采用unordered_map 

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {

        if (nums.size() == 1 || nums.size() == 0)
            return;

        //利用哈希表，将元素存放其中
        unordered_map<int, int> map;
        for (int i : nums)
        {
            auto it = map.find(i);
            if (it == map.end())
            {
                // 如果哈希表中没有则存入
                map.emplace(i, 1);
            }
            else
            {
                // 如果已经存在元素则次数(value)+1
                (*it).second++;
            }
        }

        if (map.size() == 1)
            return;
        else
        {
            nums.clear();
            for (int i = 0; i <= 2; i++)
            {
                auto it = map.find(i);
                if (it != map.end())
                {
                    for (int i = 0; i < (*it).second; i++)
                        nums.push_back((*it).first);
                }
            }
        }
    }
};