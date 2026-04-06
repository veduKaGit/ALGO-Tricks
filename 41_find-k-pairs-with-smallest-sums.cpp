//LEETCODE: 373. Find K Pairs with Smallest Sums

// You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.
// Define a pair (u, v) which consists of one element from the first array and one element from the second array.
// Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.


// BAD APPROACH (O(N * M * log K)) => time

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>ans;
        priority_queue<pair<int, vector<int>>>pq;

        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                int sum=nums1[i]+nums2[j];
                if(pq.size()<k)
                    pq.push({sum, {nums1[i], nums2[j]}});
                else if(sum < pq.top().first){
                    pq.pop();
                    pq.push({sum, {nums1[i], nums2[j]}});
                }else{
                    break;  // IMP => since sorted
                }
            }
        }

        while(pq.size()>0){
            vector<int>v = pq.top().second;
            ans.push_back(v);
            pq.pop();
        }

        return ans;
    }
};

// GOOD APPROACH:
// greedy + pq
// Key idea: Use a min-heap, seed it with (nums1[i], nums2[0]) for all i. Each time you 
// pop the smallest pair (i, j), push the next candidate (i, j+1) — because that's the
// next smallest sum reachable from that row.                                           

// TIME:
// O(k log k):
//   - Heap is seeded with at most min(n, k) elements
//   - Each of the k pops triggers at most one push                                       
//   - Each heap op = O(log k)                     

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {  
        // {sum, i, j}                                                                   
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;    
                                                                                        
        for (int i = 0; i < min((int)nums1.size(), k); i++)                              
            pq.push({nums1[i] + nums2[0], i, 0});                                        
                                                                                        
        vector<vector<int>> ans;
        while (k--) {                                                     
            auto [sum, i, j] = pq.top();
            pq.pop();                                       
            ans.push_back({nums1[i], nums2[j]});
            
            if (j + 1 < nums2.size())                                                    
                pq.push({nums1[i] + nums2[j+1], i, j+1});                                
        }
        return ans;                                                                      
    }              
};
