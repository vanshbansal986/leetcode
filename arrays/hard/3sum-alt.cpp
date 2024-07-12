// https://leetcode.com/problems/3sum/description/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums, int target){
    int n = nums.size();
    vector<vector<int>> output;
    sort(nums.begin() , nums.end());

    for(int i=0; i<n; i++){
        vector<int> mini;
        
        int target = -1 * nums[i];
        int low = i+1;
        int high = n-1;

        while(low<high){
            if(nums[low] + nums[high] > target){
                high--;
            }
            else if(nums[low] + nums[high] > target){
                low++;
            }
            else{
                mini.push_back(nums[i]);
                mini.push_back(nums[low]);
                mini.push_back(nums[high]);
                
                output.push_back(mini);
            }
        }
    }
    
    return output;

}

int main(){

}