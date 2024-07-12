// https://leetcode.com/problems/majority-element/description/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int majority_elem(vector<int> &nums){
    int n = nums.size();
    int count = 0;
    int candidate = 0;

    for(int i=0; i<n; i++){
        if(count == 0){
            candidate = nums[i];
        }

        if(nums[i] == candidate){
            count++;
        }
        else{
            count--;
        }
    }

    return candidate;
}



int main(){

}

