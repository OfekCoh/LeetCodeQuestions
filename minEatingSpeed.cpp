    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1, high=*max_element(piles.begin(), piles.end()), mid;

        while(low<=high)
        {
            mid=(low+high)/2;
            long long sum=0;
            for(int num: piles) {
                sum+= num/mid;
                if(num%mid) sum++; // if we get a fraction need to add another whole hour 
            }
            if(sum>h) low=mid+1;
            else high=mid-1;
        }
        return low;
    }