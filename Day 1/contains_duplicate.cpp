/* link - https://leetcode.com/problems/contains-duplicate/   */
// Author - Riya Singh



class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       unordered_set<int> s;
        int n = nums.size();
        for(int i=0; i<n; i++){
            s.insert(nums[i]);
        }
        if(s.size() == n){
            return false;
        }
        return true;
    }
};