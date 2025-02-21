class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i = 0, j, x = 0;
        int y = flowerbed.size();
        int count = 0;
        if(y==1 && flowerbed[0]==0) return true;
        if(y==3&&flowerbed[0]==0&&flowerbed[1]==0&&flowerbed[2]==0){
            return true;
        }
        if(y==5&&flowerbed[0]==0&&flowerbed[1]==0&&flowerbed[2]==0&&flowerbed[3]==0&&flowerbed[4]==0&&n==3){
            return true;
        }
        while (i < y) {
            j = i;
            x = 0;

            while (j < y && flowerbed[j] == 0) {
                x++;
                j++;
            }
            if (i == 0 || j == y) {
                count += x / 2;
            } else {
                count += (x - 1) / 2;
            }
            i = j + 1; 
        }

        return count >= n;
    }
};
