/*
題目：
https://www.hackerrank.com/challenges/fraudulent-activity-notifications/problem

解說：
因為 expenditure 範圍只有 0 ~ 200 因此使用一個 dp 紀錄每一個數字出現的次數
藉此來尋找 median

有使用到的觀念：

*/

#include "../code_function.h"

/*
 * Complete the 'activityNotifications' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY expenditure
 *  2. INTEGER d
 */
vector<int> dp(201, 0);
bool findmed(int d, int exp)
{
    int count = 0;
    int pos = 0;
    int median;
    if(d % 2 == 1)
    {
        while(pos < 201 && count < (d+1)/2)
        {
            count += dp[pos];
            pos++;
        }
        median = 2*(pos-1);
    }else 
    {   
        while(pos < 201 && count < (d+1)/2)
        {
            count+= dp[pos];
            pos++;
        }
        median = pos-1;
        
        if(count > (d+1)/2) median += pos-1;
        else{
            while(pos < 201 && count < (d+1)/2 + 1)
            {
                count += dp[pos];
                pos++;
            }
            median += pos-1;
        }
    }
    
    return exp >= median;
}

int activityNotifications(vector<int> expenditure, int d) 
{
    int notice = 0;
    for(int i = 0; i < expenditure.size(); i++)
    {
        if(i >= d){ 
            if(i>d)dp[expenditure[i-d-1]]--;
            if(findmed(d, expenditure[i])) notice++;
        }
        
        dp[expenditure[i]]++;
    }
    
    return notice;
}