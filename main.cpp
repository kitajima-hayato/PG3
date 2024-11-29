#include <fstream>
#include <vector>
#include <cstring>
#include <iostream>
#include <string> 
#include <algorithm>
#include <sstream>
using namespace std;

int main() {
    vector<string> numbers;
    ifstream file("File/PG3_2024_03_02.txt");

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string item;
            while (getline(ss, item, ',')) {
                numbers.push_back(item);
            }
        }
        file.close();
    }
    else {
        cout << "Unable to open file" << endl;
        return 1;
    }

    // 文字列を昇順に並び替え
    sort(numbers.begin(), numbers.end());

    // 並び替えた内容をコンソールに出力
    for (const auto& number : numbers) {
        cout << number << endl;
    }

    return 0;
}



