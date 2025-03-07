class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int max=0;
        int n=nums.size();
        int i=0;
        int j=nums.size()-1;
        int toplam=0;
        sort(nums.begin(),nums.end());
        while(i<j){
            toplam=nums[i]+nums[j];
            if(toplam>k){
                j--;
            }
            else if(toplam<k){
                i++;
            }
            else{
                max++;
                i++;
                j--;
            }
        }
        return max;
    }
};
