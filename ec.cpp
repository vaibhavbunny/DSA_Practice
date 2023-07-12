#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    int maxLength = 0;
    int currentLength = 1;

    for (int i = 1; i < str.length(); i++) {
        if (str[i] == str[i - 1]) {
            currentLength++;
        } else {
            maxLength = max(maxLength, currentLength);
            currentLength = 1;
        }
    }

    maxLength = max(maxLength, currentLength);

    cout << "Maximum consecutive occurrences of the same character: " << maxLength << endl;

    return 0;
}
