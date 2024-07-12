#include<iostream>
#include<vector>
using namespace std;

int helper(vector<int> nums , int target , int start , int end){
    // base case
    if(start > end){
        return INT_MAX;
    }

    int mid = start + (end-start)/2;

    int min_elem = INT_MAX;

    // if this is true, it means left half is sorted in inc order
    if(nums[mid] >= nums[start]){
        // since left half is sorted , the min elem from left half will be the first/start elem 
        int mini1 = nums[start];

        // now we find the min elem from right half by calling recursion on right half
        int mini2 = helper(nums,target,mid+1,end);
        
        // comparing both min elems from left and right half
        min_elem = min(mini1,mini2);
    }
    // if we reach the else condition it means that right half is sorted in inc order
    else{

        // since right half is sorted , the min elem from right half will be the mid elem
        int mini1 = nums[mid];

        //// now we find the min elem from left half by calling recursion on left half
        int mini2 = helper(nums,target,start,mid-1);
        
        min_elem = min(mini1,mini2);
    }

    return min_elem;

}

int binary_search(vector<int> nums , int target){
    
    int n = nums.size();
    
    return helper(nums,target,0,n-1);


}


int main(){
    return 0;
}