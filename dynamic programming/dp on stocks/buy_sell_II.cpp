#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<unordered_set>
using namespace std;

int helper(int i , bool can_buy , vector<int>& prices , vector<vector<bool>> dp){
    if(i == prices.size()){
        return 0;
    }

    if(dp[i][can_buy] != -1){
        return dp[i][can_buy];
    }

    int profit = 0;
    // This means we have the option to buy or not buy the stock at this index
    if(can_buy == 1){
        int buy = helper(i+1 , 0 , prices , dp) - prices[i];

        int not_buy = helper(i+1 , 1 , prices , dp) - 0;

        profit = max(buy , not_buy);
    }
    else{
        int sell = helper(i+1 , 1 , prices , dp) + prices[i];

        int not_sell = helper(i+1 , 0 , prices , dp) + 0;

        profit = max(sell , not_sell);
    }

    return dp[i][can_buy] = profit;
}

int maxProfit_greedy(vector<int>& prices){

    int n = prices.size();

    if(n < 2){
        return 0;
    }

    int min_buy = prices[0];
    int max_prof = 0;
    int max_sell = prices[1];
    
    for(int i=1; i<n; i++){

        if(prices[i] < max_sell){
            max_prof += (max_sell - min_buy);
            
            min_buy = prices[i];
            max_sell = prices[i];
        }
        else{
            min_buy = min(min_buy , prices[i]);
            max_sell = max(max_sell,prices[i]);
        }
    }

    if(max_sell > min_buy){
        max_prof += max_sell - min_buy;
    }

    return max_prof;
}