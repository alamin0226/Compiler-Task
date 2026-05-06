#include <iostream>
using namespace std;

bool acceptedByRE(char str[]) {
    int i = 0;

    // accepts strings containing only 'a' and 'b'
    while (str[i] != '\0') {
        if (str[i] != 'a' && str[i] != 'b') {
            return false;
        }
        i++;
    }

    return true;
}

int main() {
    char str[100];

    cout << "Regular Expression: R = ab* + [a*(b+)* + ab]+\n\n";

    for (int i = 1; i <= 5; i++) {
        cout << "Enter string " << i << ": ";
        cin >> str;

        if (acceptedByRE(str)) {
            cout << "Result: Accepted\n";
        } else {
            cout << "Result: Rejected\n";
        }

        cout << endl;
    }

    return 0;
}
