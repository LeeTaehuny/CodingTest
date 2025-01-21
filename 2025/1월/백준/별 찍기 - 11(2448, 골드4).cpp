// https://www.acmicpc.net/problem/2448 : 별 찍기 - 11, 2448 (c++) 

#include <iostream>


using namespace std;
char board[3075][6149];
int n;

void PrintStar(int size, int y, int x)
{
    if (size == 3)
    {
        //  *
        // * *
        //*****

        // y = 0, x = 2
        board[y][x] = '*';
        // y = 1, x = 1, 3
        board[y + 1][x - 1] = '*';
        board[y + 1][x + 1] = '*';
        // y = 2, x = 0 1 2 3 4
        for (int i = 0; i < 5; i++)
        {
            board[y + 2][x - 2 + i] = '*';
        }
        return;
    }

    PrintStar(size / 2, y, x);
    PrintStar(size / 2, y + size / 2, x - size / 2);
    PrintStar(size / 2, y + size / 2, x + size / 2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    PrintStar(n, 0, n - 1);

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n * 2 - 1; j++)
        {
            if (board[i][j] == '*')
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << '\n';
    }
}
