// https://leetcode.com/problems/majority-element-ii/description/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> majority_elem2(vector<int> &nums){
    int n = nums.size();
    vector<int> output;

    int candidate1 =0;
    int candidate2 =0;
    int count1 =0;
    int count2 =0;

    for(int i=0; i<n; i++){
        if(count1 == 0 && nums[i] != candidate2){
            candidate1 = nums[i];
            count1 = 1;
        }
        else if(count2 == 0 && nums[i] != candidate1){
            candidate2 = nums[i];
            count2 = 1;
        }
        else if(nums[i] == candidate1){
            count1++;
        }
        else if(nums[i] == candidate2){
            count2++;
        }
        else{
            count1--;
            count2--;
        }
    }
    
    if(count1>0){
        output.push_back(candidate1);
    }
    if(count2>0){
        output.push_back(candidate2);
    }

    return output;

}

vector<int> majority_elem(vector<int> &nums){
    int n = nums.size();
    vector<int> output;
    int half = n/2;

    if(n%2 != 0){
        half = n/2 + 1;
    }

    if(n == 1){
        output.push_back(nums[0]);
        return output;
    }

    
    int candidate = 0;
    int count = 0;

    
    for(int i=0; i<half; i++){
        
        if(count == 0){
            candidate = nums[i];
            count++;
        }

        if(nums[i] == candidate){
            count++;

        }
        else{
            count--;
        }
    }
    int elem1 = candidate;

    candidate = 0;
    count = 0;
    for(int i=half; i<n; i++){
        
        if(count == 0){
            candidate = nums[i];
            count++;
        }

        if(nums[i] == candidate){
            count++;

        }
        else{
            count--;
        }
    }
    int elem2 = candidate;

    int min = (n/3) + 1;
    int count1 = 0;
    int count2 = 0;

    for(int i=0; i<n; i++){
        if(nums[i] == elem1){
            count1++;
        }
        if(nums[i] == elem2){
            count2++;
        }
    }

    if(count1>=min){
        output.push_back(elem1);
    }
    if(count2>=min && elem2 != elem1){
        output.push_back(elem2);
    }

    return output;


    
    
    return output;
}



int main(){

}

