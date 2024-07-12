#include<iostream>
#include<vector>
#include <cmath>
using namespace std;

int helper(vector<int> nums , int target , int start , int end){
    // base case
    int n = nums.size();
    
    if(start > end){
        return  INT_MAX;
    }

    int mid = start + (end - start)/2;
    int sum = 0;
    
    
    for(int i=0; i<n; i++){
        if(nums[i]%mid==0){
            sum+=(nums[i]/mid);
        } 
        else{
            sum+=(nums[i]/mid)+1;
        }
        
    }

    
    

}

int binary_search(vector<int> nums , int target){
    int n = nums.size();
    sort(nums.begin() , nums.end());
    
    int low = nums[0];
    int high = nums[n-1];

    return helper(nums,target,low,high);


}


int main(){
    return 0;
}