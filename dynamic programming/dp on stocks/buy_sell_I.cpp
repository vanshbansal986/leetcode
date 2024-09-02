#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<unordered_set>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int min_buy = prices[0];
    int max_prof = 0;
    
    for(int i=1; i<n; i++){
        max_prof = max(max_prof , prices[i]-min_buy);
        min_buy = min(min_buy , prices[i]);
    }
    
    return max_prof;
}