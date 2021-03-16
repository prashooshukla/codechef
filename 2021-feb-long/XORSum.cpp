#include <iostream>
#include <vector>

#define MOD 998'244'353
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long int ullu;

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<long long> A(N);
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }

    // todo
    

    int Q;
    cin >> Q;
    while (Q--) {
        int M;
        cin >> M;
    }

    return 0;
}