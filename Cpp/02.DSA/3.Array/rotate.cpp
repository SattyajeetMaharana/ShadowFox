include<bits/stdc++.h>
using namespace std;
void rotate(vector<int>& nums, int k) {
    int j=0;
    while(j<k){
        for(int i=0; i<nums.size()-1; i++){
            int temp=nums[i];
            nums[i]=nums[(i+1)%nums.size()];
            nums[(i+1)%nums.size()]=temp;
            }
            j++; 
        }
    }
int main(){
    vector<int> nums={1,2,3,4,5,6,7};
    int k=3;
    cout<<nums;
    cout<<endl<<"after calling function.."<<endl;
    rotate(nums,k);
    cout<<nums;
    return 0;
}    
