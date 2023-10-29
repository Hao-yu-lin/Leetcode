/*
題目：
https://leetcode.com/problems/count-vowels-permutation/

解說：
解法一
下方是可以組成的型態
ae
ea、ei
ia、ie、io、iu 
oi、ou
ua

下方代表著，由哪一個字母接續，比方說尾巴要接 a ，則前面必須是 e, i, u，因此 a 的組合為前一個字母是 e, i, u 的總和
a -> e + i + u;
e -> a + i;
i -> e + o;
o -> i;
u -> i + o;

解法二使用到矩陣相乘

ANS = M(n-1) * [1, 1, 1, 1, 1]t
其中有用到 fast power 演算法

有使用到的觀念：
DP
*/

#include "../code_function.h"

class Solution1 {
public:
    int countVowelPermutation(int n) 
    {
        constexpr int kMod = 1e9 + 7;
        long a = 1, e = 1, i = 1, o = 1, u = 1;

        for(int k = 2; k <= n; k++)
        {
            long aa = (i+e+u) % kMod;
            long ee = (i+a) % kMod;
            long ii = (e+o) % kMod;
            long oo = i % kMod;
            long uu = (i+o) % kMod;

            a = aa;
            e = ee;
            i = ii;
            o = oo;
            u = uu;
        }

        return (a+e+i+o+u)%kMod;
        
    }
};


class Solution2 {
public:
    int kMod = 1e9 + 7;
    vector<vector<long>> fast_pow(const vector<vector<long>>& A, const vector<vector<long>>& B)
    {
        int m = A.size();
        int x = A[0].size();
        int n = B[0].size();
        vector<vector<long>> C(m, vector<long>(n));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                for(int k = 0; k < x; k++)
                    C[i][j] += A[i][k] * B[k][j];
                C[i][j] %= kMod;
            }
        return C;
    }

    int countVowelPermutation(int n) 
    {
        vector<vector<long>> m{
            {0, 1, 0, 0, 0}, // a
            {1, 0, 1, 0, 0}, // e
            {1, 1, 0, 1, 1}, // i
            {0, 0, 1, 0, 1}, // o
            {1, 0, 0, 0, 0} // u
        };

        vector<vector<long>> ans{{1}, {1}, {1}, {1}, {1}};

        n--;
        // fast_pow
        while(n > 0){
            if(n % 2) ans = fast_pow(m, ans);
            m = fast_pow(m, m);
            n /= 2;
        }

        long sum = 0;
        for(int i = 0; i < 5; i++)
            sum += ans[i][0];
        return sum % kMod;
    }
};