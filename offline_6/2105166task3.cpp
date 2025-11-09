#include <iostream>
#include <queue>
#include <climits>
#include <vector>
using namespace std;

struct Rider {
    int k;
    int rows;
    int cols;
    vector<vector<int>> board;
    queue<pair<int, int>> q;

    Rider(int rows, int cols, int x, int y, int k) {
        this->k = k;
        this->rows = rows;
        this->cols = cols;
        board.assign(rows, vector<int>(cols, -1));
        bfs(make_pair(x, y));
    }

    int getSteps(pair<int, int> pos) {
        return board[pos.first][pos.second];
    }

    void setSteps(pair<int, int> pos, int steps) {
        board[pos.first][pos.second] = steps;
    }

    bool isValidPos(pair<int, int> pos) {
        return (pos.first >= 0 && pos.first < rows && pos.second >= 0 && pos.second < cols);
    }

    void exploreNextMoves(pair<int, int> pos) {
        int xDiffs[] = {1, 1, -1, -1, 2, -2, 2, -2};
        int yDiffs[] = {2, -2, 2, -2, 1, 1, -1, -1};

        for (size_t i = 0; i < 8; i++) {
            pair<int, int> newPos = make_pair(pos.first + xDiffs[i], pos.second + yDiffs[i]);
            if (isValidPos(newPos)) {
                if (getSteps(newPos) == -1) {
                    setSteps(newPos, getSteps(pos) + 1);
                    q.push(newPos);
                }
            }
        }
    }

    void bfs(pair<int, int> startPos) {
        setSteps(startPos, 0);
        q.push(startPos);

        while (!q.empty()) {
            auto pos = q.front();
            q.pop();
            exploreNextMoves(pos);
        }
    }
};

int calcMinMoves(int rows, int cols, const vector<Rider *> &riders) {
    int minMove = INT_MAX;

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            int moveSum = 0;
            bool valid = true;

            for (const auto rider : riders) {
                if (rider->board[i][j] == -1) {
                    valid = false;
                    break;
                }
                moveSum += (rider->getSteps(make_pair(i, j)) + rider->k - 1) / rider->k;
            }

            if (valid) {
                minMove = min(minMove, moveSum);
            }
        }
    }

    return minMove;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int rows, cols, q;
    cin >> rows >> cols >> q;

    vector<Rider *> riders;
    for (size_t i = 0; i < q; i++) {
        int x, y, k;
        cin >> x >> y >> k;

        Rider *rider = new Rider(rows, cols, x, y, k);
        riders.push_back(rider);
    }

    int minMove = calcMinMoves(rows, cols, riders);

    if (minMove == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << minMove << endl;
    }

    for (Rider *rider : riders) {
        delete rider;
    }

    return 0;
}
