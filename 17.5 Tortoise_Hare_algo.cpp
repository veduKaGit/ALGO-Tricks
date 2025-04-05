// Tortoise Hare Algo
// The same slow/fast ptr algo used in Detect_1st_node_of_cycle_in_linked_list

// Another variation:
// https://leetcode.com/problems/find-the-duplicate-number/description/

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


// NOTE: the below soln works even when:
// we have array of size n+1
// all numbers are in the range [1,n]
// multiple numbers can repeat multiple times
// we can return ANY number that is repeating
// example => [1, 4, 4, 3, 2, 4, 3, 3]
// our soln will work here as well

class Solution {
public:
    int findDuplicate(vector<int>& A) {
        if (A.size() <= 1) 
            return -1;
        // Step 1: Detect cycle using Floyd's Tortoise and Hare
        int slow = A[0];
        int fast = A[0];

        slow = A[slow];
        fast = A[A[fast]];

        while(slow!=fast){
            slow = A[slow];
            fast = A[A[fast]];
        };

        // Step 2: Find the entry point of the cycle
        fast = A[0];
        while (slow != fast) {
            slow = A[slow];
            fast = A[fast];
        }

        return fast;
    }
};

