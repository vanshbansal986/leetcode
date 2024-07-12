// https://leetcode.com/problems/subarray-sum-equals-k/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


int max_subarray(vector<int> nums , int k){
    int n = nums.size();
    unordered_map<int,int> m;
    int sum1 = 0;
    for(int i=0; i<n; i++){
        sum1 += nums[i];
        m[i] = sum1;
    }

    int count;
    int sum2;
    for(int i=1; i<n; i++){
        for(int j=i; j<n; j++){
            sum2 = m[j] - m[i-1];
            if(sum2 == k){
                count++;
            }
        }
    }

}

int main(){
    return 0;
}