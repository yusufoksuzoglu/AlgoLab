class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if (k > nums.size()) return 0;  
        if (k == 0) return 0;  
        int toplam = 0;
        for (int i = 0; i < k; i++) {  
            toplam += nums[i];
        }
        int max=toplam;  
        for (int i = k; i < nums.size(); i++) {  
            toplam+=nums[i]-nums[i-k];
            max=std::max(max,toplam);
        }
        return (double)max/k;
    }
};
