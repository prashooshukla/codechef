// https://www.codechef.com/JULY20B/problems/ADAKING

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define endl '\n'

typedef long long ll;
typedef unsigned long long int ullu;

const int row = 8;
const int col = 8;
void print(char arr[row][col]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j];
        } cout << endl;
    }
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
   
    while (t--) {
        int K;
        cin >> K;
        char x = 'X';
        char chess[row][row];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                chess[i][j] = '.';
            }
        }
        
        if (K == 64) {
            chess[0][0] = 'O';
            print(chess);
        } else if (K == 1) {
            chess[0][0] = 'O';
            chess[0][1] = x;
            chess[1][1] = x;
            chess[1][0] = x;
            print(chess);
        } else if (K % 8 == 0) {
            for (int i = 0; i < col; i++) {
                chess[K / 8][i] = x;
            } 
            chess[0][0] = 'O';
            print(chess);
        } else {
            int count = 0; 
            // for (int i = 0; i < row; i++) {
                
            //     for (int j = 0; j < col; j++) {
            //         if (count == K) break;
            //         chess[i][j] = 'a';
            //         ++count;
            //     }
            //     if (count == K) break;
            // }
            // int i = 0, j = 0;
            if (K < 8) {
                chess[0][K] = x;
                for (int i = K; i >= 0; i--) {
                    chess[1][i] = x;
                }
            } else {
                int alpha = K % 8;
                int beta = K / 8;
                for (int j = 0; j < col; j++) {
                    if (j <= alpha) {
                        chess[beta + 1][j] = x;
                        if (j == alpha) {
                            chess[beta][j] = x;
                        }
                    } else {
                        chess[beta][j] = x;
                    }
                }
            }
            // int xcount = 0;
            // for (int i = 0; i < row; i++) {
            //     // if (K % 8 == 0) break;
            //     for (int j = 0; j < col; j++) {
            //         if (chess[i][j] == 'a') {
            //             chess[i][j] = '.';
            //             ++xcount;
            //         }
            //         if (xcount == K) break;
            //     }
            //     if (xcount == K) break; 
            // }
            chess[0][0] = 'O';
            print(chess);
        }
        cout << '\n';
        
    }
	
	return 0;
}
