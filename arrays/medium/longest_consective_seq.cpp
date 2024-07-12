// https://leetcode.com/problems/longest-consecutive-sequence/description/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

// void swap(vector<int> &nums , int a , int b){
//     int temp = nums[a];
//     nums[a] = nums[b];
//     nums[b] = temp;
// }

int longestSeq(vector<int>& nums){
    int n = nums.size();
    unordered_map<int,int> m;
    unordered_set<int> st;
    

    for(int i=0; i<n; i++){
        m[nums[i]] = 1;
    }

    int longest_seq = 1;

    for(int i=0; i<n; i++){
        int seq = 1;
        int val = nums[i] - 1;
        if(m.count(val) != 1){
            int val2 = nums[i] + 1;
            while(m.count(val2) > 0){
                seq++;
                val2 += 1;
            }
        }
        
        longest_seq = max(seq , longest_seq);
    }

}

int main(){
    
    

}

