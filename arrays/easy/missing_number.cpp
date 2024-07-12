//https://leetcode.com/problems/missing-number/

#include<iostream>
#include<vector>
using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int sum = (n)*(n+1)*0.5;
    int arr_sum = 0;
    
    for(int i=0; i<n; i++){
        arr_sum += nums[i];
    }
    
    return sum - arr_sum;
        
}

int main(){

}