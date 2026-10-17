#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int V(int i, int a, int b, int c, int m, int v1, int v2, int& depth, int level)
{
    if (level > depth)
        depth = level;

    cout << "level = " << level << endl;

    if (i == 1)
        return v1;
    if (i == 2)
        return v2;

    int v_prev1 = V(i - 1, a, b, c, m, v1, v2, depth, level + 1);
    int v_prev2 = V(i - 2, a, b, c, m, v1, v2, depth, level + 1);

    return (a * v_prev1 + b * v_prev2 + c) % m;
}

int main()
{
    srand((unsigned)time(0));

    int a = 11;
    int b = 7;
    int c = 13;
    int m = 100;

    int v1 = rand() % m;
    int v2 = rand() % m;

    int n;
    cout << "n = "; cin >> n;

    cout << "\nGenerator parameters:" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << ", m = " << m << endl;
    cout << "V[1] = " << v1 << ", V[2] = " << v2 << endl << endl;

    cout << "Sequence generation:" << endl;
    cout << "---------------------------------" << endl;

    for (int i = 1; i <= n; i++)
    {
        int depth = 0;
        cout << "--- Calculating V[" << i << "] ---" << endl;

        int val = V(i, a, b, c, m, v1, v2, depth, 1);

        cout << "Value V[" << i << "] = " << val << endl;
        cout << "Recursion depth = " << depth << endl;
        cout << "---------------------------------" << endl;
    }

    return 0;
}