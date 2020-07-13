// https://www.codechef.com/JULY20B/problems/DRCHEF/

#include <bits/stdc++.h>

#define MOD 1000000007
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long int ullu;

long long get_days(vector<long long>::iterator pos, vector<long long>& A, long long x) {
    long long days = 0;
    for (auto it = pos; it != A.end(); it++) {
        long long val = *it;
        while (true) {
            // cout << x << " x ";  
            ++days;
            if (x >= *it) {
                x = *it;
                // ++days;
                break;
            }
              x *= 2;
        }
        // cout << endl;
        x *= 2;
    }
    // cout << "d " << pos - A.begin() << endl;
    return days += pos - A.begin();
        // return days;
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int tt;
	cin >> tt;
    while (tt--) {
        long long N, x;
        cin >> N >> x;
        std::vector<long long> A(N);
        for (int i = 0; i < N; i++) cin >> A[i];
        long long days = INT_MAX;
        sort(A.begin(), A.end());
        auto pos = lower_bound(A.begin(), A.end(), x);
        for (auto it = A.begin(); it != pos; it++) {
            // cout << "for " << *it;
            auto alpha = get_days(it, A, x);
            days = min(days, alpha);
            // cout << "  days " << alpha << endl;
        }
        days = min(days, get_days(pos, A, x));
        
        cout << days << endl;
    }
    
    return 0;
}