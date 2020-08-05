class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> cumm;
        if(k<0)
            k=abs(k);
        cumm.push_back(0);
        cumm.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            cumm.push_back(nums[i]+cumm[i]);
        }
        for(int i=0;i<cumm.size();i++){
            if(k!=0)
            cumm[i] %= k;
        }
        for(int i=0;i<cumm.size();i++){
            for(int j=0;j<cumm.size();j++){
                if(j-i>=2 && cumm[i]==cumm[j])
                    return true;
            }
        }
        return false;
    }
};
