#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string file_name;
    cout << "enter the file name: ";
    cin >> file_name;

    ifstream file(file_name);

    if (!file.is_open()) {
        cout << "please enter the valid output '" << file_name << "'" << endl;
        return 1;
    }

    int line_count = 0;
    int word_count = 0;
    int char_count = 0;
    string line;

    while (getline(file, line)) {
        line_count++;
        char_count += line.length() + 1;

        bool in_word = false;
        for (char ch : line) {
            if (ch == ' ' || ch == '\t') {
                in_word = false;
            } else {
                if (!in_word) {
                    word_count++;
                    in_word = true;
                }
            }
        }
    }

    cout << "lines: " << line_count << endl;
    cout << "words: " << word_count << endl;
    cout << "characters: " << char_count << endl;
    cout << "24CE082 Jenil Patel";
    return 0;
}