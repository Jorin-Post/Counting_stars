#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<int> vx = {6, 10, 10, 20, 10, 10, 10, 20, 30, 30, 42, 43, 43}; // 5 stars
vector<int> vy = {6, 9,  10, 10, 11, 12, 13, 17, 23, 24, 30, 30, 31};

int main()
{
    int count = 0, stars = 0, i = 0;
    while (vx.size() > 0)
    {
        int x = vx[i], x1 = vx[i + 1], y = vy[i], y1 = vy[i + 1];

        if (x == x1 - 1 && y == y1)
        {
            vx.erase(vx.begin() + i);
            vy.erase(vy.begin() + i);
            cout << "Erase!: " << x << " - " << y << endl;
        }
        else
        {
            vx.erase(vx.begin() + i);
            vy.erase(vy.begin() + i);
            count++;
            cout << count << '\t' << x << " - " << y << endl;
        }
    }

    for (int i = 0; i < vx.size(); i++)
    {
        cout << vx[i] << '\t' << ends;
    }
    cout << endl;
    for (int i = 0; i < vy.size(); i++)
    {
        cout << vy[i] << '\t' << ends;
    }
    cout << endl;
    cout << count << endl;
}