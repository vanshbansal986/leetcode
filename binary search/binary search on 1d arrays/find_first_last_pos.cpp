#include<iostream>
#include<vector>
using namespace std;


void helper(vector<int> nums, int target, vector<int> &output, int start, int end)
{

    // base case
    if (start > end){
        
        output.push_back(-1);
        output.push_back(-1);
        return;
    }

    int mid = start + (end - start) / 2;

    if (nums[mid] == target){
        
        int low = mid;
        int high = mid;

        while (high < end && nums[high + 1] == target){
            high++;
        }
        while (low > start && nums[low - 1] == target){
            low--;
        }
        
        output.push_back(low);
        output.push_back(high);
    }
    else if (nums[mid] > target){
        return helper(nums, target, output, start, mid - 1);
    }
    else{
        return helper(nums, target, output, mid + 1, end);
    }
}


vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> output;
    
    helper(nums,target,output,0,n-1);
    
    return output;
}






int main(){
    return 0;
}