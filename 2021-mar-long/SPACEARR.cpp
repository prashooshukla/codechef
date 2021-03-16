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

    string first = "First";
    string second = "Second";

    int tt;
    cin >> tt;
    while (tt--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        sort(A.begin(), A.end());

        long long count = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] > (i + 1)) {
                count = INT_MIN;
                break;
            } else {
                count += i + 1 - A[i];
            }
        }

        if (count == INT_MIN) {
            cout << second;
        } else {
            if (count & 1)
                cout << first;
            else
                cout << second;
        }
        cout << '\n';
    }

    return 0;
}