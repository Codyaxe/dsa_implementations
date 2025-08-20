#include <map>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<char, int> colfreq {};
        map<char, int> rowfreq {};
        map<char, int> threeby {};
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
            cout << "{ " << board[j/2][j % 2] << " " << board[j][i] <<
            " " << board[i][j] << " }";
            if (board[j][i] != '.'){
                ++colfreq[board[j][i]];
            }
            if (board[i][j] != '.'){
                ++rowfreq[board[i][j]];
            }
            if (board[j/3][(j + (i * 3) ) % 3] != '.'){
                ++threeby[board[j/3][j % 3]];
                cout << "Again: " << board[j/3][j % 3] << " "<<  j/3 <<
                " " << j%3  << '\n';
                cout << j << '\n';
            }
            if (threeby[board[j/3][j%3]] > 1 || colfreq[board[j][i]] > 1|| rowfreq[board[i][j]] > 1){
                return 0;
            }
            }
            cout << "\n";
            colfreq.clear();
            rowfreq.clear();
            threeby.clear();
        }
        return 1;
    }
};