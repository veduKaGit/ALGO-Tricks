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
    
    for(int i=0;i<n;i++){  // 0 to n
      // element at index = abs(arr[i])-1
      // mark as visited by making it -ive
      // take abs() because arr[i] could have been set visited before
        if(arr[abs(arr[i])-1] > 0)
            arr[abs(arr[i])-1] *= -1;
        else
            repeat = abs(arr[i]);  //if already negative => its repeating number
    }
    
    for(int i=0;i<n;i++)
        if(arr[i] > 0)  // means element at index i was never visited
            missing = i+1; // so i is the missing number
    
    return {repeat, missing};
}


//soln 2:

