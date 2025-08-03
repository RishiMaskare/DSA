#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void brute_force(vector<int>& nums, int n){
    sort(nums.begin(), nums.end());
}
void optimized_approach(vector<int>& nums, int n){
    int czero = 0, cone = 0, ctwo = 0;
    for(int val: nums){
        if(val==0){
            czero++;
        }else if(val==1){
            cone++;
        }else{
            ctwo++;
        }
    }
    int ind=0;
    for(int i=0;i<czero;i++){
        nums[ind++]=0;
    }
    for(int i=0;i<cone;i++){
        nums[ind++]=1;
    }
    for(int i=0;i<n;i++){
        nums[ind++]=2;
    }
}
void optimal_approach(vector<int>& nums, int n){
    int low = 0, mid = 0, high = n-1;
    while(mid <= high){
        if(nums[mid] == 0){
            swap(nums[mid], nums[low]);
            low++;
            mid++;
        }else if(nums[mid] == 1){
            mid++;
        }else{
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}
int main(){
    vector<int> nums = {0, 2, 0, 1, 2, 0, 0, 1, 2, 2};
    int n = nums.size();
    optimal_approach(nums, n);
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}