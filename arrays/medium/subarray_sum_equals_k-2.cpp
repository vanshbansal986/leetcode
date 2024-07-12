// https://leetcode.com/problems/subarray-sum-equals-k/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


int max_subarray(vector<int> nums , int k){
    int n = nums.size();
    unordered_map<int,int> m;
    int count = 0;
    int sum = 0;

    for(int i =0; i<n; i++){
        sum += nums[i];
        
        if(m.count(sum)>0){
            count++;
        }

        int remaining = sum - k;
        if(m.count(remaining) > 0){
            count++;
        }

        m[sum] = i;
    }

    return count;

}

int main(){
    return 0;
}