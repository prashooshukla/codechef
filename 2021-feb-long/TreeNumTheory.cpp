#include <bits/stdc++.h>

#define MOD 1000000007
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long int ullu;

class Node {
  public:
    long long val;
    vector<Node*> childs;
    Node(long long val);
};

Node::Node(long long val) {
    this->val = val;
}

// Node* newNode(int val) {
//     Node* temp = new Node(val);
//     return temp;
// }

void bfs(Node* root) {
    if (root == nullptr)
        return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int N = q.size();
        while (N > 0) {
            Node* p = q.front();
            q.pop();
            cout << p->val << ' ';
            for (int i = 0; i < p->childs.size(); i++) {
                q.push(p->childs[i]);
            }
            --N;
        } 
        cout << '\n';
    }
}

vector<Node*> constructTree(Node** root, vector<long long> parents, long long N) {
    vector<Node*> parentsPointer(N + 1, nullptr);
    *root = new Node(1);
    parentsPointer[1] = *root;
    long long pos = 2;
    for (long long i = 0; i < parents.size(); i++) {
        parentsPointer[pos] = new Node(i + 2);
        Node* temp = parentsPointer[parents[i]];
        temp->childs.push_back(parentsPointer[pos]);
        ++pos;
    }
    return parentsPointer;
}

void solve(Node* root, long long tasks, long long& finished) {
    if (root == nullptr)
        return;

    if (root->childs.size() == 0) {
        finished += tasks;
        return;
    } else if (root->childs.size() > 0) {
        int size = (int) root->childs.size();
        if (tasks % size != 0) return;
        else {
            for (int i = 0; i < size; i++) {
                solve(root->childs[i], tasks / size, finished);
            }
        }
    }

}

int main() {
    // your code goes here
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int N;
    cin >> N;
    vector<long long> A(N - 1);
    for (int i = 0; i < N - 1; i++) {
        cin >> A[i];
    }

    Node* root = nullptr;
    vector<Node*> parentsPointer = constructTree(&root, A, N);
    bfs(root);

    // for (int i = 1; i < parentsPointer.size(); i++) {
    //     cout << i << ' ' << parentsPointer[i]->val << '\n';
    // }

    long long Q;
    cin >> Q;
    while (Q--) {
        long long V, W;
        cin >> V >> W;
        long long finished = 0;
        solve(parentsPointer[V], W, finished);
        cout << W - finished << '\n';
        // todo
    }

    return 0;
}