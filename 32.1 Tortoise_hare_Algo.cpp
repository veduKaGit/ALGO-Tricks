// Tortoise Hare Algo
// The same slow/fast ptr algo used in Detect_1st_node_of_cycle_in_linked_list

// time O(N)

// Another variation:
// https://leetcode.com/problems/find-the-duplicate-number/description/

why => 32 all_occur_k_times_but_one_occurs_p_times.cpp => does NOT work here???
because here p%k=0

// since we can't use linear extra space => use Tortoise Hare

// why will this algo work? 
// where is a cycle formed? 
// why our answer is the starting node of the cycle?

// say our array is => [2, 4, 1, 1, 3]
// if we make a linked list of this array like:
// node[0] -> node[node[0]] -> node[node[node[0]]] .... so on ....
// it will look like: 2 -> 1 -> 4 -> 3 -> 1 -> 4 -> 3 -> 1 .... so on ....
// we find a cycle => 1 -> 4 -> 3 -> 1
// this cycle starts at 1 => thats our answer

// why repeating element is start of the cycle?
// VERY SIMPLE!
// in the linked list we create
// every node points to every other node
// since one node is repeating, the cycle will obviously form at that node

// NOTE: the below soln works even when:
// we have array of size n+1
// all numbers are in the range [1,n]
// multiple numbers can repeat multiple times
// we can return ANY number that is repeating
// example => [1, 4, 4, 3, 6, 4, 3, 3]
// our soln will work here as well

class Solution {
public:
    int findDuplicate(vector<int>& A) {
        if (A.size() <= 1) 
            return -1;
        
        int slow = A[0]; // IMP => initialize both as A[0] => since linked list starts from there
        int fast = A[0];

        slow = A[slow];  // IMP => do this once before entering while loop => so that slow!=fast in the very 1st iteration
        fast = A[A[fast]];

        while(slow!=fast){
            slow = A[slow];
            fast = A[A[fast]];
        };

        fast = A[0];
        while (slow != fast) {
            slow = A[slow];
            fast = A[fast];
        }

        return fast;
    }
};
