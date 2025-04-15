// For both next_permutation and prev_premutation => time complexity = O(N)


// next_permutation:
//used to rearrange the elements in the range [first, last) into the next lexicographically greater permutation
//NOTE => see above => last index is NOT included

vector<int>v = {4,3,2,5,6,1};
next_permutation(v.begin(), v.end());
for(auto x:v)
    cout<<x<<" ";  //op: 4 3 2 6 1 5 


// prev_permutation:
// used to rearranges the elements in the range [first, last) into the previous lexicographically-ordered permutation
//NOTE => see above => last index is NOT included

vector<int>v = {4,3,2,5,6,1};
prev_permutation(v.begin(), v.end());
for(auto x:v)
    cout<<x<<" ";  //op: 4 3 2 5 1 6 
