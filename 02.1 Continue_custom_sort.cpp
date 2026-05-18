// example when we have a vector<vector<int>>v = {{a,b,c}, {e,f,g}, {h,i,j}}
// and we want to sort by the first column, ie. sort in ascending order of a,e,h

// the c_sort logic MUST always have < (or >)
// but NEVER <= (or >=)

// WHY? 
// bcz in cpp, sort() function is written in such a way that one of its rules is irreflexivity
// thus, c_sort(x, x) must always be false.

class Solution {
public:
    static bool c_sort(vector<int>&a, vector<int>&b){ // static keyword bcz inside class
        return a[0] < b[0];
        // return a[0] <= b[0]; => will error out
    }
    int jobScheduling(....random.....) {
      ....
      sort(combined.begin(), combined.end(), c_sort);
      ....
    }
};


// CONTINUING ON THIS:
// say we have the v vector sorted by the 0th column
// now we want to apply lower/upper bound on this based on the sorted column
// whats the syntax??

int ind = upper_bound(v.begin(), v.end(), vector<int>{value, INT_MAX, INT_MAX}) - v.begin();

// VVIMP => instead of simply an integer, we check lower/upper bound based on a vector
// setting 'value' only in the column which is sorted, and keeping the others INT_MAX
