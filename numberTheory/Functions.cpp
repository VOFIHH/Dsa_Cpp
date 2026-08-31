#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 

vector<pair<int,int>> Factorisation( int n){
    if( n <= 0)return {};
    if( n == 1)return{{1,1}};
    vector<pair<int,int>> F ;
    int P = 0;
    while( n % 2 == 0){
        P++;
        n/=2;
    }   
    Factorisation.push_back({2,P});
    P = 0;
    while(n%3 == 0) {
        P++;
        n/=3;
    } 
    Factorisation.push_back({3,P});
    for ( int i = 5 ; i*i<=n ; i+=6){
        if (n % i == 0) {
            int count = 0;
            while (n % i == 0) { count++; n /= i; }
            F.push_back({i, count});
        }
        if (n % (i + 2) == 0) {
            int count = 0;
            while (n % (i + 2) == 0) { count++; n /= (i + 2); }
            F.push_back({i + 2, count});
        }
    }
    return F;
}
int32_t main() {
  cout << "hi";

}
