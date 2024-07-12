// https://leetcode.com/problems/move-zeroes/description/

#include<iostream>
#include<vector>
using namespace std;

void swap(vector<int> &nums , int a , int b){
    int temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
}

void moveZeros(vector<int> &nums){
    int n = nums.size();

    int i = 0;
    int j = 1;
    while(j<n){
        if(nums[i] == 0){
            if(nums[j] != 0){
                swap(nums,i,j);
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        else{
            i++;
        }
    }
}

int main(){

}