#include <bits/stdc++.h>

#define MOD 1'000'000'007
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
        int N;
        int Q;
        int M;
        cin >> N >> Q >> M;
        vector<int> A(N);
        for (auto& a : A) cin >> a;
        map<pair<int, int>, int> pairs;
        vector<int> best(1'000'001, 0);
        while (Q--) {
            int L;
            int R;
            cin >> L >> R;
            L -= 1;
            R -= 1;
            if (M < A[L]) continue;
            else if (A[L] <= M and A[R] > M) {
                best[A[L]] += 1;
                best[M + 1] -= 1;
            } else {
                best[A[L]] += 1;
                best[M + 1] -= 1;
                pairs[make_pair(A[L], A[R])] += 1;
            }
        }
        for (auto p: pairs) {
            int first = p.first.first;
            int second = p.first.second;
            int tur = p.second;
            int d = second + first;
            best[d] -= tur;
            int e = second + 2 * first;
            best[e] += tur;
            int temp = second + 2 * first;
            while (temp + second <= M) {
                temp += second;
                best[temp] -= tur;
                temp += first;
                best[temp] += tur;
            }
        }
        int ans = INT_MIN;
        for (int i = 1; i <= M; i++) {
            best[i] = best[i] + best[i-1];
            ans = max(best[i], ans);
        }
        cout << ans << '\n';
    }

    return 0;
}