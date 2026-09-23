#include <bits/stdc++.h>

using namespace std;
typedef long long ll; 

//   cses DP - 1 
/*
 *   if we want sum x 
 *   we can have that sum from x - 1 , x -2 , x -3 ,x - 4 , x - 5, x -6 
 *
 *   dp[x] = sum(dp[x-i]) , i->1 to 6
 *   dp[0] = 1;  // only one way to make sum 0 not throwing at all
 *    
 */
 

int32_t main() { 

    int n ;
    cin >> n ;
    vector<int> dp(n+1,0);
    dp[0] = 1;
    for ( int i = 1 ; i <= n ;++i){
        for( int j = 1 ; j <= 6 ; ++j){
             if( i - j < 0 )break;
             dp[i] = 1ll * ( dp[i] + dp[i-j]) % int(1e9 + 7);
        }
    }
    cout << dp[n];
    
}
