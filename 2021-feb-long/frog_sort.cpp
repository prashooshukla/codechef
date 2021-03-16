#include <iostream>
#include <map>
#include <utility>
#include <vector>

#define MOD 1000000007
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long int ullu;

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while (tt--) {
        int N;
        cin >> N;
        vector<int> W(N);
        for (int i = 0; i < N; i++)
            cin >> W[i];
        vector<int> L(N);
        for (int i = 0; i < N; i++)
            cin >> L[i];
        map<int, pair<int, int>> pairs;
        for (int i = 0; i < N; i++) {
            pairs.insert({W[i], {L[i], i}});
        }
        int ans = 0;
        int curr_pos;
        for (auto m: pairs) {
            if (m.first == 1) curr_pos = m.second.second;
            else {
                int current_index = m.second.second;
                while (curr_pos >= current_index) {
                    current_index += m.second.first;
                    ++ans;
                }
                curr_pos = current_index;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}