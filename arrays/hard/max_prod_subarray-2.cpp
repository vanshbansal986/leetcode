// https://leetcode.com/problems/maximum-product-subarray/description/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


int maxProduct(vector<int>& nums){
    int n = nums.size();
    int max_prod = INT_MIN;
    int pref = 1;

    for(int i=0; i<n; i++){
        pref = pref * nums[i];
        max_prod = max(pref , max_prod);
        
        if(pref == 0){
            pref = 1;
        }
    }
    int suff = 1;
    for(int i=n-1; i>=0; i--){
        suff = suff * nums[i];
        max_prod = max(suff , max_prod);
        
        if(suff == 0){
            suff = 1;
        } 

    }

    return max_prod;

}

int main(){

}

