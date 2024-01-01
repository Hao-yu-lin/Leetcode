/*
題目：
https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/

解說：
解法1：
已知字串長度為偶數
若 b 是偶數，無論怎麼 rotate，每次 add 操作總是作用在所有的奇數位上。
若 b 是奇數，當 rotate 一次後，add 的操作的作用改為偶數位上，再一次 rotate 後， add 的操作回到原本的奇數位上。
rotate 只影響數字排列，而不影響數值大小。

當 b 是奇數時，可以透過多次 rotate 操作，將所有奇數位與所有偶數位加上任意數值

數值大小只取決於做了幾次 add，add 的次數最多為 10 次，add a*10 與 add a，這兩個操作基本上是一樣
rotate 的次數最多 n 次，因為 rotate by b 和 rotate by n*b 的效果是一樣的
更高效的方法總共需要 rotate 的次數是 n/gcd(n,b)




有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
    int gcd(int a, int b)
    {
        return b > 0 ? gcd(b, a%b) : a;
    }

public:
    string findLexSmallestString(string s, int a, int b) 
    {
        string ans = s;
        int n = s.size();

        for(int i = 0; i < 10; i++)
            for(int j = 0; j < 10; j++)
            {
                string t = s;
                if(b%2 == 1)
                {
                    for(int k = 0; k < n; k+=2)
                        t[k] = (t[k]-'0'+a*i)%10 + '0';
                }
                for(int k = 1; k < n; k+=2)
                    t[k] = (t[k]-'0'+a*j)%10 + '0';
                
                string p = t;
                for(int k = 0; k <= n/gcd(n,b); k++)
                {
                    p = p.substr(n-b) + p.substr(0, n-b);
                    ans = min(ans, p);
                }
            }

        return ans;
    }
};