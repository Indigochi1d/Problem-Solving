#include <bits/stdc++.h>

using namespace std;

// n은 스크린의 개수, m은 바구니의 크기
int n, m;
int apples;
int fall[20];
int leftBasketLoc = 1, rightBasketLoc;
void input()
{
    cin >> n >> m;
    cin >> apples;
    for (int i = 0; i < apples; i++)
    {
        cin >> fall[i];
    }
    rightBasketLoc = m;
}

int solve()
{
    int moved = 0;
    for (int i = 0; i < apples; i++)
    {
        if (fall[i] < leftBasketLoc || fall[i] > rightBasketLoc)
        {
            if (fall[i] < leftBasketLoc)
            {
                while (fall[i] != leftBasketLoc)
                {
                    moved++;
                    leftBasketLoc--;
                    rightBasketLoc--;
                    if (leftBasketLoc < 1)
                    {
                        leftBasketLoc = 1;
                        rightBasketLoc = m;
                    }
                }
            }
            else if (fall[i] > rightBasketLoc)
            {
                while (fall[i] != rightBasketLoc)
                {
                    moved++;
                    leftBasketLoc++;
                    rightBasketLoc++;
                    if (rightBasketLoc > n)
                    {
                        rightBasketLoc = n;
                        leftBasketLoc = n - m + 1;
                    }
                }
            }
        }
    }
    return moved;
}

int main()
{
    input();
    cout << solve() << "\n";
    return 0;
}
