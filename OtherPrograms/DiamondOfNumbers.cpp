#include <iostream>
using namespace std;


void RowNumbers(int n, int max) {
    if (n < max) {
        cout << n << ' ';
        RowNumbers(n + 1, max);
    }
    cout << n << ' ';
}

void PrintRhombus(int n, int space = 0)
{
    if (n > 1)
    {
        PrintRhombus(n - 1, space + 2);
    }
    cout << string(space, ' ');
    RowNumbers(1, n);
    cout << "\n";
}

void PrintRhombusBottom(int n, int space)
{
    if (n >= 1)
    {
        cout << string(space, ' ');
        RowNumbers(1, n);
        cout << "\n";
        PrintRhombusBottom(n - 1, space + 2);
    }
}




int main() {
    int a;
    cout << "Enter a number [1-9]: ";
    cin >> a;
if (a > 0 && a < 10)
{
    PrintRhombus(a, 0);
    PrintRhombusBottom(a - 1, 2);
}
    else
        cout << "Wrong input." << endl;
}
