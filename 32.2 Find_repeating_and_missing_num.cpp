// question:
https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

// slightly diff from 32.1
// there we had array length n+1
// all elements in range [1,n]
// some elements occur only 1 time, but one element occurs multiple times

// here, we have array length n
// all elements in range [1, n] => one repeating, 1 missing (rest all occur 1 time)


// we can get missing^repeating (XOR) => using: (xor of all array elements) ^ (xor of 1 to n)
// we can get repeating using Tortoise Hare algo => 1st node of cycle
// solved ?????
// NO!!!!!
// tortoise hare FAILS in this question

// fails to detect the repeating number

// WHY? because we have numbers in range [1,n] and array size is n
// so slow/fast ptr may get out of bounds

// if we decrease all numbers by 1
// then all numbers in rangw [0, n-1]
// then 1st cycle node can be detected???
// still NOT => idk why but fails


// 2 soln to this problem:

// soln1:

vector<int> findTwoElement(vector<int>& arr) {
    int n = arr.size();
    int repeat=0, missing=0;
    
    for(int i=0;i<n;i++){
      // loop 0 to n-1
      // we will check for arr[i] => repeating number or not
        
      // for element at index = (arr[i]-1) => -1 to avoid out of bound error
      // mark as visited by making it -ive
      // take abs() because arr[i] could have been set visited before
        if(arr[abs(arr[i])-1] > 0)
            arr[abs(arr[i])-1] *= -1;
      //if already negative => its repeating number
        else
            repeat = abs(arr[i]);
    }
    
    for(int i=0;i<n;i++)
        if(arr[i] > 0)  // means element at index i was never visited
            missing = i+1; // so (i+1) is the missing number
    
    return {repeat, missing};
}


//soln 2:

class Solution {
  public:
    int get_right_bit(int n){
        for(int i=0;i<32;i++)
            if(n&(1<<i))
                return (1<<i);
        return -1;
    }

    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size(), xor_mr = 0;

        // xor_mr will have value = missing^repeating
        for(int i=0;i<n;i++){
            xor_mr ^= arr[i];
            xor_mr ^= (i+1);
        }
        
        int right_bit = get_right_bit(xor_mr);  //get rightmost set bit

        // since xor_mr  = missing^repeating
        // the positions where xor_mr has a set bit
        // missing and repeating differ in their bits there
        // one such bit it the rightmost set bit (for simplicity)
        
        // so we can group numbers into 2 grps
        // one grp has rightmost bit set, one grp has it unset
        
        int grp_1 = 0, grp_2 = 0;  //grp_1 has it set, grp_2 has it unset

        //we are doing this for both:
        //  1. array elements
        //  2. numbers in range [1, n]

        //so definitely one of grp_1, grp_2 is repeating, and the other one is missing
        // because missing one was counted only once (in range [1, n])
        // repeating one was counted 3x (once in [1, n], twice in array)
        for(int i=0;i<n;i++){
            if(arr[i]&right_bit)
                grp_1 ^= arr[i];
            else
                grp_2 ^= arr[i];
            
            if((i+1)&right_bit)
                grp_1 ^= (i+1);
            else
                grp_2 ^= (i+1);
        }
        
        for(int i=0;i<n;i++)
            if(grp_1 == arr[i])
                return {grp_1, grp_2};  //{repeating, missing}
        return {grp_2, grp_1};
    }
};

