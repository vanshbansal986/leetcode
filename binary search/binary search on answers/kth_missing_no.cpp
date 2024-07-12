#include<iostream>
#include<vector>
#include <cmath>
using namespace std;



int helper(int n , int start , int end){
    
}

int binary_search(vector<int> nums , int k){

    int n = nums.size();
    int elem = -1;
    int sum = 0;

    for(int i=1; i<n; i++){
        int mini = nums[i] - nums[i-1] - 1;
        sum += mini;

        if(sum >= k){
            elem = nums[i] + k - 1; 
        }
    }
    if(elem == -1){
        elem = nums[n-1] + k - sum;
    }

    return elem;
}


int main(){
    // shipWithinDays
    return 0;
}

class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int n = nums.size();
        int elem = -1;
        int sum = 0;
        if(nums[0] != 1){
            sum = nums[0] - 1;
        }

        for(int i=1; i<n; i++){
            int mini = nums[i] - nums[i-1] - 1;
            sum += mini;

            if(sum >= k){
                elem = nums[i] + k - 1-sum; 
                break;
            }
        }

        // if(elem == -1 && n == 1){
        //     elem = nums[n-1] + k - sum - 1;
        // }
        if(elem == -1){
            elem = nums[n-1] + k - sum;
        }
        

        return elem;
    }
};