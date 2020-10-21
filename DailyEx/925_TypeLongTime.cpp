#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    // 思路还是不清晰，返回True的条件没搞对
    // 一定要所有name中的所有字符都匹配且中间没有其他字符才可以的
    bool isLongPressedName(string name, string typed) {
        char lastChar; int ptr = 0;
        for(int i = 0; i < typed.size(); i++){
            if(i == 0 && typed[0] != name[0]) return false;
            
            if(typed[i] == name[ptr]){
                lastChar = name[ptr];
                ptr++;
            }
            
            if(ptr < name.size()){
                if(typed[i] != name[ptr]){
                    if(typed[i] != lastChar) return false;
                }
            }
            else{
                if(typed[i] != lastChar) return false;
            }
        }
        if(ptr < name.size()) return false;
        else return true;
    }
};