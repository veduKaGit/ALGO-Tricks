class Solution {
public:
    void outPlaceMerge(vector<int> &nums, int low, int mid, int high) {   //out of place merge function-> since we are creating a "sorted" array also
        if (low >= high) return;
        int l = low, r = mid + 1, k = 0, size = high - low + 1;
        vector<int> sorted(size, 0);
        
        while (l <= mid and r <= high){
            if(nums[l]<nums[r]){
                sorted[k] = nums[l];
                l++;
            }else{
                sorted[k] = nums[r];
                r++;
            }
            k++;
        }
        while (l <= mid){
            sorted[k] = nums[l];
            k++;
            l++;
        }
        while (r <= high){
            sorted[k] = nums[r];
            k++;
            r++;
        }

        for (k = 0; k < size; k++)
            nums[k + low] = sorted[k];
    }

    void mergeSort(vector<int> &nums, int low, int high) {
        if (low >= high) return;
        int mid = (high - low) / 2 + low;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        outPlaceMerge(nums, low, mid, high);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n-1);    
        return nums;
    }
};
