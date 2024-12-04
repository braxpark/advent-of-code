#include <bits/stdc++.h>
using namespace std;


bool isXmas(vector<char> chars) {
    return chars[0] == 'X' and chars[1] == 'M' and chars[2] == 'A' and chars[3] == 'S';
}

int main() {
    ifstream inTest("../test.txt");
    ifstream inTest2("../test_2.txt");
    ifstream inInput("../input.txt");
    ifstream& data = inInput;
    int numOccurences = 0, part2Occurences = 0;
    vector<vector<char>> grid;
    string line;
    while(getline(data, line)) {
        vector<char> curr(line.size());
        for(int i = 0; i < line.size(); i++) curr[i] = line[i];
        grid.push_back(curr);
    }
    
    for(int i = 0; i < grid.size(); i++) {
        vector<char> row = grid[i];
        for(int k = 0; k < row.size(); k++) {
            char c = row[k];
            if(c != 'X') continue;
            // up
            if(i >= 3) {
                numOccurences += isXmas({grid[i][k], grid[i - 1][k], grid[i - 2][k], grid[i - 3][k]}) ? 1 : 0;

                // up and right
                if(k < row.size() - 3) {
                    numOccurences += isXmas({grid[i][k], grid[i - 1][k + 1], grid[i - 2][k + 2], grid[i - 3][k + 3]}) ? 1 : 0;
                }

                // up and left
                if (k >= 3) {
                    numOccurences += isXmas({grid[i][k], grid[i - 1][k - 1], grid[i - 2][k - 2], grid[i - 3][k - 3]}) ? 1 : 0;
                }
            }
            // left
            if (k >= 3) {
                numOccurences += isXmas({grid[i][k], grid[i][k - 1], grid[i][k - 2], grid[i][k - 3]}) ? 1 : 0;
            }

            // right
            if(k < row.size() - 3) {
                numOccurences += isXmas({grid[i][k], grid[i][k + 1], grid[i][k + 2], grid[i][k + 3]}) ? 1 : 0;
            }
            
            // down
            if(i < row.size() - 3) {
                numOccurences += isXmas({grid[i][k], grid[i + 1][k], grid[i + 2][k], grid[i + 3][k]}) ? 1 : 0;

                // down and right
                if(k < row.size() - 3) {
                    numOccurences += isXmas({grid[i][k], grid[i + 1][k + 1], grid[i + 2][k + 2], grid[i + 3][k + 3]}) ? 1 : 0;
                }

                // down and left
                if (k >= 3) {
                    numOccurences += isXmas({grid[i][k], grid[i + 1][k - 1], grid[i + 2][k - 2], grid[i + 3][k - 3]}) ? 1 : 0;
                }
            }
        }
    }
    for(int i = 0; i < grid.size(); i++) {
        if(i == 0 || i == grid.size() - 1) continue;
        vector<char> row = grid[i];
        for(int k = 0; k < row.size(); k++) {
            char c = row[k];
            if(c != 'A') continue;
            if(k == 0 || k == row.size() - 1) continue;
            string left = "A"; left += grid[i - 1][k - 1]; left += grid[i + 1][k + 1];
            string right = "A"; right += grid[i - 1][k + 1]; right += grid[i + 1][k - 1];
            sort(left.begin(), left.end());
            sort(right.begin(), right.end());
            if(left == "AMS" && right == "AMS") {
                part2Occurences++;
            }
        }
    }

    cout << "Part 1 answer: " << numOccurences << '\n';
    cout << "Part 2 answer: " << part2Occurences << '\n';

}
