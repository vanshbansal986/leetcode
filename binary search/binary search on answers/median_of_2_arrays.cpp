#include<iostream>
#include<vector>
#include <cmath>
using namespace std;



int helper(vector<int> nums , int m , int start , int end){
    
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    int i = 0;
    int j = 0;
    float elem1 = 0;
    float elem2 = 0;
    int ind1 = 0;
    int ind2 = 0; 
    int k = 0;


    if((m+n)%2 == 0){
        ind1 = (m+n)/2 - 1;
        ind2 = (m+n)/2;
    }

    else{
        ind1 = (m+n)/2;
        ind2 = (m+n)/2;
    }

    
    while(i<m && j<n){
        if(nums1[i] <= nums2[j]){
    
            if(k == ind1){
                elem1 = nums1[i];
            }
            if(k == ind2){
                elem2 = nums1[i];
                k++;
                break;
            }
    
            i++;
            k++;
        }
        else{
    
            if(k == ind1){
                elem1 = nums2[j];
            }
            if(k == ind2){
                elem2 = nums2[j];
                k++;
                break;
            }
    
            j++;
            k++;
        }
    }
    
    while(i<m){
        if(k == ind1){
            elem1 = nums1[i];
        }
    
        if(k == ind2){
            elem2 = nums1[i];
            k++;
            break;
        }
    
        i++;
        k++;
    }
    
    while(j<n){
        if(k == ind1){
            elem1 = nums2[j];
        }
    
        if(k == ind2){
            elem2 = nums2[j];
            k++;
            break;
        }
    
        j++;
        k++;
    
    }
    
    cout<<elem1<<endl;
    cout<<elem2<<endl;
    return (elem1 + elem2)/2;
    
}

int main(){
    // shipWithinDays
    return 0;
}

