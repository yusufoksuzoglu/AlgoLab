class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>candyy;
        int i=0;
        int j=0;
        int max=candies[0];
        for(j=1;j<candies.size();++j){
            if(candies[j]>max) max=candies[j];
        }
        for(i=0;i<candies.size();++i){
            if(extraCandies+candies[i]>=max) candyy.push_back(true);
            else candyy.push_back(false);
        }
        return candyy;
    }
};
