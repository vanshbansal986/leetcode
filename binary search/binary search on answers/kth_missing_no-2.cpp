#include<iostream>
#include<vector>
#include <cmath>
using namespace std;



int helper(vector<int> nums , int k , int start , int end){
    if(start > end){
        return -1;
    }

    int mid = start + (end - start)/2;
    int missing = nums[mid] - mid - 1;

    if(missing == k){
        return mid;
    }
    else if(missing < k){
        return helper(nums,k,mid+1,end);
    }
    else{
        return mid + k;
    }
}

int binary_search(vector<int> nums , int k){

    int n = nums.size();
    return helper(nums,k,0,n-1);
}


int main(){
    // shipWithinDays
    return 0;
}