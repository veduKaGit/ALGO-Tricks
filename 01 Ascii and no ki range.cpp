1. ASCII....0->48
            a->97
            A->65

2. If we have lowercase letters ONLY
   make vector v of size 26
   do v[str[i]-'a'] to get index
   
3. If we have lowercase/uppercase/numbers/special characters 
   make array of size 128 (all possible characters)
   vector<int>v(128, -1);
   v[str[i]] = ...something...;  // no need to do v[str[i]-'a'] => gives error
   
4. int range-> { -2147483648 to 2147483647 } -> ie. { 2.1 * 10^9 tak ja sakta hai}
   long long int range -> { -(2^63) to (2^63)-1 } -> ie. {  9 * 10^18 tak ja sakta hai}
