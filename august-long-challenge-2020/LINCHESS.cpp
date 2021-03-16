// https://www.codechef.com/AUG20B/problems/LINCHESS

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
        int N, K, input;
        cin >> N >> K;
        vector<int> P(N);
        for (int i = 0; i < N; i++) {
            cin >> P[i];
        }
        auto flag = false;
        auto mini = INT_MAX;
        int solution;
        for (int i = 0; i < N; i++) {
            if (P[i] <= K) {
                if (K % P[i]) {
                    if (K / P[i] < mini) {
                        mini = K / P[i];
                        solution = P[i];
                    }
                }
            }
        }
        (mini < INT_MIN) ? (cout << solution) : (cout << -1);
        cout << endl;
    }

    return 0;
}