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

int helper(vector<int> nums , int h , int start , int end){
    int n = nums.size();
    if(start >= end){
        return start;
    }

    int mid = start + (end - start)/2;

    int sum = sumByD(nums,mid);

    if(sum > h){
        return helper(nums,h,mid+1,end);
    }
    else{
        return helper(nums,h,start,mid-1);
    }
    
}

int binary_search(vector<int> nums , int target){
    
    int n = nums.size();

    int low = 1;
    int high = *max_element(nums.begin(),nums.end());


    return helper(nums,target,low,high);


}


int main(){
    return 0;
}