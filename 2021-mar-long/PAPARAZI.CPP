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
        long long N;
        cin >> N;
        vector<long long> heights(N);
        for (long long i = 0; i < N; i++) {
            cin >> heights[i];
        }

        if (N == 2) {
            cout << "1\n";
        } else {
            vector<pair<long long, long long>> pairs(N);
            for (long long i = 0; i < N; i++) {
                pairs[i] = {i + 1, heights[i]};
            }
            vector<pair<long long, long long>> H;
            H.push_back({1, heights[0]});
            H.push_back({2, heights[1]});
            int size = (int)H.size();
            long long ans = INT_MIN;
            for (int i = 2; i < N; i++) {
                while ((int)H.size() >= 2) {
                    double h = (double)pairs[i].second - (double)H[size - 1].second;
                    double b = (double)pairs[i].first - (double)H[size - 1].first;
                    double slope = h / b;
                    h = (double)H[size - 1].second - (double)H[size - 2].second;
                    b = (double)H[size - 1].first - (double)H[size - 2].first;
                    double slope2 = h / b;

                    if (slope2 > slope)
                        break;
                    if (slope2 <= slope) {
                        size--;
                        H.pop_back();
                    } else {
                        break;
                    }
                }
                size += 1;
                H.push_back(pairs[i]);
                if (H[size - 1].first - H[size - 2].first > ans) {
                    ans = H[size - 1].first - H[size - 2].first;
                }
            }
            cout << ans << '\n';
        }
    }

    return 0;
}