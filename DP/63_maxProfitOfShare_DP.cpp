#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int size = prices.size();
        if (size == 0) return 0;
        int res = 0;
        int mini = prices[0];
        
        for (int i = 1; i < size; i++)
        {
            res = max(res, (prices[i] - mini));
            mini = min(mini, prices[i]);
        }
        return res;
    }
};