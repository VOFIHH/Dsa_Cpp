#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
using u128 = unsigned __int128;
using i128 = __int128;
template<typename T>
T binpow(T a, T b , const T MOD) { // O(logn) exponentiation 
    T ans = 1;
    while (b) {
        if (b & 1) {
            ans =(u128)ans * a % MOD;
        }
        a =(u128)a * a % MOD;
        b >>= 1;
    }
    return ans;
}

template <typename T >
T lcm( T a , T b){
    return (a/gcd(a,b) * b);

}
template<typename T >
T recursive_ex_gcd(T a ,T b , T&x, T&y){ // recursive implementation 
    if ( b == 0){ // when b = 0 , [x=1 , y =0] 
        x = 1 ;
        y = 0 ;
        return a;
    } 
    T x1 , y1;
    T d = recursive_ex_gcd(b , a % b , x1 , y1); //  get the values of x1 and y1 
    x = y1;  
    y = x1 - y1*(a/b);
    return d ;
}
template<typename T >
T ex_gcd( T a , T b , T &x , T&y){ // iterative implementation 
     x = 1 , y = 0 ;
     T x1 = 0 , y1 = 1 , a1 = a , b1 = b;

     while (b1){
         T q = a1/b1;
         tie(x , x1) = make_pair(x1 , x - q*x1);
         tie(y , y1) = make_pair( y1 , y - q*y1);
        tie(a1 , b1) = make_pair(b1 , a1 - q*b1);
     }
     return(a1);
}
// Miller Rabin (primality check for large numbers) for n the standard root(n) algorithm is enough
bool isprime(ull n){ // a^d - 1 = 0   or a^2rd + 1 = 0 (mod n) ,r-> (0 , s-1] 
    if ( n < 2)return false;
    if ( n == 2)return true;
    if (!(n & 1))return false;
    ull b[]={2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    ull s = __builtin_ctzll(n-1) , d = (n-1) >> s;
    for ( ull base : b ){
        if ( n == base)return true;
        base%=n;
        if(!base)continue;
        ull x = binpow(base , d , n);
        if( x == 1 || x == n-1)continue;
        bool p = false;
        for ( ull tmp = 1 ; tmp < s;++tmp){
            x = (u128)x * x%n;
            if( x == n-1){p = true ; break;}
        }
        if(p)continue;
        return false;
    }
    return true;  
}


template<typename  T> 
T modinv ( T a , const T m ){ 
    if(isprime(a)) return binpow(a,m-2,m);
    T x ,y ;
    T g = ex_gcd(a , m, x , y);
    if (g!= 1)return -1;
    return (x % m + m)%m;
}
template <typename  T>
bool hassolution(T a , T b ,T c){ 
    // change the code if want only positive ans or any other condition 
    // to make the logic the roots are in the form x - bt/g and y + at/g
    // so every equation or inequality become a solving for 't' problem
    // T x ,T y ;
    // ex_gcd(a , b ,x ,y);
    // x*=c/g
    // y*=c/g
    return (c % gcd(a,b) == 0); 
    
}
    
    




