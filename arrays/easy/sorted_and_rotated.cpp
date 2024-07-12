// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

#include<iostream>
#include<vector>
using namespace std;



bool check(vector<int> &nums){
    int n = nums.size();
    int i =0;
    int flag = 1;
    bool sorted = true;
    int firstElem = nums[0];
    while(i<n-1){
        if(nums[i] <= nums[i+1]){
            i++;
        }
        else{
            i++;
            while(i<n-1 && flag == 0){
                if(nums[i] <= nums[i+1] ){
                    i++;
                }
                else{
                    flag =1;
                    sorted = false;
                    break;
                }
            }
            if(nums[i] > firstElem){
                sorted = false;
            }
        }
    }
}

int main(){
    
    return 0;
}