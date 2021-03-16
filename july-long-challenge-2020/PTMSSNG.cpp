// https://www.codechef.com/JULY20B/problems/PTMSSNG

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define endl '\n'

typedef long long ll;
typedef unsigned long long int ullu;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
   
    while (t--) {
        int N;
        cin >> N;
        unordered_map<int, int> X, Y;
        int loop = 4 * N - 1;
        while (loop--) {
            int x, y;
            cin >> x >> y;
            if (X[x] == 1) {
                X.erase(x);
            } else {
                X[x] = 1;
            }
            if (Y[y] == 1) {
                Y.erase(y);
            } else {
                Y[y] = 1;
            }
        }
        auto it_x = X.begin();
        auto it_y = Y.begin();
        cout << it_x -> first << " " << it_y -> first << endl;
    }
	
	return 0;
}
