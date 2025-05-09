#include <iostream> 
#include <vector> 
#include <set> 
using namespace std; 
 
int main() { 
    vector<int> numbers; 
    int n, value; 
 
    cout << "Enter the number of integers: "; 
    cin >> n; 
 
    cout << "Enter the integers: "; 
    for (int i = 0; i < n; ++i) { 
        cin >> value; 
        numbers.push_back(value); 
    } 
 
    set<int> uniqueNumbers(numbers.begin(), numbers.end()); 

 
    cout << "\nUnique Elements: "<<endl; 
    for (const auto& num : uniqueNumbers) { 
        cout << num << " "<<endl; 
    } 
    cout<< "24CE082 Jenil Patel"<<endl;
    return 0; 
} 