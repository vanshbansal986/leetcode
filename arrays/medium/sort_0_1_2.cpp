// https://leetcode.com/problems/sort-colors/description/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void swap(vector<int> &nums , int a , int b){
    int temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
}

void sortColors(vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    int j = n-1;

    while(i<j){
        if(nums[i] == 2){
            if(nums[j] == 0){
                swap(nums,i,j);
                i++;
                j--;
            }
            else if(nums[j] == 1){
                swap(i,j);
                j--;
            }
            else{
                j--;
            }
        }
        else if(nums[i] == 0){
            i++;
        }
        else{
            if(nums[j] == 0){
                swap(i,j);
                i++;
                j--;
            }
            else if(nums[j] == 2){
                j--;
            }
        }
    }        
}

int main(){

}

void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n-1;

        while(i<j){
            if(nums[i] == 2){
                if(nums[j] == 0){
                    swap(nums,i,j);
                    i++;
                    j--;
                }
                else if(nums[j] == 1){
                    swap(nums,i,j);
                    j--;
                }
                else{
                    j--;
                }
            }
            else if(nums[i] == 0){
                i++;
            }
            else{
                if(nums[j] == 0){
                    swap(nums,i,j);
                    i++;
                    j--;
                }
                else if(nums[j] == 2){
                    j--;
                }
            }
        }
    }