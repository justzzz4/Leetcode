#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> Jewels;
        for(int i = 0; i < J.size(); i++) {
            char c = J[i];
            Jewels.insert(c);
        }
        int sum = 0;
        for(int i = 0; i < S.size();i++){
            if(Jewels.count(S[i])) sum++;
        }
         return sum;
    }
};