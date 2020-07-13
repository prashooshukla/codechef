// https://www.codechef.com/JULY20B/problems/CHFNSWPS

#include <bits/stdc++.h>

#define MOD 1000000007
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long int ullu;

void print(map<long long, long long> mp) {
    for (auto m: mp) {
        cout << "m  " << m.first << " " << m.second << endl;
    }
}

void printu(vector<long long> V) {
    for (auto v: V) {
        cout << v << " ";
    } cout << '\n';
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int tt;
	cin >> tt;
    while (tt--) {
        int N;
        cin >> N;
        std::vector<long long> A(N);
        std::vector<long long> B(N);
        unordered_map<long long, long long> frequency;
        map<long long, long long> A_1;
        map<long long, long long> B_1;
        long long smallest = INT_MAX;
        for (int i = 0; i < N; i++) {
            cin >> A[i];
            frequency[A[i]]++;
            A_1[A[i]]++;
            smallest = min(smallest, A[i]);
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
            frequency[B[i]]++;
            B_1[B[i]]++;
            smallest = min(smallest, B[i]);
        }
        long long ans = 0;
        bool flag = true;
        for (auto m: frequency) {
            if (m.second % 2 != 0) {
                flag = false;
                ans = -1;
                break;
            }
        }
        if (flag) {
            map<long long, long long> extra_A;
            map<long long, long long> extra_B;
            long long A_unbalanced = 0;
            long long B_unbalanced = 0;
            for (auto a: A_1) {
                if (a.second > B_1[a.first]) {
                    extra_A[a.first] = (a.second - B_1[a.first]) / 2;
                    A_unbalanced += extra_A[a.first];
                }
            }
            for (auto b: B_1) {
                if (b.second > A_1[b.first]) {
                    extra_B[b.first] = (b.second - A_1[b.first]) / 2;
                    B_unbalanced += extra_B[b.first];
                }
            }
            vector<long long> alpha;
            vector<long long> beta;
            for (auto a: extra_A) {
                for (int i = 0; i < a.second; i++) {
                    alpha.push_back(a.first);
                }
            }
            for (auto a: extra_B) {
                for (int i = 0; i < a.second; i++) {
                    beta.push_back(a.first);
                }
            }
            // cout << "a: "; printu(alpha); cout << "b: "; printu(beta);
            reverse(beta.begin(), beta.end());
            int len = (int) alpha.size();
            for (int i = 0; i < len; i++) {
                // cout << "s: " << (2 * smallest) << " a: " << alpha[i] << " b: " << beta[i] << " r: " << min(2 * smallest, min(alpha[i], beta[i])) << endl;
                ans += min(2 * smallest, min(alpha[i], beta[i]));
            }
        } 
        
        cout << ans << endl;
    }
    
    return 0;
}