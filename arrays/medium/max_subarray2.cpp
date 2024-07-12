// https://leetcode.com/problems/maximum-subarray/description/

#include<iostream>
#include<vector>
using namespace std;


int max_subarray(vector<int> nums){
    int n = nums.size();

    int maxSum = nums[0];
    int sum = 0;

    for(int i=0; i<n; i++){
        sum = sum + nums[i];
        maxSum = max(sum,maxSum);

        if(sum<0){
            sum = 0;
        }

        
    }
}

int main(){
    return 0;
}