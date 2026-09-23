#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int32_t main() { 
    int n ;
    cin >> n;
    int x ;
    cin >> x;
    int dp[x+1];
    dp[0] = 0; 
    const int Inf = 1e9 + 10;
    for( int i = 1 ; i <= x ; ++i)dp[i] = Inf;
    int coins[n];
    for( int i = 0 ; i < n ; ++i)cin >> coins[i];
    sort(coins , coins + n);

    for( int i = 1 ; i <= x ; ++i){
        for ( int j = 0 ; j< n ; ++j){ 
            if( i - coins[j] < 0)break;
            dp[i] = min(dp[i] , dp[i - coins[j]] + 1);
        }  
        cout << i << ' ' << dp[i] << '\n';
        
    } 
    cout << dp[x] ;

}
