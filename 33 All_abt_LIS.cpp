// LIS => longest increasing subsequence 




// In LIS => 2 types of questions:

// 1. find length of LIS => most optimal in O(N *logN) time

// 2. given an array 'nums' => construct an array 'dp' 
//    => where dp[i] = length of LIS considering ONLY [0,i] indices in nums, AND DEFINITELY including nums[i] in the LIS
//    => this comes handy in many dp questions
//    => O(N *logN) time





//ANS_for_problem_1

int longestIncreasingSubsequence(int arr[], int n){
    
    vector<int> temp;
    temp.push_back(arr[0]);
    
    int len = 1;
    
    for(int i=1; i<n; i++)  //start from i=1
    {
        if(arr[i]>temp.back())
	{  
           temp.push_back(arr[i]);
           len++;  
        } 
        else  //else -> includes == wala case also -> example we have temp array as -> [1,2,9] -> now arr[i] is 2 -> since we take lower_bound -> temp remains same
	{
            int ind = lower_bound(temp.begin(),temp.end(),arr[i]) - temp.begin();    //DO NOT use uper_bound
            temp[ind] = arr[i];  //replace => DONT change len
        }
        
    }
    
    return len;
}







// ANS_for_problem_2

// almost similar to problem_1

vector<int> longestIncreasingSubsequenceEndingWithI(int arr[], int n){        
                                                                                                                               
    vector<int> temp;                                                                                                          
    vector<int>ans(n);   // answer array                                                                                                   
                                                                                                                               
    temp.push_back(arr[0]);                                                                                                    
    ans[0] = 1;     // initialise                                                                                                           
                                                                                                                               
    int len = 1;                                                                                                               
                                                                                                                               
    for(int i=1; i<n; i++)                                                                                   
    {                                                                                                                          
        if(arr[i]>temp.back())                                                                                                 
    	{                                                                                                                          
           temp.push_back(arr[i]);                                                                                             
           len++;                                                                                                              
           ans[i] = len;        // update                                                                                               
        }                                                                                                                      
        else                                                                                   
    	{                                                                                                                          
            int ind = lower_bound(temp.begin(),temp.end(),arr[i]) - temp.begin();
            temp[ind] = arr[i];                                                           
            ans[i] = ind+1;    // update                                                                                                
        }                                                                                                                      
                                                                                                                               
    }                                                                                                                          
                                                                                                                               
    return ans;                                                                                                                
}
