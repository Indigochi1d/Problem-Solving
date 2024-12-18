#include <bits/stdc++.h>

using namespace std;

int N;
char a[64][64];
string tmp_s;

void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp_s;
        for (int j = 0; j < N; j++)
        {
            a[i][j] = tmp_s[j];
        }
    }
}
string quad(int y, int x, int size)
{
    if (size == 1)
        return string(1, a[y][x]);

    string answer = "";
    char b = a[y][x];
    for (int i = y; i < y + size; i++)
    {
        for (int j = x; j < x + size; j++)
        {
            if (a[i][j] != b)
            {
                answer += "(";
                answer += quad(y, x, size / 2);
                answer += quad(y, x + size / 2, size / 2);
                answer += quad(y + size / 2, x, size / 2);
                answer += quad(y + size / 2, x + size / 2, size / 2);
                answer += ")";
                return answer;
            }
        }
    }
    return string(1, a[y][x]);
}

int main()
{
    input();
    // ---- ok-----
    string answer = quad(0, 0, N);

    cout << answer << "\n";

    return 0;
}
