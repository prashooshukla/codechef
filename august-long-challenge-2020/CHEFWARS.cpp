// https://www.codechef.com/AUG20B/problems/CHEFWARS

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
        int H, P;
        cin >> H >> P;
        int to = 0; 
        while (P > 0) {
            to += P;
            P /= 2;
        }
        (to >= H) ? (cout << 1) : (cout << 0);
        cout << '\n';
    }
    
    return 0;
}