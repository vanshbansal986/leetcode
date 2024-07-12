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
        int diff = target - nums[i];

        if(m.count(diff)){
            output.push_back(i);
            output.push_back(m[diff]);
            break;
        }
    }
}

int main(){

}