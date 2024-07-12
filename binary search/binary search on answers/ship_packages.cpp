#include<iostream>
#include<vector>
#include <cmath>
using namespace std;



int helper(vector<int> nums , int days , int start , int end){
    int n = nums.size();
    if(start > end){
        return start;
    }

    int mid = start + (end - start)/2;
    int weight = 0;
    int curr_days = 0;

    int i = 0;
    while(i<n){

        weight += nums[i];

        if(weight > mid){
            weight = 0;
            curr_days++;
        }
        else if(weight == 0){
            weight = 0;
            curr_days++;
            i++;
        }
        else{
            i++;
        }

    }
    if(weight > 0){
        curr_days++;
    }

    if(curr_days <= days){
        return helper(nums,days,start,mid-1);
    }
    else{
        return helper(nums , days , mid+1 , end);
    }

    
}

int binary_search(vector<int> nums , int target){
    
    int n = nums.size();

    int low = 1;
    int high = 0;
    for(int i=0; i<n; i++){
        high += nums[i];
    }


    return helper(nums,target,low,high);


}


int main(){
    // shipWithinDays
    return 0;
}