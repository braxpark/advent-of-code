#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream inTest("../test.txt");
    ifstream inInput("../input.txt");
    ifstream& data = inInput;
    string line;
    int64_t total = 0;
    int64_t part2Total = 0;
    while(getline(data, line)) {
        std::regex pattern(R"(mul\((\d{1,3}),(\d{1,3})\))");

        auto begin = std::sregex_iterator(line.begin(), line.end(), pattern);
        auto end = std::sregex_iterator();

        for (auto it = begin; it != end; ++it) {
            total += (stoi((*it)[1]) * stoi((*it)[2]));
        }
    }
    ifstream inTest2("../test_part_2.txt");
    ifstream inInput2("../input.txt");
    ifstream& part2Data = inInput2;
    int64_t diff = 0;
    bool enabled = true;
    while(getline(part2Data, line)) {
        std::regex pattern(R"((?:mul\((\d{1,3}),(\d{1,3})\)|do\(\)|don't\(\)))");
        auto begin = std::sregex_iterator(line.begin(), line.end(), pattern);
        auto end = std::sregex_iterator();
        for(auto it = begin; it != end; ++it) {
            if(it->str() == "don't()")  {
                enabled = false;
                continue;
            } else if(it->str() == "do()")  {
                enabled = true;
                continue;
            }
            if(enabled) {
                part2Total += (stoi((*it)[1]) * stoi((*it)[2]));
            } else {
                diff += (stoi((*it)[1]) * stoi((*it)[2]));
            }
        }
    }
    cout << "Part 1 answer: " << total << '\n';
    cout << "Part 2 answer: " << part2Total << '\n';
    cout << "They add up to: " << part2Total << " + " << diff << " = " << part2Total + diff << '\n';
}
