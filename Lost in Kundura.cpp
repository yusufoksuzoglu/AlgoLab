#include <bits/stdc++.h>

using namespace std;

int main() {
    
long long n, m, i, j;
cin >> n >> m;
vector<vector<long long>> dim(n, vector<long long> (m, 0));
dim[0][0] = 1;
for(i = 0; i < n; ++i){
    for(j = 0; j < m; ++j){
        if(i == 0 && j != 0){
            dim[i][j] = 1;
        }
        if(j == 0 && i != 0){
            dim[i][j] = 1;
        }
        if(i >= 1 && j != 0){
            dim[i][j] = (dim[i - 1][j] + dim[i][j - 1]) % 1000000007LL;
        }
    }
}
cout << dim[n - 1][m - 1];
	return 0;
}
