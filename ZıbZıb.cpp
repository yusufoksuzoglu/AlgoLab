#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N, K, i, j;
    cin >> N >> K;
    vector<long long> arr(N);
    for(i = 0; i < N; ++i){
        cin >> arr[i];
    }
    vector<long long> dp(N, INT_MAX);
    dp[0] = 0;
    for(i = 0; i < N; ++i){
        for(j = 1; j <= K; ++j){
            if(i + j < N && dp[i] + abs(arr[i + j] - arr[i]) < dp[i + j]){
                dp[i + j] = dp[i] + abs(arr[i + j] - arr[i]);
            }    
        }
    }
    cout << dp[N - 1];
	return 0;
}
