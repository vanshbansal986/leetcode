//https://leetcode.com/problems/rotate-array/description/

// 37/38 test cases passed. Last Test case gives TLE

#include<iostream>
#include<vector>
using namespace std;

void swap(vector<int> &nums , int a , int b){
    int temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
}

void rotate(vector<int> &nums , int k){
    int n = nums.size();

    // this is incase k is greater than size of array
    if(k>nums.size()){
        while(k>nums.size()){
            k = k-n;
        }
    }

    for(int i=0; i<k; i++){
        int j = n-k+i;
        while(j>0){
            swap(nums,j,j-1);
            j--;
        }
    }
}

int main(){
    return 0;
}