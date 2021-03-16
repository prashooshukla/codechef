#include <bits/stdc++.h>

#define MOD 1000000007
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long int ullu;

long long lower(vector<long long> A, long long X) {
    long long N = (long long)A.size();
    long long L = 0;
    long long R = N;
    while (L < R) {
        long long mid = L + (R - L) / 2;
        if (X <= A[mid]) {
            R = mid;
        } else {
            L = mid + 1;
        }
    }
    return L;
}

long long upper(vector<long long> A, long long X) {
    long long N = (long long)A.size();
    long long L = 0;
    long long R = N;
    while (L < R) {
        long long mid = L + (R - L) / 2;
        if (X >= A[mid]) {
            L = mid + 1;
        } else {
            R = mid;
        }
    }
    return L - 1;
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while (tt--) {
        long long N, E, H, A, B, C;
        cin >> N >> E >> H >> A >> B >> C;

        vector<long long> indexes;
        for (int i = 0; i <= N + 1; i++) {
            indexes.push_back(i);
        }
        vector<long long> prices;
        long long k = lower(indexes, H);
        long long alt = upper(indexes, E);
        for (long long i = 0; i <= N; i++) {
            long long price1 = upper_bound(indexes.begin(), indexes.end(), (H - 3 * i)) - indexes.begin() - 1;
            long long price = lower_bound(indexes.begin(), indexes.end(), (2 * N - E - 2 * i)) - indexes.begin();

            if (price1 == N + 1 and price1 + 3 * i > H)
                continue;
            if (price1 < price or price == N + 1)
                continue;

            k = 0;
            if (C > A) {
                if (price < (N - i)) {
                    k = price;
                } else {
                    k = N - i;
                }
                k = (price < (N - i) ? price : (N - i));
            } else {
                if (price1 < N - i) {
                    k = price1;
                } else {
                    k = N - i;
                }
                k = (price1) < (N - i) ? price1 : (N - i);
            }

            alt = N - k - i;
            if (k + 2 * i >= 2 * N - E and k + 3 * i <= H) {
                prices.push_back(A * alt + B * i + C * k);
                // cout << "cahla" << '\n';
            }
        }

        if ((long long)prices.size() == 0) {
            cout << "-1\n";
        } else {
            long long mini = INT_MAX;
            for (long long i = 0; i < (long long)prices.size(); i++) {
                mini = min(mini, prices[i]);
            }
            cout << mini << '\n';
        }
    }

    return 0;
}