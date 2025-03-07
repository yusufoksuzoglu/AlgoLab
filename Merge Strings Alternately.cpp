class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string alterne;
        int i=0;
        int j=0;
            while( i < word1.length()|| j < word2.length()){
                if(i < word1.length()){
                    alterne+=word1[i];
                    i++;
                }
                if(j < word2.length()){
                    alterne+=word2[j];
                    j++;
                }
    }
    return alterne;
    }
};
