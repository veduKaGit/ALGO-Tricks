#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>v = {-1, 1, 4, 5, 11, 20, 21, 97, 99, 100};
    
    auto it = lower_bound(v.begin(), v.end(), 5);
    cout<<*it<<endl;  // 5
    it = lower_bound(v.begin(), v.end(), 6);
    cout<<*it<<endl;  // 11
    
    it = upper_bound(v.begin(), v.end(), 5);
    cout<<*it<<endl; // 11
    it = upper_bound(v.begin(), v.end(), 100);
    cout<<*it<<endl; // 60721 => random number => since points to v.end();
    
    int ind = lower_bound(v.begin(), v.end(), 5) - v.begin();
    cout<<ind<<endl;  // 3
    
    ind = upper_bound(v.begin(), v.end(), -2) - v.begin();
    cout<<ind<<endl;  // 0
    
    ////// now we'll see usage on map/set/multimap/multiset ////////
    // i am demonstrating on map and MULTIset (similarly we can do for set and MUTLImap)
    
    map<int, int>m;
    multiset<int>ms;
    
    m[-1] = 1;
    m[2] = 1;
    m[3] = 10;
    m[7] = 11;
    m[11] = 10;
    m[15] = -1;
    
    ms.insert(-1);
    ms.insert(2);
    ms.insert(2);
    ms.insert(10);
    ms.insert(11);
    ms.insert(15);
    ms.insert(15);
    
    auto it2 = m.lower_bound(3);
    cout<<it2->first<<" "<<it2->second<<endl;  // 3 10
    it2 = m.upper_bound(-1);
    cout<<it2->first<<" "<<it2->second<<endl;  // 2 1
    
    // int ind2 = m.lower_bound(7) - m.begin();   //INVALID SYNTAX FOR MAP/SET

    auto it3 = ms.lower_bound(2);
    cout<<*it3<<endl;  // 2
    it3 = ms.upper_bound(9);
    cout<<*it3<<endl; //10
    
    // int ind2 = ms.upper_bound(9) - ms.begin(); //INVALID SYNTAX FOR MAP/SET
    
    return 0;
}
