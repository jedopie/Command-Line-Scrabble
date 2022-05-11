#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    vector<vector<string>> board;


    for (int i = 0; i < 15; i++) {
        vector<string> row;
        for (int j = 0; j < 15; j++) {
            if (j == 0)
            row.push_back("|  |");
            else
            row.push_back("  |");
            
        }
        board.push_back(row);
    }

    for (char i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            cout << board[i][j].c_str();
        }
        cout << "\n";
    }

    return 0;
    }