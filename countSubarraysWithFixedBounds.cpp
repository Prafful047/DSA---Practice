long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;

        int minidx = -1;
        int maxidx = -1;
        int invalidIdx = -1;

        for(int i=0 ; i<nums.size() ; i++){

            if(nums[i]>maxK || nums[i]<minK){
                invalidIdx = i;
            }

            if(nums[i]==minK){
                minidx = i;
            }

            if(nums[i]==maxK){
                maxidx = i;
            }

            auto smaller = min(minidx,maxidx);

            auto temp = smaller - invalidIdx ;

            ans += (temp >= 0)? temp : 0 ;

        }

        return ans;
    }