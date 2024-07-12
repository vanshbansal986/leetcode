#include<iostream>
#include<vector>
using namespace std;

int helper(vector<int> nums , int target , int start , int end){
    // base case
    if(start > end){
        return -1;
    }

    int mid = start + (end - start)/2;

    if(nums[mid] == target){
        return mid;
    }
    else if(nums[mid] > nums[end]){
        return helper(nums,target,mid+1,end);
    }
    else{
        return helper(nums,target,start,mid-1);
    }

}

int binary_search(vector<int> nums , int target){
    
    int n = nums.size();
    
    return helper(nums,target,0,n-1);


}


int main(){
    return 0;
}