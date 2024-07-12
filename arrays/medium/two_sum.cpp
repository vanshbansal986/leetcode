// https://leetcode.com/problems/two-sum/description/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target){
    vector<int> output;
    int n = nums.size();

    unordered_map<int,int> m;

    for(int i=0; i<n; i++){
        m[nums[i]] = i;
    }

    sort(nums.begin() , nums.end());

    int i = 0;
    int j = n-1;

    while(i<j){
        int sum = nums[i] + nums[j];
        if(sum > target){
            j--;
        }
        else if(sum < target){
            i++;
        }
        else{
            output.push_back(m[nums[i]]);
            output.push_back(m[nums[i]]);
            break;
        }
    }
}

int main(){

}