// https://www.codechef.com/JULY20B/problems/CRDGAME

#include <bits/stdc++.h>

#define MOD 1000000007
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long int ullu;

long long num_sum(long long N) {
    long long sum = 0;
    if (N <= 9) return N;
    while (N > 0) {
        sum += (N % 10);
        N /= 10;
    }
    return sum;
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
   
    while (t--) {
        int N;
        cin >> N;
        long long chef = 0;
        long long morty = 0;
        while (N--) {
            long long A, B;
            cin >> A >> B;
            long long sum_a = num_sum(A);
            long long sum_b = num_sum(B);
            if (sum_a > sum_b) chef++;
            else if (sum_b > sum_a) morty++;
            else {
                chef++;
                morty++;
            }
        }
        if (chef > morty) {
            cout << "0 " << chef << endl;
        } else if (morty > chef) {
            cout << "1 " << morty << endl;
        } else {
            cout << "2 " << chef << endl;
        }
    }
	
	return 0;
}
