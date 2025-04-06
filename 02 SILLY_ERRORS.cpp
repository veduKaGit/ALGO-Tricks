// SORT vector<pair<int, int>>
// customize your own sort function

// why we use '&'?
// it will work even without it
// we just pass by reference, it avoids copying the object. Thus no TLE.


// IF we have csort function inide a class => use STATIC => static bool csort ()
// Static functions belong to the class itself
// not to an instance of the class
// They can be called directly using the class name, without needing an object


#include <bits/stdc++.h>
using namespace std;

bool csort(pair<int, int>&a, pair<int, int>&b){  // use '&' !!!
    if(a.second==b.second)
        return a.first>b.first;  // if values are same, sort descending based on keys
    return a.second<b.second;    //sort ascending based on value
}

int main()
{
    vector<pair<int, int>>v = {{1,3}, {2,3}, {0, 3}, {4, 5}, {7, 5} , {9,9}, {7,9}, {6,6}};
    sort(v.begin(), v.end(), csort);  //use custom sort function
    
    for(auto x:v){
        cout<<x.first<<" "<<x.second<<endl;
    }
    
    return 0;
}
