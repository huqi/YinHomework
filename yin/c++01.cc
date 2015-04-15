#include <iostream>
using namespace std;

int main()
{
    string s("Good morning");
    string input;
    getline(cin, input);
    cout << input;

    if (input.compare(s) == 0)
        cout << "Hello" << endl;
    return 0;
}
