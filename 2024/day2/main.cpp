#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<int> reportLevels) {
    int increasing = reportLevels[1] > reportLevels[0];
    bool safeLevel = true;
    for(int i = 1; i < reportLevels.size(); i++) {
        int diff = abs(reportLevels[i] - reportLevels[i - 1]);
        if(diff < 1 or diff > 3) {
            safeLevel = false; break;
        }
        if((increasing and (reportLevels[i] < reportLevels[i - 1])) or (not increasing and (reportLevels[i] > reportLevels[i - 1]))) {
            safeLevel = false; break;
        }
    }
    return safeLevel;
}

bool isSafeWithOneRemoval(vector<int> report, int index) {
    report.erase(report.begin() + index);
    return isSafe(report);
}

int main() {
    ifstream inTest("test.txt");
    ifstream inInput("input.txt");
    ifstream& data = inInput;
    string report;
    int safeLevels = 0;
    int partTwoSafeLevels = 0;
    while(getline(data, report)) {
        stringstream ss(report);
        string level;

        vector<int> reportLevels;
        while(getline(ss, level, ' ')) {
            reportLevels.push_back(stoi(level));
        }
        // part 1
        if(isSafe(reportLevels)) {
            safeLevels++;
        } else {
            for(int i = 0; i < reportLevels.size(); i++) {
                if(isSafeWithOneRemoval(reportLevels, i)) {
                    partTwoSafeLevels++;
                    break;
                }
            }
        }
    }
    cout << "Part 1: " << safeLevels << '\n';
    cout << "Part 2: " << safeLevels + partTwoSafeLevels << '\n';
}
