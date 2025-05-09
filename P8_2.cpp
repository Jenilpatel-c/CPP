#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <iterator>

using namespace std;

void count_word_frequency(const string& input) {
    map<string, int> word_count;
    string word;
    stringstream ss(input);

    while (ss >> word) {
        for (char& c : word) {
            c = tolower(c);
        }
        word_count[word]++;
    }

    cout << "\nword frequency distribution:\n";
    for (const auto& pair : word_count) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

int main() {
    string input;

    cout << "enter a sentence: ";
    getline(cin, input);

    count_word_frequency(input);

    cout << "24CE082 Jenil Patel";
    return 0;
}