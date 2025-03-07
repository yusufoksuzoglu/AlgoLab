class Solution {
public:
    int maxVowels(string s, int k) {
        vector<char>vowe;
        int max=0;
        int vovi=0;
        int i=0;
        for(i=0;i<k;++i){
            vowe.push_back(s[i]);
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                vovi++;
            }
        }
        max=vovi;
        for(i=k;i<s.length();++i){
            if(vowe.front()=='a'||vowe.front()=='e'||vowe.front()=='i'||vowe.front()=='o'||vowe.front()=='u'){
                vovi--;
            }
            vowe.erase(vowe.begin());
            vowe.push_back(s[i]);
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                vovi++;
            }
            if(vovi>max) max=vovi;
        }
        return max;
    }
};
