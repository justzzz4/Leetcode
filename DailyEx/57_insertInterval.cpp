#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        // 将新区间插入
        bool hasInserted = false;
        for (auto it = intervals.begin(); it != intervals.end(); it++)
        {
            if (newInterval[0] <= (*it)[0])
            {
                intervals.insert(it, newInterval);
                hasInserted = true;
                break;
            }
        }
        if(!hasInserted) intervals.push_back(newInterval);

        // 下一段代码是应对newInterval包含Intervals中任何区间的一种特殊情况
        if(newInterval[0] <= intervals[0][0] && newInterval[1] >= (*(intervals.end() -1))[1]){
            intervals.clear();
            intervals.push_back(newInterval);
        }

        // 对重叠区间合并
        auto it = intervals.begin();
        while (it != intervals.end() - 1)
        {
            if ((*it)[1] >= (*(it + 1))[0])
            {
                int a = (*it)[1];
                int b = (*(it + 1))[1];
                if (a >= b)
                {
                    // 如果前区间后端点大于后区间后端点，说明后区间是前区间的子集
                    // 在删除后面这个区间之后，指针保持不变
                    intervals.erase(it + 1);
                }
                else
                {
                    // 如果不是包含关系，那么就删除后区间，并拓展原区间的后端点
                    (*it)[1] = b;
                    intervals.erase(it + 1);
                }
            }
            else
            {
                it++;
            }
        }
        return intervals;
    }
};
