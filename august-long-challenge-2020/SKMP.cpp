// https://www.codechef.com/AUG20B/problems/SKMP

#include <bits/stdc++.h>

#define MOD 1000000007
#define endl '\n'
#define MAX_CHAR 26

using namespace std;

typedef long long ll;
typedef unsigned long long int ullu;

void print (int A[]) {
    for (int i = 0; i < MAX_CHAR; i++) {
        if (A[i] > 0) {
            cout << (char) ('a' + i) << ' ';
        }
    }
    cout << endl;
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int tt;
	cin >> tt;
    while (tt--) {
        string S;
        cin >> S;
        string P;
        cin >> P;
        int count_S[26] = {0};
        // int count_P[26] = {0};
        for (int i = 0; i < S.length(); i++) {
            count_S[S[i] - 'a']++;
        }
        // print(count_S);
        for (int i = 0; i < P.length(); i++) {
            // count_P[P[i] - 'a']++;
            count_S[P[i] - 'a']--;
        }
        // print(count_S);
        
        string op1 = "", op2 = "";
        int indice = P[0] - 'a';
        int last_indice = P[P.length() - 1] - 'a';
        auto flag = true;
        for (int i = 0; i < MAX_CHAR; i++) {
            if (i == indice) {
                op1.append(P);
            }
            for (int j = 0; j < count_S[i]; j++) {
                char c = (char) ('a' + i);
                op1.push_back(c);
                op2.push_back(c);
            }
            if (i == indice) {
                op2.append(P);
            }
        }
        if (lexicographical_compare(op1.begin(), op1.end(), op2.begin(), op2.end())) {
            cout << op1 << '\n';
        } else {
            cout << op2 << '\n';
        }
    }
    
    return 0;
}