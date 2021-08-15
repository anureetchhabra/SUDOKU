
#include <bits/stdc++.h>
using namespace std;

#define UNASSIGNED 0



bool FindEmptyPlace(int answergrid[9][9], int &r, int &c)
{
    for (r = 0; r < 9; r++)
        for (c = 0; c < 9; c++)
            if (answergrid[r][c] == UNASSIGNED)
                return true;
    return false;
}

bool CheckRow(int answergrid[9][9], int r, int n)
{
    for (int c = 0; c < 9; c++)
        if (answergrid[r][c] == n)
            return true;
    return false;
}

bool CheckColumn(int answergrid[9][9], int c, int n)
{
    for (int r = 0; r < 9; r++)
        if (answergrid[r][c] == n)
            return true;
    return false;
}

bool CheckBox(int answergrid[9][9], int boxStartRow, int boxStartCol, int n)
{
    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++)
            if (answergrid[r + boxStartRow]
                          [c + boxStartCol] == n)
                return true;
    return false;
}

bool CheckSafe(int answergrid[9][9], int r, int c, int n)
{

    return !CheckRow(answergrid, r, n) && !CheckColumn(answergrid, c, n) && !CheckBox(answergrid, r - r % 3, c - c % 3, n) && answergrid[r][c] == UNASSIGNED;
}

bool SolveSudoku(int answergrid[9][9])
{
    int r, c;

    if (!FindEmptyPlace(answergrid, r, c))

        return true;

    for (int n = 1; n <= 9; n++)
    {

        if (CheckSafe(answergrid, r, c, n))
        {

            answergrid[r][c] = n;

            if (SolveSudoku(answergrid))
                return true;

            answergrid[r][c] = UNASSIGNED;
        }
    }

    // backtracking
    return false;
}

