// https://www.codechef.com/AUG20B/problems/SUBSFREQ

#include <bits/stdc++.h>

#define MOD 1'000'000'007
#define endl '\n'
#define input(n) for(auto&a:n)cin>>a
using namespace std;

typedef long long ll;
typedef unsigned long long int ullu;

int power(int x, int y) {  
    int res = 1;
//   pppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp
    x = x % MOD;
    if (x == 0) return 0;; 
    while (y > 0) {  
        if (y & 1)  
            res = (res * x) % MOD;  
        y = y >> 1;
        x = (x * x) % MOD;  
    }  
    return res;  
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
        vector<int> A(N);
        input(A);
        vector<int> ans (N, 1);
        for (int i = 1; i < N; i++) {
            ans[i] = (ans[i - 1] * 2) % MOD;
        }
        reverse(ans.begin(), ans.end());
        for (auto a: ans) {
            cout << a << ' ';
        } cout << endl;
        // for (auto a: A) cout << a << " "; cout << endl;
    }   
    return 0;
}