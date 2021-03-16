#include <bits/stdc++.h>

#define MOD 1000000007
#define endl '\n'
#define watch(x) cout << (#x) << " is " << (x) << endl

using namespace std;

typedef long long ll;
typedef unsigned long long int ullu;

void print(vector<vector<long long>> A, string s) {
    cout << "Matrix: " << s << '\n';
    for (auto a : A) {
        for (auto i : a) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}

bool check(vector<vector<long long>> A, vector<vector<long long>> B, long long r, long long c) {
    for (long long i = 0; i < r; i++) {
        for (long long j = 0; j < c; j++) {
            if (A[i][j] != B[i][j])
                return false;
        }
    }
    return true;
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string yes = "Yes";
    string no = "No";
    int tt;
    cin >> tt;
    while (tt--) {
        long long r, c, x;
        cin >> r >> c >> x;
        vector<vector<long long>> a(r, vector<long long>(c));
        for (long long i = 0; i < r; i++) {
            for (long long j = 0; j < c; j++) {
                cin >> a[i][j];
            }
        }

        // print(a, "a");
        vector<vector<long long>> b(r, vector<long long>(c));
        for (long long i = 0; i < r; i++) {
            for (long long j = 0; j < c; j++) {
                cin >> b[i][j];
            }
        }
        // print(b, "B");
        long long k = INT_MAX;
        if (c < x and r < x) {
            bool temp = check(a, b, r, c);
            if (temp) {
                cout << yes;
            } else
                cout << no;
        } else if (r < x) {
            long long diff;
            for (long long i = 0; i < r; i++) {
                for (long long j = 0; j <= (c - x); j++) {
                    if (a[j][i] == b[i][j]) {
                        continue;
                    } else {
                        diff = b[i][j] - a[i][j];
                        a[i][j] += diff;
                        k = 1;
                        while (k < x) {
                            a[i][j + k] += diff;
                            k += 1;
                        }
                    }
                }
            }
            if (check(a, b, r, c))
                cout << yes;
            else
                cout << no;
        } else if (c < x) {
            long long diff;
            for (long long i = 0; i < c; i++) {
                for (long long j = 0; j <= (r - x); j++) {
                    if (a[j][i] == b[j][i]) {
                        continue;
                    } else {
                        diff = b[j][i] - a[j][i];
                        a[j][i] += diff;
                        k = 1;
                        while (k < x) {
                            a[j + k][i] += diff;
                            k++;
                        }
                    }
                }
            }
            if (check(a, b, r, c))
                cout << yes;
            else
                cout << no;
        } else if (r >= x and c >= x) {
            long long diff;
            for (long long i = 0; i < r; i++) {
                for (long long j; j <= (c - x); j++) {

                    if (a[i][j] == b[i][j]) {
                        continue;
                    } else {
                        diff = b[i][j] - a[i][j];
                        a[i][j] += diff;
                        k = 1;
                        while (k < x) {
                            a[i][j + k] += diff;
                            ++k;
                        }
                    }
                }
            }
            for (long long i = 0; i < c; i++) {
                for (long long j = 0; j < r - x; j++) {
                    if (a[j][i] == b[j][i]) {
                        continue;
                    } else {
                        diff = b[j][i] - a[j][i];
                        a[j][i] += diff;
                        k = 1;
                        while (k < x) {
                            a[j + k][i] += diff;
                            k += 1;
                        }
                    }
                }
            }
            if (check(a, b, r, c))
                cout << yes;
            else
                cout << no;
        }
        cout << '\n';
    }

    return 0;
}