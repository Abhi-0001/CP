#include<bits/stdc++.h>
using namespace std;


// question on prefix and hashing
/*  TEST CASE
    5 3
    1 2 100
    2 5 100
    3 4 100
*/

const long int N = 1e7 + 5;
long long arr[N];
long int n;
int main(){
    int m;
    cin>>n>>m;
    /*
    while(m--){
        long int a, b, k;
        cin>>a>>b>>k;
        for(int i=a; i<=b; i++){
            arr[i] += k;
        }
    }
    int max = 0;
    for(int i=1; i<n; i++){
        if(arr[max] < arr[i])
            max = i;
    }
    cout<<arr[max];
    */

    // Time complexity --> O ((m = 2 * 10^5) * (n = 10^7) + 10^7) ~ 10^12 i.e, can't run in 1ms.
    
    // optimized approach:
    while(m--){
        long int a, b, k;
        cin>>a>>b>>k;
        arr[a] += k;
        arr[b+1] -= k;
    }
    for(int i=1; i<=n; i++){
        arr[i] = arr[i] + arr[i-1];
    }
    int max = 0;
    for(int i=1; i<n; i++){
        if(arr[max] < arr[i])
            max = i;
    }
    cout<<arr[max];
    // time complexity: O (2*10^5 + 10^7 + 10^)
}

/*
const int N = 1e5 + 5;
long double fact[N]; // will store upto 1.97926e+4930 i.e, 1754!
int main(){
    fact[0] = fact[1] = 1;
    for(int i=2; i<=N; i++)
        fact[i] = fact[i-1] * i;
    int n;
    // infinity assignment
    // long double inf = numeric_limits<long double>::infinity();
        cin>>n;
        cout<<fact[n];
}
*/

/*  GCDQ CODECHEF ---> using prefix sum but instead of sum we are calculating gcd.
    TEST CASE:
    1
3 3
2 6 9
1 1
2 2
2 3

int main(){
    int t, n, q;
    cin>>t;
    while(t--){
        cin>>n>>q;
        int arr[n+10];
        for(int i=1; i<=n; i++){
            cin>>arr[i];
        }
        int forward[n+10], backward[n+10];
        forward[0] = backward[n+1] = 0;

        for(int i=1; i<=n; i++)
            forward[i] = __gcd(forward[i-1], arr[i]);
        for(int i=n; i>=1; i--)
            backward[i] = __gcd(backward[i+1] ,arr[i]);
        
        while(q--){
            int l, r, gc;
            cin>>l>>r;
            cout<<__gcd(forward[l-1], backward[r+1])<<endl;
        }
    }
    
}
*/

// const int N = 1e3 + 10;
// int arr[N][N];
// long long pf[N][N];
// // prefix sum function
// // long long sum(int )
// int main(){
//     int n;
//     cin>>n;
//     for(int i=1; i<=n; i++)
//         for(int j=1; j<=n; j++){
//             cin>>arr[i][j];
//             pf[i][j] = arr[i][j] + pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1];
//         }
    
//     int q, a, b, c ,d;
//     cin>>q;
//     while(q--){
//         cin>>a>>b>>c>>d;
//         cout<<pf[c][d] - pf[a-1][d] - pf[c][b-1] + pf[a-1][b-1]<<endl;
//     }
// }

// /*
//     3
//     3 6 2
//     8 9 2
//     3 4 1
//     2
//     1 1 2 2
//     1 2 3 3
// */



