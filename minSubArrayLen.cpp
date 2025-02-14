int minSubArrayLen(int target, vector<int>& nums) {
    int i=0,j=0,min=INT_MAX, sum=0;

    if(nums[i]>=target) return 1;
    
    while(j<nums.size()) {
        sum+=nums[j];
        
        if(sum>=target && i<j) {
            while(sum-nums[i]>=target) sum-=nums[i++]; // advance i 
            if(min>(j-i+1)) min=j-i+1;  // found new min
        }

        j++;
    }
    

    if(min==INT_MAX) return 0;
    else return min; 
}