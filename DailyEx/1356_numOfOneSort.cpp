#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(pair<int,int>a,pair<int,int>b){
        if(a.second != b.second){
            return a.second < b.second;
        }
        else{
            return a.first < b.first;
        }
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<int>twoPow;
        vector<int>ans;
        vector<pair<int,int>> map;
        
        // arr 按升序进行排列
        sort(arr.begin(),arr.end());
        
        // 将各阶乘存入其中
        for(int i = 13; i >=0; i--){
            twoPow.push_back(int(pow(2,i)));
        }
        
        // 记录每个数的1的个数，将映射存入map中
        for(auto &x : arr){
            
            pair<int,int> newPair;
            newPair.first = x;
            newPair.second = 0;
            
            for(int i = 0; i<twoPow.size(); i++){
                if(x >= twoPow[i]){
                    // 1的个数加1，同时减去这个数
                    newPair.second++;
                    x -= twoPow[i];
                }
                if(x == 0) break;
            }
            map.push_back(newPair);
        }
        // 排序
        sort(map.begin(),map.end(),this->cmp);
        // 插入到新数组中
        for(auto & pairinmap:map){
            ans.push_back(pairinmap.first);
        }
        return ans;
    }
};


// 官方题解1：暴力解法
/*
class Solution {
public:
    int get(int x){
        int res = 0;
        while (x) {
            res += (x % 2);
            x /= 2;
        }
        return res;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> bit(10001, 0);
        for (auto x: arr) {
            bit[x] = get(x);
        }
        sort(arr.begin(),arr.end(),[&](int x,int y){
            if (bit[x] < bit[y]) {
                return true;
            }
            if (bit[x] > bit[y]) {
                return false;
            }
            return x < y;
        });
        return arr;
    }
};
*/

// 官方题解2：递推预处理
// 我们定义 bit[i]bit[i] 为数字 ii 二进制表示下数字 1 的个数，则可以列出递推式：

// bit[i] = bit[i>>1] + (i \& 1)
// bit[i]=bit[i>>1]+(i&1)

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/sort-integers-by-the-number-of-1-bits/solution/gen-ju-shu-zi-er-jin-zhi-xia-1-de-shu-mu-pai-xu-by/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
/*
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> bit(10001, 0);
        for (int i = 1;i <= 10000; ++i) {
            bit[i] = bit[i>>1] + (i & 1);
        }

        // 匿名函数 lambdas，lambdas 表达式又称 匿名函数，其构造了一个可以在作用范围内捕获变量的函数对象
        // lambda表达式实际为一个仿函数functor，编译器后会生成一个匿名类（注：这个类重载了（）运算符）
        // [] 表示不捕获任何变量
        // [=] 表示父作用域下的参数进行值传递
        // [&] 表示父作用域下的参数进行引用传递
        // [this] 通过引用捕获当前对象
        // [*this] 通过传值方式捕获当前对象
        // 省略returnType的情况：
        // 1、返回值为void类型 2、可以根据declType推断出返回值类型
        // 常量引用，如果用一个具体的数字（不是左值）初始化引用，那么这个引用应该是一个常引用
        // 指针常量：指针的值不变。
        // 常量指针：指针所指向的内容不能改变，但是指针的值可以改变。
        sort(arr.begin(),arr.end(),[&](int x,int y){
            if (bit[x] < bit[y]) {
                return true;
            }
            if (bit[x] > bit[y]) {
                return false;
            }
            return x < y;
        });
        return arr;
    }
};
复杂度分析

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/sort-integers-by-the-number-of-1-bits/solution/gen-ju-shu-zi-er-jin-zhi-xia-1-de-shu-mu-pai-xu-by/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/ 
