#include <bits/stdc++.h>

using namespace std;

string s;
vector<char> opers;
vector<int> numbers;
int n;
int maxValue = -999999;

int operate(int num1, char op, int num2)
{
    if (op == '*')
    {
        return num1 * num2;
    }
    if (op == '-')
    {
        return num1 - num2;
    }
    if (op == '+')
    {
        return num1 + num2;
    }
}

void solve(int here, int num)
{
    if (here == numbers.size() - 1)
    {
        maxValue = max(maxValue, num);
        return;
    }

    solve(here + 1, operate(num, opers[here], numbers[here + 1]));
    if (here + 2 < numbers.size())
    {
        int tmp = operate(numbers[here + 1], opers[here + 1], numbers[here + 2]);
        solve(here + 2, operate(num, opers[here], tmp));
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '+' || s[i] == '*' || s[i] == '-')
        {
            opers.push_back(s[i]);
        }
        else
        {
            numbers.push_back(s[i] - '0');
        }
    }
    solve(0, numbers[0]);
    cout << maxValue << "\n";
    return 0;
}
