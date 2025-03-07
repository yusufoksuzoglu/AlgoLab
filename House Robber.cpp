class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int i=2;
        int j=0;
        int maximus=0;
        if(n==1){
            int aykiri=nums[0];
            return aykiri;
        }
        while(i!=n){
            for(j=0;j<i-1;++j){
                maximus=max(maximus,nums[j]+nums[i]);
            }
            nums[i]=maximus;
            i++;
            maximus=0;
        }
        return *max_element(nums.begin(), nums.end());
    }
};
