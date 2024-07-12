// https://leetcode.com/problems/maximum-product-subarray/description/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


int maxProduct(vector<int>& nums){
    int n = nums.size();
    int first_neg = 0;
    int last_neg = 0;
    int count = 0;
    
    for(int i=0; i<n; i++){
        if(nums[i] <= 0 && count == 0){
            first_neg = i;
            last_neg = i;
            count++;
        }
        else if(nums[i] <= 0 && count != 0){
            last_neg = i;
            count++;
        }
    }

    
    
    if(count %2 == 0){
        int prod = 1;
        for(int i=0; i<n; i++){
            prod = prod * nums[i];
            
            return prod;
        }
    }
    else{
        int prod1 = 0;
        int prod2 = 0;

        for(int i=0; i<last_neg; i++){
            prod1 = prod1 * nums[i];
        }

        for(int i=first_neg+1; i<n; i++){
            prod2 = prod2 * nums[i];
        }
        
        return max(prod1,prod2);
    }


}

int main(){

}

