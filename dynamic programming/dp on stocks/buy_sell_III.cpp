#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<unordered_set>
using namespace std;

int helper(int i , bool can_buy , int count , vector<int>& prices , vector<vector<vector<int>>> &dp){
    if(i == prices.size()){
        return 0;
    }

    if(count > 4){
        return 0;
    }

    if(dp[i][can_buy][count] != -1){
        return dp[i][can_buy][count];
    }

    int profit = 0;
    // This means we have the option to buy or not buy the stock at this index
    if(can_buy == 1){
        int buy = helper(i+1 , 0 , count+1, prices , dp) - prices[i];

        int not_buy = helper(i+1 , 1 , count , prices , dp) - 0;

        profit = max(buy , not_buy);
    }
    // This means we have to sell before buying (we have already bought)
    else{
        int sell = helper(i+1 , 1 , count+1 , prices , dp) + prices[i];

        int not_sell = helper(i+1 , 0 , count , prices , dp) + 0;

        profit = max(sell , not_sell);
    }

    return dp[i][can_buy][count] = profit;
}

int tabular(vector<int> prices){
    int n = prices.size();

    vector<vector<vector<int>>> dp(n+1 , vector<vector<int>>(3 , vector<int>(5 , 0)));

    for(int i = n-1; i>=0; i--){
        for(int can_buy = 0; can_buy <= 1; can_buy++){
            for(int count = 3; count>=0; count--){
                int profit = 0;
                // This means we have the option to buy or not buy the stock at this index
                if(can_buy == 1){
                    int buy = dp[i+1][0][count+1] - prices[i];

                    int not_buy = dp[i+1][1][count];

                    profit = max(buy , not_buy);
                }
                // This means we have to sell before buying (we have already bought)
                else{
                    int sell = dp[i+1][1][count+1] + prices[i]; 

                    int not_sell = dp[i+1][0][count];

                    profit = max(sell , not_sell);
                }

                dp[i][can_buy][count] = profit;
            }
        }
    }

    return dp[0][1][0];
}



int maxProfit(vector<int> prices){
    int n = prices.size();

    vector<vector<vector<int>>> dp(n+1 , vector<vector<int>>(3 , vector<int>(5 , -1)));

    return helper(0,1,0,prices,dp);
}