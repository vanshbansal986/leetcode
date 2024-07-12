#include<iostream>
#include<vector>
#include <cmath>
using namespace std;



int helper(vector<int> nums , int m , int start , int end){
    int n = nums.size();
    if(start >= end){
        return start;
    }

    int mid = start + (end - start)/2;
    int students = 1;
    int sum = 0;

    for(int i=0; i<n; i++){
        
        if(sum + nums[i] > mid){
            students++;
            sum = nums[i];
        }
        else{
            sum += nums[i];
        }
    }

    if(students > m){
        return helper(nums,m , mid+1 , end);
    }
    else{
        return helper(nums,m , start , mid);
    }
}

int binary_search(vector<int> nums , int m){
    int n = nums.size();
    int max = 0;
    int sum = 0;

    for(int i=0; i<n; i++){
        sum += nums[i];
        if(nums[i] > max){
            max = nums[i];
        }
    }


    return helper(nums,m,max,sum);
}


int main(){
    // shipWithinDays
    return 0;
}

