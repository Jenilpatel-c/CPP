#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

class directory_manager {
private:
    map<string, vector<string>> directory;

public:
    void add_folder(const string& folder_name) {
        if (directory.find(folder_name) == directory.end()) {
            directory[folder_name] = vector<string>();
            cout << "folder '" << folder_name << "' created.\n";
        } else {
            cout << "folder '" << folder_name << "' already exists.\n";
        }
    }

    void add_file_to_folder(const string& folder_name, const string& file_name) {
        if (directory.find(folder_name) != directory.end()) {
            directory[folder_name].push_back(file_name);
            cout << "file '" << file_name << "' added to folder '" << folder_name << "'.\n";
        } else {
            cout << "folder '" << folder_name << "' does not exist. please create it first.\n";
        }
    }

    void display_directory() {
        cout << "\n--- directory structure ---\n";
        for (map<string, vector<string>>::iterator it = directory.begin(); it != directory.end(); ++it) {
            cout << "folder: " << it->first << "\n";
            vector<string>& files = it->second;
            if (files.empty()) {
                cout << "  (empty)\n";
            } else {
                for (vector<string>::iterator fit = files.begin(); fit != files.end(); ++fit) {
                    cout << "  - " << *fit << "\n";
                }
            }
        }
    }
};

int main() {
    directory_manager dm;
    int choice;
    string folder, file;

    do {
        cout << "\n1. add folder\n2. add file to folder\n3. display directory\n0. exit\nchoose: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "enter folder name: ";
                getline(cin, folder);
                dm.add_folder(folder);
                break;
            case 2:
                cout << "enter folder name: ";
                getline(cin, folder);
                cout << "enter file name: ";
                getline(cin, file);
                dm.add_file_to_folder(folder, file);
                break;
            case 3:
                dm.display_directory();
                break;
            case 0:
                cout << "exiting...\n";
                break;
            default:
                cout << "invalid choice.\n";
        }

    } while (choice != 0);

    cout << "24CE082 Jenil Patel";
    return 0;
}