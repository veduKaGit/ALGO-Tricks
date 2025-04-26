// used to find the majority element among the given elements
// that have >  floor(N/2) occurrences. 

// takes 2 traversals over the given elements
// works in O(N) time complexity and O(1) space complexity



class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        int major = arr[0], freq = 1;

        // write case 1 BEFORE case 2
        // this ques is easy, but in the next part, we'll know why
        // case 1 BEFORE case 2 is important
        for(int i=1;i<n;i++){
            if(arr[i] == major){   //if already exists => case 1
                freq++;
            }else if(freq == 0){   //if new major element => case 2 
                major = arr[i];
                freq = 1;
            }else{
                freq--;
            }
        }

        freq = 0;
        // Checking if majority candidate occurs more than n/2 times
        for (int i=0; i<n; i++) {
            if (arr[i] == major)
                freq++;
        }

        if (freq > (n/2))
            return major;
        return -1;
    }
};
