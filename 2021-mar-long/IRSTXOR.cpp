#include <bits/stdc++.h>

#define MOD 1000000007
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long int ullu;

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
      
    int tt;
    cin >> tt;
    while (tt--) {
        long long C;
        cin >> C;
        long long d = floor(log2(C)) + 1;
        long long A = (1 << (d - 1)) - 1;
        long long B = 1 << d;
        B = B - C;
        cout << A * (A + B) << '\n';

    }

    return 0;
}