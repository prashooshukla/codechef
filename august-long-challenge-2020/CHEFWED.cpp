// https://www.codechef.com/AUG20B/problems/CHEFWED

#include <bits/stdc++.h>

#define MOD 1'000'000'007
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long int ullu;

vector<vector<int>> get_min_efficiency(vector<vector<int>> L, int N) {
    vector<vector<int>> efficiency (101, vector<int>(101, 0));
    // long long ans = UINT64_MAX;
    int pair = 1e2;
    for (int i = 1; i <= N; i++) {
        efficiency[1][i] = L[0][i - 1];
    }
    for (int i = 2; i < pair; i++) {
        efficiency[i][1] = 0;
    }
    for (int i = 2; i < pair; i++) {
        for (int j = 2; j < N; j++) {
            int temp = INT_MAX;
            for (auto k = 1; k < j; ++k) {
                temp = min(efficiency[i - 1][k] + L[k][j - 1], temp);
            }
            efficiency[i][j] = temp;
        }
    }
    return efficiency;
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while (tt--) {
        int N, K;
        cin >> N >> K;
        vector<int> F(N);
        for (int i = 0; i < N; i++) {
            cin >> F[i];
        }
        vector<vector<int>> L(N + 1, vector<int> (N + 1, 0));
        for (auto i = 0; i < N; i++) {
            unordered_map<int, int> M;
            for (auto j = i; j < N; j++) {
                if (j == 0) L[i][j] = 0;
                else L[i][j] = L[i][j - 1];
                if (M.count(F[j])) {
                    if (M[F[j]] == 1) L[i][j]++;
                    L[i][j] += 1;
                }
                M[F[j]]++;
            }
        }
        auto d = get_min_efficiency(L, N);
        auto count = INT_MAX;
        for (int t = 1; t < 100; t++) {
            count = min(count, t * K + d[t][N]);
        }
        cout << count << endl;
    }

    return 0;
}