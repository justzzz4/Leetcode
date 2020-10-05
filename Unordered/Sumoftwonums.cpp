#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    //    可以避免x和自己匹配
    //  hashtable 有 key value find方法查询的是Key
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int,int> hashtable;
      for(int i = 0 ; i < nums.size();i++){
          auto it = hashtable.find(target - nums[i]);
          if(it != hashtable.end()){
              return {it->second,i};
          }
          hashtable[nums[i]] = i;
      }
      return{};
    }

};