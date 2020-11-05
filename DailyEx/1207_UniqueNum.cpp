#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> map;
        unordered_set<int> set;
        for(int i = 0; i< arr.size(); i++){
            auto it = map.find(arr[i]);
            if(it == map.end()){
                map.emplace(arr[i],1);
            }
            else{
                it->second ++;
            }
        }
        for(auto it = map.begin(); it != map.end(); it++){
            if(set.count(it->second) == 0)set.emplace(it->second);
            else {
                return false;
            }
        }
        return true;
    }
};