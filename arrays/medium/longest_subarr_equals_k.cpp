// https://www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_5713505?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


int max_subarray(vector<int> nums , int k){
    int n = nums.size();
    unordered_map<int,int> m;
    int max_length = 0;
    int sum = 0;
    
    for(int i=0; i<n; i++){
        int length = 0;
        sum += nums[i];
        int target = sum-k;

        if(sum == k){
            length = i+1;
        }
        else if(m.count(target)>0){
            length = i - m[target];
        }
        
        max_length = max(max_length , length);

        m[sum] = i;

    }

    return max_length;

}

int main(){
    return 0;
}