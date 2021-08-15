#include <iostream>
#include <iomanip>
#include <time.h>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <vector>
#include "solver.h"

using namespace std;
#define UNASSIGNED 0

int points[2][81];
int count = 0;

void text_colour(int colour_num)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, colour_num);
}

int welcome()
{
    int difficulty;
    cout << "Choose Difficulty:" << endl;
    text_colour(1);
    cout << "1.Easy\n";
    text_colour(14);
    cout << "2.Medium\n";
    text_colour(4);
    cout << "3.Hard\n";
    text_colour(15);
    cin >> difficulty;
    getch();
    if (difficulty > 3)
    {
        system("cls");
        cout << "Enter a valid choice\n";
        welcome();
    }

    system("cls");

    return difficulty;
}
int *MakePuzzle(int displaygrid[9][9], int difficulty)
{
    int n = 0;
    switch (difficulty)
    {

    case 1:
        srand(time(0));
        while (n < 35)
        {

            int delrow = ((rand() % 10) + 0);
            int delcol = ((rand() % 10) + 0);
            //cout<<delcol<<" "<<delrow<<endl;
            displaygrid[delrow][delcol] = 0;

            n++;
        }
        break;
    case 2:
        srand(time(0));

        while (n < 43)
        {

            int delrow = ((rand() % 10) + 0);
            int delcol = ((rand() % 10) + 0);
            displaygrid[delrow][delcol] = 0;
            n++;
        }
        break;
    case 3:

        while (n < 50)
        {

            int delrow = ((rand() % 10) + 0);
            int delcol = ((rand() % 10) + 0);
            displaygrid[delrow][delcol] = 0;
            n++;
        }
        break;

    default:
        break;
    }

    return reinterpret_cast<int *>(displaygrid);
}

bool pointInpoints(int i, int j)
{
    for (int k = 0; k < ::count; k++)
    {
        if (points[0][k] == i && points[1][k] == j)
            return true;
    }
    return false;
}

void printgrid(int diplaygrid[9][9])
{

    for (int k = 0; k < 37; k++)
    {
        //SetConsoleTextAttribute(h, 8);
        text_colour(8);
        cout << "-";
    }
    cout << endl;

    for (int i = 0; i < 9; i++)
    {
        int n = 0;

        for (int j = 0; j < 9; j++)
        {
            if (j == 3 || j == 6)
            {
                // SetConsoleTextAttribute(h, 14);
                text_colour(14);
                cout << "|";
            }
            else
            {
                //SetConsoleTextAttribute(h, 8);
                text_colour(8);
                cout << "|";
            }
            //SetConsoleTextAttribute(h, 15);
            text_colour(15);
            if (diplaygrid[i][j] == 0)
                cout << "   ";
            else
            {
                if (!pointInpoints(i, j))
                    cout << " " << diplaygrid[i][j] << " ";
                else
                {
                    text_colour(9);
                    cout << " " << diplaygrid[i][j] << " ";
                    text_colour(15);
                }
            }
        }
        //SetConsoleTextAttribute(h, 8);
        text_colour(8);
        cout << "|" << endl;
        while (n < 37)
        {
            if (n == 12 || n == 24)
            {
                cout << "+";
                //SetConsoleTextAttribute(h, 14);
                text_colour(14);
            }
            // else if (n == 4 || n == 8 || n == 16 || n == 20 || n == 28)
            // {
            //     cout << "+";
            //     SetConsoleTextAttribute(h, 8);
            // }
            else
            {
                if (i == 2 || i == 5)
                {
                    //SetConsoleTextAttribute(h, 14);
                    text_colour(14);
                    cout << "-";
                }
                else
                {
                    //SetConsoleTextAttribute(h, 8);
                    text_colour(8);
                    cout << "-";
                }
            }
            n++;
        }
        cout << endl;
    }
    //return reinterpret_cast<int *>(printgrid);
}

bool input(int answergrid[9][9], int displaygrid[9][9])
{
    int filled = 0, row, column, num, wrong_answer = 0, correct_answer = 0;

    do
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (displaygrid[i][j] != 0)
                    filled++;
            }
        }
        if (filled == 62)
        {
            text_colour(5);
            cout << "*********  Halfway There!  *********" << endl;
            text_colour(15);
        }
        if (filled == 75)

        {
            text_colour(5);
            cout << "*********  Almost There!  ********" << endl;
            text_colour(15);
        }
        if (filled == 81)

        {
            text_colour(5);
            cout << "*********  CONGRATULATIONS! *********" << endl;
            text_colour(15);
            cout << "Correct Responses: " << correct_answer << endl;
            cout << "Incorrect Responses: " << wrong_answer << endl;
        }

        cout << "Enter the row\n";
        cin >> row;
        if (row == 0)
        {

            system("cls");
            cout << "Correct Responses: " << correct_answer << endl;
            cout << "Incorrect Responses: " << wrong_answer << endl;
            cout << "Correct Solution is:\n";
            return false;
        }

        cout << "Enter the column\n";
        cin >> column;
        if (column == 0)
        {

            system("cls");

            cout << "Correct Responses: " << correct_answer << endl;
            cout << "Incorrect Responses: " << wrong_answer << endl;
            cout << "Correct Solution is:\n";

            return false;
        }

        cout << "Enter the number to be entered\n";
        cin >> num;
        if (num == 0)
        {

            system("cls");

            cout << "Correct Responses: " << correct_answer << endl;
            cout << "Incorrect Responses: " << wrong_answer << endl;
            cout << "Correct Solution is:\n";

            break;
        }

        if (answergrid[row - 1][column - 1] == num)
        {
            displaygrid[row - 1][column - 1] = num;
            correct_answer++;
            points[0][::count] = row - 1;
            points[1][::count] = column - 1;
            ::count++;
            printgrid(displaygrid);
        }
        else
        {
            text_colour(15);
            cout << "***************Wrong Answer***************" << endl;
            wrong_answer++;
            printgrid(displaygrid);
        }

    } while (filled != 82);
}

bool check(vector<int> ar, int element)
{
    for (int i = 0; i < ar.size(); i++)
    {
        if (ar[i] == element)
            return false;
    }
    return true;
}

void rules()
{
    text_colour(14);
    cout << "**************RULES**************" << endl;
    text_colour(9);
    cout << "1.Only use the numbers 1 to 9" << endl;
    cout << "2.Avoid trying to guess the solution to the puzzle" << endl;
    cout << "3.Only use each number once in each row, column, & grid" << endl;
    cout << "To Quit while playing press 0" << endl;
    text_colour(15);
}

int main()
{
    int answergrid[9][9], displaygrid[9][9];

    int choice, difficulty;
    while (true)
    {
        getch();
        system("cls");
    play:
        text_colour(14);
        cout << "***************SUDOKU***************" << endl;
        text_colour(9);
        cout << setw(10) << "1.PLAY\n2.RULES\n3.EXIT\n";
        text_colour(15);
        cin >> choice;
        getch();
        system("cls");
        if (choice == 1)
        {

            difficulty = welcome();

            srand(time(0));
            int i = 0, j = 0;
            //initialize a grid
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    answergrid[i][j] = 0;
                    displaygrid[i][j] = 0;
                }
            }

            // generate random number at the diagonal
            for (int k = 0; k <= 2; k++)
            {
                vector<int> ar;
                for (int j = 0; j <= 2; j++)
                {
                    int index = (k * 3) + j;
                    int unique = (rand() % 9) + 1;
                    while (!check(ar, unique))
                        unique = (rand() % 9) + 1;
                    ar.push_back(unique);
                    answergrid[index][index] = unique;
                }
                //answergrid[k][k] = ((rand() % 9) + 1);
            }
            SolveSudoku(answergrid);

            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    displaygrid[i][j] = answergrid[i][j];
                }
            }
            // printgrid(answergrid);
            MakePuzzle(displaygrid, difficulty);
            SolveSudoku(answergrid);

            printgrid(displaygrid);

           if (!input(answergrid, displaygrid)){
                printgrid(answergrid);
           }
        }
        else if (choice == 2)
        {
            rules();
            getch();
            system("cls");
            goto play;
        }
        else
        {
            cout << "Thank you for playing" << endl;
            break;
        }
    }
    return 0;
}
