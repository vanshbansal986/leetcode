#include<iostream>
#include<vector>
using namespace std;

int helper(vector<int> nums , int start , int end){
    // base case
    if(start == end){
        return start;
    }
    if(start > end){
        return -1;
    }

    int mid = start + (end - start)/2;

    if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
        return nums[mid];
    }
    else if(nums[mid] == nums[mid-1]){
        int len = (mid - 1 - start);
        
        if(len % 2 == 0){
            return helper(nums , mid+1 , end);
        }
        else{
            return helper(nums , start , mid-2);
        }
    }
    else if(nums[mid] == nums[mid+1]){
        int len = end - (mid+1);
        
        if(len % 2 == 0){
            return helper(nums , start , mid-1);
        }
        else{
            return helper(nums , mid+2 , end);
        }
    }

    return -1;


}

int binary_search(vector<int> nums , int target){
    
    int n = nums.size();
    
    return helper(nums,0,n-1);


}


int main(){
    return 0;
}