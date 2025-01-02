#include <bits/stdc++.h>

using namespace std;

int asw = -9999999;
int n;
string input;
vector<char> operators;
vector<int> numbers;

int calculate(int num1, char op, int num2)
{
    if (op == '+')
        return num1 + num2;
    if (op == '*')
        return num1 * num2;
    if (op == '-')
        return num1 - num2;
}

void solve(int here, int num)
{
    if (here == numbers.size() - 1)
    {
        asw = max(asw, num);
        return;
    }
    solve(here + 1, calculate(num, operators[here], numbers[here + 1]));
    if (here + 2 <= numbers.size() - 1)
    {
        int tmp = calculate(numbers[here + 1], operators[here + 1], numbers[here + 2]);
        solve(here + 2, calculate(num, operators[here], tmp));
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> input;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '+' || input[i] == '*' || input[i] == '-')
        {
            operators.push_back(input[i]);
        }
        else
        {
            numbers.push_back(input[i] - '0');
        }
    }
    solve(0, numbers[0]);
    cout << asw << "\n";

    return 0;
}
