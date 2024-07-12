#include<iostream>
#include<vector>
#include <cmath>
using namespace std;

int sumByD(vector<int> &arr, int div) {
    int n = arr.size(); //size of array
    //Find the summation of division values:

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ceil((double)(arr[i]) / (double)(div));
    }
    
    return sum;
}

int helper(vector<int> nums , int bouqets , int flowers , int start , int end){
    int n = nums.size();
    if(start >= end && bouqets > 0){
        return -1;
    }
    
    if(start >= end && bouqets == 0){
        return start;
    }

    int mid = start + (end - start)/2;

    
    for(int i=0; i<n; i++){
        if(nums[i] <= mid){
            flowers--;
        }
        else{
            break;
        }
    }
    
    if(flowers == 0){
        return helper(nums , bouqets-- , flowers , start , mid-1);
    }
    else{
        return helper(nums , bouqets , flowers , mid+1 , end);
    }

    
}

int binary_search(vector<int> nums , int target){
    
    int n = nums.size();

    int low = 1;
    int high = *max_element(nums.begin(),nums.end());


    //return helper(nums,target,low,high);


}


int main(){
    return 0;
}