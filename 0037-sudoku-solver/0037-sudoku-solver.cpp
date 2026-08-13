// class Solution {
// public:
//     bool can(vector<vector<char>>& board,int r,int c,char ch){
//         for(int i=0;i<9;i++){
//             if(board[r][i]==ch) return false;
//             if(board[i][c]==ch) return false;
//             if(board[3*(r/3)+i/3][3*(c/3)+i%3]==ch) return false;
//         }
//         return true;
//     }
//     bool fun(vector<vector<char>>& board){
//         for(int i=0;i<board.size();i++){
//             for(int j=0;j<board[0].size();j++){
//                 if(board[i][j]=='.'){
//                     for(char ch='1';ch<='9';ch++){
//                         if(can(board,i,j,ch)){
//                             board[i][j]=ch;
//                             if(fun(board)==true) return true;
//                             else board[i][j]='.';
//                         }
//                     }
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
//     void solveSudoku(vector<vector<char>>& board) {
//         fun(board);
//     }
// };



struct Set {
    
    static const int16_t COMMITED = 1 << 12;
    static const int16_t INITIAL  = (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5) |
                                    (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);
    
    int16_t _data;
    
    Set() : _data(INITIAL) {}
    
    inline void solve(int n)                  { _data = 1 << n; }
    inline int  first()                 const { for (int i = 1; i <= 9; i++) { if (_data & (1 << i)) { return i; } } return 0; }
    inline int  value()                 const { return is_solved() ? first() : -1; }
    
    inline void commit()                      { _data |= COMMITED; }
    inline bool is_commited()           const { return (_data & COMMITED) > 0; }
    inline int  count()                 const { return __builtin_popcount(_data & ~COMMITED); }
    
    inline bool is_solved()             const { return count() == 1; }
    inline bool is_empty()              const { return count() == 0; }
    inline bool is_solved_uncommited()  const { return is_solved() && !is_commited(); }
    inline bool has_candidate(int n)    const { return (_data & (1 << n)) > 0; }
    inline void remove_candidate(int n)       { _data &= ~(1 << n); }
};

struct Space {

    typedef array<Set, 9 * 9> data_t;
    typedef pair<int, int>    index_t;

    data_t   _data;
    bool     _failed;

    Space() : _failed(false) {}
    
    inline static int            _index(int col, int row) { return row * 9 + col; }
    inline static pair<int, int> _col_row(int index)      { return pair<int, int>(index % 9, index / 9); }

    inline Set &_at(int col, int row) { return _data[_index(col, row)]; }
    inline Set &_at(int index)        { return _data[index]; }
    
    void _remove(int index, int n) {
        _data[index].remove_candidate(n);
        if (_data[index].is_empty()) {
            _failed = true;
        }
    }

    void _update_row(int col, int row, int n) {
        for (int c = 0; c < 9; c++) {
            if (col != c) {
                _remove(_index(c, row), n);
            }
        }
    }

    void _update_column(int col, int row, int n) {
        for (int r = 0; r < 9; r++) {
            if (row != r) {
                _remove(_index(col, r), n);
            }
        }
    }

    void _update_box(int col, int row, int n) {
        int section = col / 3 + (row / 3) * 3,
            start_c = (section % 3) * 3,
            start_r = (section / 3) * 3;
        for (int r = start_r; r < start_r + 3; r++) {
            for (int c = start_c; c < start_c + 3; c++) {
                if (r != row || c != col) {
                    _remove(_index(c, r), n);
                }
            }
        }
    }

    void solve(int col, int row, int n) {
        _at(col, row).solve(n);
        _update_row(col, row, n);
        _update_column(col, row, n);
        _update_box(col, row, n);
        _at(col, row).commit();
    }

    bool is_failed() {
        return _failed;
    }

    bool is_complete() {
        for (int i = 0; i < 9 * 9; i++) {
            if (!_data[i].is_solved()) {
                return false;
            }
        }
        return true;
    }
    
    int _best_index() {
        int best = -1;
        for (int i = 0, best_count = 10; i < 9 * 9; i++) {
            int count = _data[i].count();
            if (count > 1 && count < best_count) {
                best = i;
                best_count = count;
                if (best_count == 2) {
                    return best;
                }
            }
        }
        return best;
    }

    bool attempt_resolve(int col, int row, int n, int depth)
    {
        solve(col, row, n);
        commit();
        if (is_failed()) {
            return false;
        }
        if (is_complete()) {
            return true;
        }
        resolve_best(depth + 1);
        if (is_failed()) {
            return false;
        }
        return !is_failed();
    }
    
    bool resolve_best(int depth = 0)
    {
        int best = _best_index();
        if (best == -1) {
            return false;
        }
        auto p = _col_row(best);
        Set &op = _data[best];
        for (int n = 1; n <= 9; n++) {
            if (op.has_candidate(n)) {
                Space space = *this;
                if (space.attempt_resolve(p.first, p.second, n, depth)) {
                    *this = space;
                } else {
                    _remove(best, n);
                    if (_data[best].is_solved_uncommited()) {
                        commit();
                    }
                }
                return true;
            }
        }
        return false;
    }
    
    bool solve() {
        commit();

        if (is_failed()) return false;
        if (is_complete()) return true;

        int best = _best_index();
        Set &options = _data[best];
        auto [col, row] = _col_row(best);

        for (int n = 1; n <= 9; n++) {
            if (options.has_candidate(n)) {
                Space branch = *this;
                branch.solve(col, row, n);

                if (branch.solve()) {
                    *this = branch;
                    return true;
                }
            }
        }

        return false;
    }

    bool commit()
    {
        if (is_failed()) {
            return false;
        }
        int committed;
        do {
            committed = 0;
            for (int i = 0; i < 9 * 9; ++i) {
                if (_data[i].is_solved_uncommited()) {
                    auto p = _col_row(i);
                    solve(p.first, p.second, _data[i].value());
                    committed++;
                    if (is_failed()) {
                        return false;
                    }
                }
            }
        } while (committed > 0);
        return !is_failed();
    }
    
    void write()
    {
        for (int j = 0; j < 9; j++) {
            for (int i = 0; i < 9; i++) {
                auto val = _data[_index(i, j)].value();
                if (val == -1) {
                    cout << " ";
                } else {
                    cout << val;
                }
                cout << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    
    // board info

    void init_from_board(const vector<vector<char>>& board)
    {
        // init with known values
        for (int j = 0; j < 9; j++) {
            for (int i = 0; i < 9; i++) {
                auto val = board[j][i];
                if (val != '.') {
                    solve(i, j, val - '0');
                }
            }
        }
    }

    void update_board(vector<vector<char>>& board)
    {
        for (int j = 0; j < 9; j++) {
            for (int i = 0; i < 9; i++) {
                board[j][i] = char(_at(i, j).value() + '0');
            }
        }
    }
};

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        Space space;
        space.init_from_board(board);
        space.solve();
        space.update_board(board);
    }
};
