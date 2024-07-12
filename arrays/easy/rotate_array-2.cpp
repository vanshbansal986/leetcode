//https://leetcode.com/problems/rotate-array/description/

// Alternate approach by reversing the array

#include<iostream>
#include<vector>
using namespace std;

void swap(vector<int> &nums , int a , int b){
    int temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
}

void reverse(vector<int> &nums , int start , int end){
    int n = start - end;
    
    for(int i = start; i<end; i++){
        swap(nums,i,end-i);
    }
}

void rotate(vector<int> &nums , int k){
    int n = nums.size();

    reverse(nums,0,n-1);
    reverse(nums,0,k);
    reverse(nums,k+1,n-1);

    
}

int main(){
    return 0;
}