// https://www.codechef.com/JULY20B/problems/CHEFSTR1

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
	
	int t;
	cin >> t;
   
    while (t--) {
        int N;
        cin >> N;
        std::vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        long long ans = 0;
        for (int i = 1; i < N; i++) {
            if (A[i] == A[i - 1]) continue;
            ans += abs(A[i] - A[i - 1]) - 1;
        }
        cout << ans << endl;
    }
	
	return 0;
}
