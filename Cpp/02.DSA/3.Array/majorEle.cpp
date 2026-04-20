#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int > mp;
        vector<int> ans;
        for(int x:nums){
            if(mp.find(x) != mp.end()) mp[x]++; 
            else mp.insert({x,1});
        }
        int grt=0;
        for(auto x:mp){
            if(x.second>grt){
                ans.clear();
                ans.push_back(x.first);
            }
            else if(x.second == grt){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1,2};
    vector<int> result = obj.majorityElement(nums);

    cout << "Majority element(s): ";
    for(int x : result){
        cout << x << " ";
    }
    return 0;
}