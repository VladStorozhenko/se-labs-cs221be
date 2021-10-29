#include <iostream>

using namespace std;

int main()
{
    int n, i, j;
    cout << "Input n: ";
    cin >> n;
    double x, s, p;
    s = 0;
    cout << "Input x: ";
    cin >> x;
    if (x < 0)
    {
        if (n <= 1)
        {
            cout << "Wrong n";
        }
        else
        {
            for (i = 0; i <= n; i++)
            {
                p = 1.0;
                for (j = i; j <= n - 1; j++)
                {
                    p *= (double)i * i + j;
                }
                s += p;
            }
            cout << "Result: " << s;

        }
    }
    else
    {
        if (n <= 3)
        {
            cout << "Wrong n"; 
        }
        else
        {
            for (i = 1; i <= n - 2; i++)
            {
                s += i - x;
            }
            cout << "Result: " << s;
        }



    }

}
