class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans=0, tot=0;
        unordered_map<int,int>m;

        // m[remainder] → how many times this remainder has appeared so far
        m[0]++;

        for(int i=0;i<nums.size();i++){
            tot += nums[i];
            int rem = tot%k;
            if(rem<0)   
                rem+=k;  // since nums[i] can be -ive
            
            ans += m[rem];
            
            m[rem]++;   //IMP -> m[rem]++
        }

        return ans;
    }
};
