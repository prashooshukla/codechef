#include <iostream>
#include <vector>

#define MOD 1000000007
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long int ullu;

bool getPrime(long long N, long long Y) {
    vector<bool> primes(N + 1, true);

    for (int p = 2; p * p <= N; p++) {
        if (primes[p]) {
            for (int i = p * p; i <= N; i += p) {
                primes[i] = false;
            }
        }
    }
    vector<int> prime_count(N + 1, 0);
    int count = 0;
    for (int i = 2; i <= N; i++) {
        if (primes[i])
            ++count;
        prime_count[i] = count;
    }
    return prime_count[N] > Y;
}

vector<int> countPrimes(int N) {

    vector<int> A(N + 1);
    for (int i = 0; i <= N; i++) {
        A[i] = 0;
    }
    for (int i = 2; i * i <= N; i++) {
        for (int j = i + i; j <= N; j += i) {
            A[j] = 1;
        }
    }
    int cnt = 0;
    vector<int> primes(N+1, 0);
    for (int i = 2; i < N; i++) {
        if (A[i] == 0) {
            cnt++;
        }
        primes[i] = cnt;
    }

    return primes;
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string chef = "Chef";
    string divyam = "Divyam";
    int total = 1e6 + 5;
    auto primes = countPrimes(total);

    int tt;
    cin >> tt;
    while (tt--) {
        long long X, Y;
        cin >> X >> Y;

        if (primes[X] > Y) {
            cout << divyam << '\n';
        } else {
            cout << chef << '\n';
        }
    }

    return 0;
}