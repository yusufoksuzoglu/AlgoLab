class Solution {
public:
    string removeStars(string s) {
        std::stack<char>yildiz;
        int i=0;
        for(i=0;i<s.length();++i){
            if(s[i]!='*') yildiz.push(s[i]);
            if(s[i]=='*' && s[0]!='*'){ 
                yildiz.push(s[i]);
                yildiz.pop();
                yildiz.pop();
            }
        }
        stack<char>yildiz2;
        while(!yildiz.empty()){
            char a = yildiz.top();
            yildiz.pop();
            yildiz2.push(a);
        }
        string yeni;
        while(!yildiz2.empty()){
            char b = yildiz2.top();
            yildiz2.pop();
            yeni.push_back(b);
        }
        return yeni;
    }
};
