class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> cumm;
        map<int,vector<int>> mp;
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
            mp[cumm[i]].push_back(i);
        }
        for(auto itr : mp){
            int start = itr.second[0];
            cout<<start<<endl;
            int end=*(itr.second.begin() + (itr.second.size()-1));
            cout<<end<<endl;
            if(end-start>=2)
                return true;
        }
        return false;
    }
};
