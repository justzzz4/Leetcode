#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//双向广度优先搜索
/*
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if ( words.empty() || words.find(endWord) == words.end() ) return 0;
        words.erase(beginWord);
        queue<string> que;
        que.push(beginWord);
        unordered_set<string> visited;
        visited.insert(beginWord);
        int step = 1;
        while ( !que.empty() ) {
            // 找到没有被访问过, 而且能够由当前单词转换而成的单词
            int n = que.size();
            // 每一轮(每一层step加个1)
            while ( n-- ) {
                string curWord = que.front();
                que.pop();
                // 当前单词的每个字符都替换成其他的25个字符, 然后在单词表中查询
                // 是不是包含转换后的单词
                // 这里千万不能遍历单词表, 因为单词表很长, 而哈希表使用的红黑树
                // 的查询效率比遍历单词表高很多
                for ( int i = 0; i < curWord.size(); ++i ) {
                    char originalChar = curWord[i];
                    for ( int j = 0; j < 26; ++j ) {
                        if ( char('a' + j) == originalChar ) continue;
                        curWord[i] = (char)('a' + j);
                        if ( words.find(curWord) != words.end() && visited.find(curWord) == visited.end() ) {
                            if ( curWord == endWord ) return step + 1;
                            else {
                                que.push(curWord);
                                visited.insert(curWord);
                            }
                        }
                    }
                    curWord[i] = originalChar;
                }
            }
            ++step;
        }
        return 0;
    }
};
*/ 
// 题目中让找的是最短转换序列，深度优先搜索只能找到解，但不是最优解
// 但是广度优先搜索可以找到最优解

// 自己写的深度优先搜索版本，将所有结点都遍历，然后将路径长度加入，超时是必然。
class Solution {
public:
    
    // 写了个深度优先搜索，结果超时了
    int numOfDiff(string a,string b){
        int diff = 0;
        for(int i = 0; i<a.size();i++){
            if(a[i] != b[i])diff++;
        }
        return diff;
    }

    // string a应该是上一个字符串，string b是下一个要跳转的字符串
    bool canPushIntoStack(string a,string b,vector<pair<string,int>>& stack1,vector<pair<string,int>>&stack2){
        if(numOfDiff(a,b) != 1) return false;
        bool canPush = true;
        for(pair<string,int> pair_ : stack1){
            if(pair_.first == b) canPush = false;
        }
        for(pair<string,int> pair_ : stack2){
            if(pair_.first == b) canPush = false;
        }
        return canPush;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(),wordList.end(),endWord) == wordList.end()) return 0;
        vector<pair<string,int>> wordStack;
        vector<pair<string,int>> waste;
        vector<int> length;
        pair<string,int> newPair; newPair.first = beginWord; newPair.second = 0;
        wordStack.push_back(newPair);
        while(wordStack.size() != 0){
            // 将栈顶元素出栈
            pair<string,int> top = *(wordStack.end() - 1);
            if(wordStack.size()!=0) wordStack.pop_back();
            // 加入到出栈队列里面
            waste.push_back(top);
            // 找到答案，将结果保存，出栈
            if(top.first == endWord){
                length.push_back(top.second + 1);
                // 
                if(wordStack.size()!= 0)
                {
                    int length = (*(wordStack.end() - 1)).second;
                    auto it = waste.begin();
                    while(it != waste.end()){
                        if((*it).second >= length) it = waste.erase(it);
                        else{
                            it++;
                        }
                    }
                }
            }
            // 然后遍历字典，将不在两个栈内，且仅仅差一个字母的元素入栈
            bool isAdded = false;
            for(string word : wordList){
                // 如果可以入栈，那么就入栈
                if(canPushIntoStack(top.first,word,wordStack,waste)){
                    pair<string,int> pushPair; 
                    pushPair.first = word;
                    pushPair.second = top.second + 1;
                    // 入栈操作
                    isAdded = true;
                    wordStack.push_back(pushPair);
                }
            }
            // 代表该路径走不通
            if(!isAdded) {
                // 向路径数组中添加0
                length.push_back(0);
                if(wordStack.size()!= 0)
                {
                    int length = (*(wordStack.end() - 1)).second;
                    auto it = waste.begin();
                    while(it != waste.end()){
                        if((*it).second >= length) it = waste.erase(it);
                        else{
                            it++;
                        }
                    }
                }
            }
        }
        int minLength = INT_MAX;
        for(int i : length){
            if(i < minLength && i != 0) minLength = i;
        }
        return(minLength == INT_MAX)?0:minLength;
    }

};

