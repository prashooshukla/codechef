// https://www.codechef.com/AUG20B/problems/CRDGAME3

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
        int Pc, Pr;
        cin >> Pc >> Pr;
        long long chef, rick;
        chef = (Pc / 9) + ((Pc % 9 == 0) ? 0 : 1);
        rick = (Pr / 9) + ((Pr % 9 == 0) ? 0 : 1);
        if (chef == rick) {
            cout << "1 " << rick;
        } else if (chef < rick) {
            cout << "0 " << chef;
        } else if (chef > rick) {
            cout << "1 " << rick;
        }
        cout << endl;
    }
    
    return 0;
}