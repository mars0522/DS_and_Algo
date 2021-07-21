#include <iostream>
using namespace std;

void printMazePaths(int sr, int sc, int dr, int dc, string op) {
    // write your code here
    if (sr == dr and sc == dc)
        cout << op << endl;
    else if (sr > dr or sc > dc)
        return ;
    else
    {
        printMazePaths(sr, sc + 1, dr, dc, op + "h");
        printMazePaths(sr + 1, sc, dr, dc, op + "v");

    }

}

int main() {
    int n;
    int m;
    cin >> n >> m;
    printMazePaths(0, 0, n - 1, m - 1, "");
}