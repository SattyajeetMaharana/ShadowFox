#include<bits/stdc++.h>
using namespace std;
bool check(vector<int>& nums) {
        int sml=INT_MAX;
        int j;
        // smallest element search
        for(int i=0; i<nums.size(); i++){
            if(sml>nums[i]){
                sml=nums[i];
                j=i;            
            }
            else if(sml==nums[i]){
                j=i;
            }
        }
        // base condition
        if(sml==nums[0]){
            for(int i=0;i<nums.size()-1;i++){
                if(nums[i]>nums[i+1])
                return false;
            }
            return true;
        }
        // mid conditions
        else{
            if(j==1){
                if(nums[nums.size()-1]>nums[0]){
                    return false;
                }
            }
            else{
                for(int i=0; i<=j-2; i++){
                    if(nums[i]>nums[i+1]){
                        return false;
                    }
                }    
            }
            if(j==nums.size()-1){
                if(nums[0]<nums[j]){
                    return false;
                }
            }
            else{
               for(int i=j; i<=nums.size()-2; i++){
                    if(nums[i]>nums[i+1]){
                        return false;
                    }
                }
            }
            return true;
        }
    }
int main(){
    vector<int> nums={6,10,6};
    cout<<"started"<<endl;
    if(check(nums)){
        cout<<"yes approved";
    }
    else{
        cout<<"nahhh....";
    }

}