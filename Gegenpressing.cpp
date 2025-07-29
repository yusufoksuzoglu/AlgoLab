#include <iostream>
#include <vector>
using namespace std;

bool takimarkadasi(int m,int n,vector<vector<vector<char>>> &saha){
    int dx[]={-1,0,1};
    int dy[]={-1,-1,-1};
    for(int i=0;i<3;++i){
        int nx=m+dx[i];
        int ny=n+dy[i];
        if(nx>=0&&ny>=0&&nx<5&&ny<5){
                if(count(saha[ny][nx].begin(), saha[ny][nx].end(), '#') == 1 && count(saha[ny][nx].begin(), saha[ny][nx].end(), '*') == 0){
                    saha[ny][nx].push_back('0');
                    for(auto it=saha[n][m].begin();it!=saha[n][m].end();++it){
                        if(*it=='0'){
                            saha[n][m].erase(it);
                            break;
                        }
                    }
                    return true;
                }
            }
        }
    return false;
}

bool forvet(vector<vector<vector<char>>> &saha){
    for(int i = 0;i<5;++i){
        if(count(saha[1][i].begin(),saha[1][i].end(),'#') != 0 && count(saha[1][i].begin(),saha[1][i].end(),'0') == 1) return true;
    }
    return false;
}
pair<int, int> topubul(vector<vector<vector<char>>> &saha){
    for(int i=0; i<5; ++i){
        for(int j=0; j<5; ++j){
            if(count(saha[i][j].begin(), saha[i][j].end(), '0') == 1) return make_pair(i, j);
        }
    }
    return make_pair(-1, -1);
}

bool baskiyagit(int m,int n,int l,int k,vector<vector<vector<char>>> &saha){
    if (count(saha[k][l].begin(), saha[k][l].end(), '*')==2) return false;
    auto &kaynak=saha[n][m];
    for(auto it=kaynak.begin();it!=kaynak.end();++it){
        if(*it=='*'){
            kaynak.erase(it);
            saha[k][l].push_back('*');
            return true;
        }
    }
    return false;
}

bool pas(pair<int, int> cord, vector<vector<vector<char>>> &saha){
    int m = cord.first;
    int n = cord.second;
    if (count(saha[n][m].begin(), saha[n][m].end(), '*')==1){
        if(takimarkadasi(m, n, saha)) return true;
        if(baskiyagit(m-1, n, m, n, saha)) return false;
        if(baskiyagit(m+1, n, m, n, saha)) return false;
        if(baskiyagit(m-1, n-1, m, n, saha)) return false;
        if(baskiyagit(m, n-1, m, n, saha)) return false;
        if(baskiyagit(m+1, n-1, m, n, saha)) return false;
    }
    
    if (count(saha[n][m].begin(), saha[n][m].end(), '*')==2) return false;
    return takimarkadasi(m, n, saha);
}

int main(){
    vector<vector<vector<char>>> saha = {
            { {}, {}, {'*'}, {}, {} },
            { {'*'}, {'#','*'}, {'#',}, {'#','*'}, {} },
            { {'*'}, {'#','*'}, {'#'}, {'#','*'}, {'*'} },
            { {'#','0'}, {'#','*'}, {'*'}, {'#','*'}, {'#'} },
            { {}, {}, {'#'}, {}, {} }
          };
    while(pas(topubul(saha),saha)){
        if(forvet(saha)){
            cout<<"GOL OLDU!";
            return 0;
        }
    }
    cout<<"GEGENPRESS BAŞARIYLA UYGULANMIŞTIR!";
    return 0;
}
