#include <iostream>
using namespace std;

void printStairPaths(int n, string op) {
    // write your code here

    if (n == 0)
        cout << op << endl;
    else if (n < 0)
        return;
    else
    {
        printStairPaths(n - 1, op + "1");
        printStairPaths(n - 2, op + "2");
        printStairPaths(n - 3, op + "3");
    }

}

int main() {

    int n;
    cin >> n;
    printStairPaths(n, "");
}