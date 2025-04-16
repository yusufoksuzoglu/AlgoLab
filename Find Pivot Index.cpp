class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int s;
        int toplam2=0;
        for(s=1;s<n;++s){
            toplam2+=nums[s];
        }
        int toplam1=0;
        s=0;
        while(toplam1!=toplam2 && s<n-1){
            toplam1+=nums[s];
            s++;
            toplam2-=nums[s];
        }
        if(toplam1==toplam2) return s;
        else return -1;
    }
};
