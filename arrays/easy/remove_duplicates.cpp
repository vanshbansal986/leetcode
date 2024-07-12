// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include<iostream>
#include<vector>
using namespace std;

void swap(vector<int> &nums , int a , int b){
    int temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
}

int remove_dup(vector<int> &nums){
    int n = nums.size();
    int i=1;
    int curr = 0;
    int k = 0;

    while(i<n){
        if(nums[i] == nums[curr]){
            while(nums[i] == nums[curr]){
                i++;
            }
            swap(nums,curr+1,i);
            k++;
            curr += 1;
            i++;
        }
        else{
            swap(nums,curr+1,i);
            curr +=1;
            i++;
            k++;
        }  
    }

}

int main(){
    return 0;
}