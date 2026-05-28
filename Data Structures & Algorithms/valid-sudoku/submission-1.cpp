class Solution {
public:

    bool checkRow(vector<vector<char>>& board, int r) {
        vector<int> seen(10, 0);

        for (int c = 0; c < 9; c++) {
            if (isdigit(board[r][c])) {
                int val = board[r][c] - '0';
                seen[val]++;
                if (seen[val] > 1) {
                    return false;
                }
            }
        }

        return true;
    }


    bool checkCol(vector<vector<char>>& board, int c) {
        vector<int> seen(10, 0);

        for (int r = 0; r < 9; r++) {
            if (isdigit(board[r][c])) {
                int val = board[r][c] - '0';
                seen[val]++;
                if (seen[val] > 1) {
                    return false;
                }
            }
        }

        return true;
    }

    bool checkSquare(vector<vector<char>>& board, int s) {
        vector<int> seen(10, 0);

        int x = 3 * (s / 3);
        int y = 3 * (s % 3);

        for (int r = x; r < x + 3; r++) {
            for (int c = y; c < y + 3; c++) {
                if (isdigit(board[r][c])) {
                    int val = board[r][c] - '0';
                    seen[val]++;
                    if (seen[val] > 1) {
                        return false;
                    }
                }
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        // for (int i = 0; i < 9; i++) {
        //     if (!checkRow(board, i) || !checkCol(board, i) || !checkSquare(board, i)) {
        //         return false;
        //     }
        // }

        vector<unordered_set<int>> rows(10), cols(10), sq(10);

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (isdigit(board[r][c])) {
                    int digit = board[r][c] - '0';
                    if (!rows[r].insert(digit).second) {
                        return false;
                    }
                    if (!cols[c].insert(digit).second) {
                        return false;
                    }
                    int sqId = 3 * (r / 3) + (c / 3) % 3;
                    if (!sq[sqId].insert(digit).second) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
