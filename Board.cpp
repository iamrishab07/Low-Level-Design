class Board {
public:
    std::vector <vector<char>> squares;
    string boardStatus = "EMPTY";
    int size;

    Board() {
        int n = 3;
        for (int i = 0; i < n; i++) {
            vector<char> sub;
            for (int j = 0; j < n; j++) {
                sub.push_back('-');
            }
            this->squares.push_back(sub);
        }
    }

    void updateBoardStatus(string status) {
        this->boardStatus = status;
    }

    void markOnBoard(Move *move) {
        int row = move->row;
        int col = move->col;

        this->squares[row - 1][col - 1] = move->mark;
    }

    string getBaordStatus() {
        return this->boardStatus;
    }

    void initialize() {
        int row = this->squares.size();
        int col = this->squares[0].size();
        this->size = row * col;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                this->squares[i][j] = '-';
            }
        }
    }

    void showBoard() {
        int row = this->squares.size();
        int col = this->squares[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cout << this->squares[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl;
    }

    bool checkForBoardMatch() {
        return checkForHorizontalMatch() || checkForVerticalMatch() || checkForDiagonalMatch();
    }


    bool checkForHorizontalMatch() {
        int row = this->squares.size();
        int col = this->squares[0].size();

        for (int i = 0; i < row; i++) {
            char c = this->squares[i][0];
            if (c == '-') continue;
            bool rowRes = true;

            for (int j = 1; j < col; j++) {
                if (this->squares[i][j] == c && this->squares[i][j] != '-') rowRes &= true;
                else rowRes &= false;
            }
            if (rowRes) return true;
        }
        return false;
    }

    bool checkForVerticalMatch() {
        int row = this->squares.size();
        int col = this->squares[0].size();

        for (int i = 0; i < col; i++) {
            char c = this->squares[0][col];
            if (c == '-') continue;
            bool rowRes = true;

            for (int j = 1; j < row; j++) {
                if (this->squares[j][i] == c && this->squares[j][i] != '-') rowRes &= true;
                else rowRes &= false;
            }
            if (rowRes) return true;
        }
        return false;
    }

    bool isValidMove(int row, int col) {
        return this->squares[row - 1][col - 1] == '-';
    }

    bool checkForDiagonalMatch() {
        int row = this->squares.size();
        int col = this->squares[0].size();
        char c = this->squares[0][0];
        if (c == '-') return false;

        for (int i = 0; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (i == j && this->squares[i][j] != c) return false;
            }
        }

        return true;
    }

};