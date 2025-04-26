https://leetcode.com/problems/majority-element-ii/description/

// since we need to find elements
// which appear > floor(n/3) times
// there can be only 2 such elements (since its >, not >=)


//logic:
// 1. there are NO elements that appears more than n/3 times => then whatever the algorithm 
//    got from 1st iteration wound be rejected in the second iteration.
// 2. there is only 1 element that appears more than n/3 times => after 1st iteration one of 
//    the candicate must be that appears more than n/3 times, the other candicate 
//    is not necessarily be the second most frequent but it would be rejected in 2nd iteration.
// 3. there are 2 elments that appear more than n/3 times => candicates would contain both of
//    them


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        int major1 = INT_MAX, major2=INT_MAX, freq1 = 0, freq2 = 0;

        // first always set major1, major2 before checking for freq1,freq2 = 0
        // bcz if we change the order of if/else statements (ie. check for freq before major)
        // its possible at some point, freq1 or freq2 == 0
        // and we end up setting major1 and major2 as the same element
        for(int i=0;i<n;i++){
            if(major1 == nums[i]){
                freq1++;
            }else if(major2 == nums[i]){
                freq2++;
            }else if(freq1 == 0){
                major1 = nums[i];
                freq1 = 1;
            }else if(freq2 == 0){
                major2 = nums[i];
                freq2 = 1;
            }else{
                freq1--;
                freq2--;
            }
        }

        freq1 = 0, freq2 = 0;
        for(int i=0;i<n;i++){
            if(major1==nums[i])
                freq1++;
            if(major2==nums[i])
                freq2++;
        }

        if(freq1>(n/3))
            ans.push_back(major1);
        if(freq2>(n/3))
            ans.push_back(major2);

        return ans;
    }
};
