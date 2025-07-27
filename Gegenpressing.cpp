#include<bits/stdc++.h>
using namespace std;

bool arkadas(int m,int n,vector<vector<vector<char>>> &saha){
    for(char c:saha[m][n]){
        if(c=='#') return true;
    }
    return false;
}

bool forvet(int m,int n,vector<vector<vector<char>>> &saha){
    for(char c:saha[m][n]){
        if(c=='0') return true;
    }
    return false;
}

void topugonder(int m,int n,vector<vector<vector<char>>> &saha){
    auto &hucresel=saha[m][n];
    for(auto it=hucresel.begin();it!=hucresel.end();++it){
        if(*it=='0'){
            hucresel.erase(it);
            break;
        }
    }
}

int rakipsayi(int m,int n,vector<vector<vector<char>>> &saha){
    int sayi=0;
    for(char c:saha[m][n]){
        if(c=='*') sayi++;
    }
    return sayi;
}

int sayi(int m,int n,vector<vector<vector<char>>> &saha){
    int count=0;
    for(char c:saha[m][n]){
        if(c=='#') count++;
    }
    return count;
}

void baskiyagit(int m,int n,int l,int k,vector<vector<vector<char>>> &saha){
    auto &kaynak=saha[m][n];
    for(auto it=kaynak.begin();it!=kaynak.end();++it){
        if(*it=='*'){
            kaynak.erase(it);
            saha[l][k].push_back('*');
            break;
        }
    }
}

bool takimarkadasi(int m,int n,vector<vector<vector<char>>> &saha){
    int dx[]={-1,-1,-1,0,0};
    int dy[]={-1,0,1,-1,1};
    for(int i=0;i<5;++i){
        int nx=m+dx[i];
        int ny=n+dy[i];
        if(nx>=0&&ny>=0&&nx<5&&ny<5){
            for(char c:saha[nx][ny]){
                if(c=='#') return true;
            }
        }
    }
    return false;
}

bool baski(int x,int y,vector<vector<vector<char>>> &saha){
    int rakip=0;
    for(char c:saha[x][y]){
        if(c=='*') rakip++;
    }
    return(rakip<2);
}

int main(){
    vector<vector<vector<char>>> saha(5,vector<vector<char>>(5));
    int x,y,c,d;
/*maçın 11'e 11 yapıldığı düşünülür.
Bu sebeple 5x5 bir matris iş görecektir. Öncelikli olarak tüm sahanın boş olduğu düşünülür.
Daha sonra sırasıyla A ve B takımları sahaya yerleştirilir. 
Son olarak her iki takımın da en ileri bölgesinde en az bir forvete sahip olduğu kabul edilir. */
    for(int i=0;i<11;++i){
        cin>>x>>y;
        saha[x][y].push_back('*');
    }

    for(int i=0;i<11;++i){
        cin>>c>>d;
        saha[c][d].push_back('#');
    }

    cin>>x>>y; //topun hangi bölgede olduğu kararlaştırılır.
    saha[x][y].push_back('0');

    while(takimarkadasi(x,y,saha)){
        if(rakipsayi(x,y,saha)<2){
            int dx[]={-1,-1,-1,0,0};
            int dy[]={-1,0,1,-1,1};
            for(int i=0;i<5;++i){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0&&ny>=0&&nx<5&&ny<5&&rakipsayi(nx,ny,saha)>0){
                    baskiyagit(nx,ny,x,y,saha);
                }
            }
        }

        int dx[]={-1,-1,-1,0,0};
        int dy[]={-1,0,1,-1,1};
        bool pasYapildi=false;

        for(int i=0;i<5;++i){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0&&ny>=0&&nx<5&&ny<5){
                if(baski(nx,ny,saha)&&arkadas(nx,ny,saha)&&!baski(x,y,saha)){
                    topugonder(x,y,saha);
                    saha[nx][ny].push_back('0');
                    x=nx;
                    y=ny;
                    pasYapildi=true;
                    break;
                }
            }
        }

        if(!pasYapildi){
            cout<<"Gegenpress başarıyla uygulanmıştır!"<<endl;
            break;
        }

        if(forvet(1,1,saha)||forvet(1,2,saha)||forvet(1,3,saha)){
            cout<<"GOL GOL GOL"<<endl;
            break;
        }
    }

    return 0;
}
