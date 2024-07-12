#include<iostream>
#include<vector>
using namespace std;

int helper(vector<int> nums , int start , int end){
    // base case
    // if(start == end){
    //     return start;
    // }
    if(start > end){
        return -1;
    }

    int mid = start + (end-start)/2;

    if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
        return mid;
    }
    else{
        
        if(nums[mid+1] > nums[mid]){
            return helper(nums , mid+1 , end);
        }
        else{
            return helper(nums , mid+2 , end);
        }

        if(nums[mid-1] > nums[mid]){
            return helper(nums , start , end-1);
        }
        else{
            return helper(nums , start , end-2);
        }


    }
    

}

int binary_search(vector<int> nums , int target){
    int n = nums.size();
    if(n<2){
        return 0;
    }

    if(nums[0] > nums[1]){
        return 0;
    }
    else if(nums[n-1] > nums[n-2]){
        return n-1;
    }
    else{
        return helper(nums,0,n-1);
    }
    

    
    
    


}


int main(){
    return 0;
}