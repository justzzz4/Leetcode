#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
    if(A.size() == 0) return A;
    if(A.size() == 0) return A;
    int a[26] = {0};
    
    // 第一个数组出现各字母次数
    for(int i = 0 ; i < A[0].size();i++){
        a[A[0][i] - 'a']++;
    }
    
    int a_[26] = {0};

    for(int i = 1 ; i< A.size();i++){
        
        // 从A中第二个字符串开始遍历
        for(int j = 0; j < A[i].size() ; j++){
            a_[A[i][j] - 'a']++;
        }
        // 更新两个数组，将数组中的较小值放入a中
        for(int j = 0 ;j<26;j++){
            if(a[j] > a_[j]){
                a[j] = a_[j];
            }
        }

        // 将a_数组重新归零
        for(int j = 0 ; j < 26;j++){
            a_[j] = 0;
        }
    }
    
    // 处理输出
    vector<string>ans;
    string alphabet[26] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
    for(int i = 0 ; i < 26 ;i++){
        for(int j = 0 ; j < a[i]; j++){
            ans.push_back(alphabet[i]);
        }
    }
    return ans;
    }
};

/*
=================================================================
==42==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x602000000071 at pc 0x0000002ec4f9 bp 0x7ffd4170ebb0 sp 0x7ffd4170e370
READ of size 2 at 0x602000000071 thread T0
    #6 0x7fc5187fa0b2  (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
0x602000000071 is located 0 bytes to the right of 1-byte region [0x602000000070,0x602000000071)
allocated by thread T0 here:
    #4 0x7fc5187fa0b2  (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
Shadow bytes around the buggy address:
  0x0c047fff7fb0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7fc0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7fd0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7fe0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7ff0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x0c047fff8000: fa fa fd fa fa fa fd fa fa fa fd fa fa fa[01]fa
  0x0c047fff8010: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8020: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8030: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8040: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8050: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07 
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
  Shadow gap:              cc
==42==ABORTING
*/