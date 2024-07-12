// https://leetcode.com/problems/rearrange-array-elements-by-sign/description/



#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void swap(vector<int> &nums , int a , int b){
    int temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
}

vector<int> ReArrange(vector<int>& nums){
    int n = nums.size();
    vector<int> output(n);
    int np = 0;
    int nn = 1;
    
    for(int i = 0; i<n; i++){
        if(nums[i] > 0){
            output[np] = nums[i];
            np +=2;
        }
        else{
            output[nn] = nums[i];
            nn +=2;
        }
    }
    return output;

}

int main(){

}

