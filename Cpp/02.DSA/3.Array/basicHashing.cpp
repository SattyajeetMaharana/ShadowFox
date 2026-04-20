#include<bits/stdc++.h>
using namespace std;
    int maxSubArray(vector<int>& nums) {
        // ****Optimized****
        int sum=0;
        int gSum=INT_MIN;
        for(int i=0; i<nums.size(); i++){
            sum=sum+nums[i];
            if(sum<0)     sum==0;            
            if(gSum<sum) gSum=sum;
        }
        return gSum;
    }
int main(){
    vector<int> arr={-2,-1,-3,-4,-1,-2,-1,-5,-4};
    int ans=maxSubArray(arr);
    cout<<"\n\nanswer is"<<ans;
}
