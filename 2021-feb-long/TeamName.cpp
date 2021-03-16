#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#define MOD 1000000007
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long int ullu;

void print(vector<char> A) {
    cout << "V: ";
    for (auto a: A) cout << a << ' ';
    cout << '\n';
}
void print(unordered_set<char> A) {
    cout << "S: ";
    for (auto a: A) cout << a << ' ';
    cout << '\n';
}

int distinct_teams(vector<char> A, vector<char> B) {
    // print(A);
    // print(B);
    unordered_set<char> s(A.begin(), A.end());
    for (auto b: B) s.insert(b);
    // copy(s.begin(), s.end(), back_inserter(B));
    // print(s);
    return s.size();
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
        vector<string> names(N);
        for (int i = 0; i < N; i++) cin >> names[i];

        unordered_map<string , vector<char>> pairs;
        for (auto n: names) {
            string temp = n.substr(1);
            if (pairs.find(temp) != pairs.end()) pairs[temp].push_back(n[0]);
            else pairs[temp] = {n[0]};
        }
        
        int size = (int) pairs.size();
        vector<string> keys(size);
        int i = 0;
        for (auto p: pairs) {
            keys[i++] = p.first;
        }

        long long answer = 0;
        
        for (i = 0; i < size; i++) {
            for (int j = i+1; j < size; j++) {
                int temp_size = distinct_teams(pairs[keys[i]], pairs[keys[j]]);
                // cout << "temp " << temp_size << '\n';
                // print(pairs[keys[i]]);
                // cout << "i str " << keys[i] << '\n';
                // print(pairs[keys[j]]);
                // cout << "j str " << keys[j] << '\n';
                
                answer += (temp_size - (int) pairs[keys[i]].size()) * (temp_size - (int) pairs[keys[j]].size());
            }
        }
        answer *= 2;
        cout << answer << '\n';
    }

    return 0;
}