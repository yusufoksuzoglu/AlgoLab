#include <bits/stdc++.h>

using namespace std;
long long subseq(vector<long long> &lis, long long N){
    long long i, j;
    long long x = 1;
    vector<long long> dy(N, 1);
    for(i = 0; i < N; ++i){
        for(j = 0; j < i; ++j){
            if(lis[j] <= lis[i]){
                dy[i] = max(dy[i], dy[j] + 1);
            }
        }
        x = max(x, dy[i]);
    }
    return x;
}
int main() {
    
long long N, i;
cin >> N;
vector<long long> lis(N);
for(i = 0; i < N; ++i){
    cin >> lis[i];
}
cout << subseq(lis, N);
	return 0;
}
