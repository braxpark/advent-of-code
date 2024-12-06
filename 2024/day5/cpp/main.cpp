#include <bits/stdc++.h>
using namespace std;

bool validUpdate(vector<int> update, unordered_map<int, vector<int>> deps) {
    unordered_set<int> contains;
    unordered_set<int> seen;
    for(auto u : update) contains.insert(u);
    for(auto num : update) {
        vector<int> dependsOn = deps[num];
        for(auto dep : dependsOn) {
            if(contains.count(dep) > 0 && seen.count(dep) == 0) {
                return false;
            }
        }
        seen.insert(num);
    }
    return true;
}

int getInvalidIndex(vector<int> update, unordered_map<int, vector<int>> deps) {
    unordered_set<int> contains;
    unordered_set<int> seen;
    for(auto u : update) contains.insert(u);
    int idx = 0;
    for(auto num : update) {
        vector<int> dependsOn = deps[num];
        for(auto dep : dependsOn) {
            if(contains.count(dep) > 0 && seen.count(dep) == 0) {
                return idx;
            }
        }
        seen.insert(num);
        idx++;
    }
    return -1;
}

vector<int> fixUpdateOrdering(vector<int> update, unordered_map<int, vector<int>> deps) {
    while(true) {
        int invalidIdx = getInvalidIndex(update, deps);
        if(invalidIdx == -1) break;
        int invalidNum = update[invalidIdx];
        update.erase(update.begin() + invalidIdx);
        update.push_back(invalidNum);
    }
    return update;
}

int main() {
    ifstream inTest("../test.txt");
    ifstream inInput("../input.txt");
    ifstream& data = inInput;
    string line;
    unordered_map<int, vector<int>> deps;
    int64_t part1Ans = 0, part2Ans;
    while(getline(data, line)) {
        if(line == "") break;
        stringstream ss(line);
        vector<int> nums;
        for(string num; getline(ss, num, '|');) {
            nums.push_back(stoi(num));
        }
        deps[nums[1]].push_back(nums[0]);
    }
    vector<vector<int>> updates;
    while(getline(data, line)) {
        stringstream ss(line);
        vector<int> update;
        for(string num; getline(ss, num, ',');) {
            update.push_back(stoi(num));
        }
        bool isValidUpdate = validUpdate(update, deps);
        if(isValidUpdate) {
            part1Ans += update[update.size() / 2];
        } else {
            vector<int> fixed = fixUpdateOrdering(update, deps);
            assert(fixed.size() > 0);
            part2Ans += fixed[fixed.size() / 2];
        }
    }
    cout << "Part1 Answer: " << part1Ans << '\n';
    cout << "Part2 Answer: " << part2Ans << '\n';
}
