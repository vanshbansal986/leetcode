// https://leetcode.com/problems/3sum/description/

// passes 311/313 testcases. Gives TLE

#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums, int target){
    int n = nums.size();
    set<vector<int>> s;
    
    for(int i=0; i<n; i++){
        int target1 = -1 * nums[i];
        set<int> hashset;
        
        for(int j=i+1; j<n; j++){
            int target2 = target1 - nums[j];
            
            if(hashset.find(target2) != hashset.end() ){
                
                vector<int> mini = {nums[i] , nums[j] , target2};
                sort(mini.begin(),mini.end());
                
                s.insert(mini);

            }

            hashset.insert(nums[j]);
        }
        
    }
    vector<vector<int>> output(s.begin() , s.end());

    return output;
}

int main(){

}