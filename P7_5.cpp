#include <iostream> 
#include <iomanip> 
#include <string> 
using namespace std; 
ostream& currency(ostream& out) { 
    out << "Rs "; 
    return out; 
} 
int main() { 
    string names[] = {"Harshil", "Maxy", "Vansh", "Yash"}; 
    double marks[] = {77,90, 71, 80}; 
    double fees[] = {15000,12000,5000,9000}; 
    cout << left << setw(15) << "Name"  
         << right << setw(10) << "Marks"  
         << setw(15) << "Fees" << endl; 
    cout << setfill('-') << setw(40) << "-" << setfill(' ') << endl; 
    for (int i = 0; i < 4; ++i) { 
        cout << left << setw(15) << names[i] 
             << right << setw(10) << fixed << setprecision(2) << marks[i] 
             << setw(10) << currency << fixed << setprecision(2) << fees[i] << 
endl; 
    } 
    return 0; 
} 