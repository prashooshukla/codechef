#include <bits/stdc++.h>

#define MOD 1000000007
#define endl '\n'
#define watch(x) cout << (#x) << " is " << (x) << endl

using namespace std;

typedef long long ll;
typedef unsigned long long int ullu;

vector<long long> pp1;
vector<long long> pp2;

bool isInRange(long long a, long long b) {
    for (long long i = 0; i < (ll)pp1.size(); i++) {
        if (pp1[i] <= b and pp2[i] >= a) {
            return true;
        }
    }
    return false;
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while (tt--) {
        long long N, M, X, Y;
        cin >> N >> M >> X >> Y;
        vector<long long> A(M);
        vector<long long> B(M);
        vector<long long> C(M);
        vector<long long> D(M);

        for (long long i = 0; i < M; i++) {
            cin >> A[i] >> B[i] >> C[i] >> D[i];
        }
        if (X == Y) {
            cout << 0 << '\n';
            continue;
        }
        long long z = 0;
        vector<long long> di(M);
        long long ans = -1;
        long long v = -1;                              
        vector<long long> l(M);
        vector<long long> quant1(1, X);
        vector<long long> quant2(1, X);
        while (ans == -1 and (int) quant1.size() != 0) {
            pp1.clear();
            pp1 = quant1;
            pp2.clear();
            pp2 = quant2;
            vector<long long> wieght1, weight2;
            for (long long i = 0; i < M; i++) {
                if (di[i] == 0 and isInRange(A[i], B[i])) {
                    wieght1.push_back(C[i]);
                    weight2.push_back(D[i]);
                    if (C[i] <= Y and D[i] >= Y) {
                        ans = z + 1;
                        v += z;
                        l[i] = ans;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
                    }
                    di[i] = 1;
                }
            }
            quant1 = wieght1;
            quant2 = weight2;
            // l.push_back(z);
            z++;
        }
        // sort(l.begin(), l.end());
        cout << ans << '\n';
    }

    return 0;
}