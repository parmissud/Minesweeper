#include <iostream>
#include <time.h>
#include "clui.h"
#include <string>
#include <conio.h>
#include <windows.h>
using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // baraye daryafte va erae etelaat az console
COORD CursorPosition;                             // taeine mokhtasate safhe baraye jabejaii ba kilid ha
struct user
{
    int num;
    string name;
    int score;
};
void minesNumber(int, int, user[]);
void makeBoard(int, int);
void game(int, int, user[]);
void loadgame1(int, int, user[]);
void loadgame2(int, int, user[]);
void loadgame3(int, int, user[]);
void loadgame4(int, int, user[]);
int win(int);
void sideMines(int, int, int, int, user);
void menu(user[]);
void gotoXY();
void grade(user[]);
char board[20][20][5], mines[20][20][5], board1[20][20][5], mines1[20][20][5], board2[20][20][5], mines2[20][20][5], board3[20][20][5], mines3[20][20][5], board4[20][20][5], mines4[20][20][5];
bool load1 = true, load2 = true, load3 = true, load4 = true;
int num = 0, m1 = 0, n1 = 0, m2, n2, m3, n3, m4, n4, M2, N2,numberofusers=1;
bool endgame = true, flag = true;
void bubbleSort(user users[])
{
    int i, j;
    bool flag;
    for (i = 0; i < 4; i++)
    {
        flag = false;
        for (j = 0; j < 4 - i - 1; j++)
        {

            if (users[j].score >= users[j + 1].score)
            {
                swap(users[j], users[j + 1]);
                flag = true;
            }
        }
        if (!flag)
        {
            break;
        }
    }
}
void gotoXY(int x, int y) // baraye kar ba key ha va goftn inke curser koja bere
{
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}
void menu(user users[]) // sakhte menu
{
    clear_screen();

    user us5;
    us5 = users[4];
    int menu_item = 0, run, x = 7;
    gotoXY(18, 5);
    cout << us5.name << endl;
    gotoXY(18, 6);
    cout << "Main Menu";
    gotoXY(18, 7);
    cout << "->";

    bool running = true;
    while (running)
    {
        gotoXY(20, 7);
        cout << "New Game";
        gotoXY(20, 8);
        cout << "Load Game";
        gotoXY(20, 9);
        cout << "Change Name";
        gotoXY(20, 10);
        cout << "Leaderboard";
        gotoXY(20, 11);
        cout << "Quit";

        system("pause>nul"); // the >nul bit causes it the print no message

        if (GetAsyncKeyState(VK_DOWN) && x != 11) // down button pressed
        {
            gotoXY(18, x);
            cout << "  ";
            x++;
            gotoXY(18, x);
            cout << "->";
            menu_item++;
            continue;
        }

        if (GetAsyncKeyState(VK_UP) && x != 7) // up button pressed
        {
            gotoXY(18, x);
            cout << "  ";
            x--;
            gotoXY(18, x);
            cout << "->";
            menu_item--;
            continue;
        }
        if (GetAsyncKeyState(VK_RETURN))
        { // Enter key pressed
            switch (menu_item)
            {
            case 0:
            {
                clear_screen();
                grade(users);
                break;
            }
            case 1:
            {
                clear_screen();
                cout << "1.loadgame 1" << endl;
                cout << "2.loadgame 2" << endl;
                cout << "3.loadgame 3" << endl;
                cout << "4.loadgame 4" << endl;
                int number;
                cin >> number;

                if (number == 1)
                {
                    if (board1[0][0][us5.num] == '0' || board1[0][0][us5.num] == '1' || board1[0][0][us5.num] == '2' || board1[0][0][us5.num] == '3' || board1[0][0][us5.num] == '*' || board1[0][0][us5.num] == '#')

                    {
                        loadgame1(m1, n1, users);
                    }
                    else
                    {
                        clear_screen();
                        cout << "no load game" << endl;
                        delay(2000);
                        menu(users);
                    }
                }
                if (number == 2)
                {
                    if (board2[0][0][us5.num] == '0' || board2[0][0][us5.num] == '1' || board2[0][0][us5.num] == '2' || board2[0][0][us5.num] == '3' || board2[0][0][us5.num] == '*' || board2[0][0][us5.num] == '#')

                    {
                        loadgame2(M2, N2, users);
                    }
                    else
                    {
                        clear_screen();
                        cout << "no load game" << endl;
                        delay(2000);
                        menu(users);
                    }
                }
                if (number == 3)
                {
                    if (board3[0][0][us5.num] == '0' || board3[0][0][us5.num] == '1' || board3[0][0][us5.num] == '2' || board3[0][0][us5.num] == '3' || board3[0][0][us5.num] == '*' || board3[0][0][us5.num] == '#')

                    {
                        loadgame3(m3, n3, users);
                    }
                    else
                    {
                        clear_screen();
                        cout << "no load game" << endl;
                        delay(2000);
                        menu(users);
                    }
                }
                if (number == 4)
                {
                    if (board4[0][0][us5.num] == '0' || board4[0][0][us5.num] == '1' || board4[0][0][us5.num] == '2' || board4[0][0][us5.num] == '3' || board4[0][0][us5.num] == '*' || board4[0][0][us5.num] == '#')

                    {
                        loadgame4(m4, n4, users);
                    }
                    else
                    {
                        clear_screen();
                        cout << "no load game" << endl;
                        delay(2000);
                        menu(users);
                    }
                }
            }
            case 2:
            {
                clear_screen();
                string name;
                cout << "name?";
                cin >> name;
                bubbleSort(users);

                if (users[3].score < users[4].score)
                {
                    users[3] = users[4];
                }

                bubbleSort(users);
                bool is = true;
                for (int i = 0; i < 4; i++)
                {
                    if (users[i].name == name)
                    {
                        users[4] = users[i];
                        is = false;
                    }
                }
                if(is)
                {
                    users[4].name = name;
                    users[4].score = 0;
                    numberofusers++;
                }

                menu(users);

                break;
            }
            case 3:
            {
                

                
                clear_screen();
                
                cout << users[4].name <<users[4].score<< endl;
                
                break;
            }
            case 4:
            {
                gotoXY(20, 16);
                running = false;
                quit();
            }
            }
        }
    }
    gotoXY(20, 21);
}
void makeBoard(int m, int n, user users[])
{
    user us5 = users[4];
    // ekhtesase alamat ha dar board
    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < m; col++)
        {
            board[row][col][us5.num] = '*';
            mines[row][col][us5.num] = '0';
        }
    }
    // daryafte random e mahale bomb ha
    srand((unsigned int)time(0));
    for (int i = 0; i < n; i++)
    {
        int row = (rand() % (m - 1));
        int col = (rand() % (m - 1));
        while (mines[row][col][us5.num] == '@')
        {
            row = (rand() % (m - 1));
            col = (rand() % (m - 1));
        }
        mines[row][col][us5.num] = '@';
    }
    minesNumber(m, n, users);
}
void minesNumber(int m, int n, user users[])
{
    user us5 = users[4];
    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (mines[row][col][us5.num] == '@')
            {
                for (int x = row - 1; x <= row + 1; x++)
                {
                    for (int y = col - 1; y <= col + 1; y++)
                    {
                        if (x >= 0 && x <= m - 1)
                        {
                            if (y >= 0 && y <= m - 1)
                            {
                                if (mines[x][y][us5.num] != '@')
                                {
                                    mines[x][y][us5.num] += 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
void grade(user users[])
{
    int menu_item = 0, run, x = 7;
    gotoXY(18, 5);
    cout << "Grades";
    gotoXY(18, 7);
    cout << "->";

    bool running = true;
    while (running)
    {
        gotoXY(20, 7);
        cout << "Begginer";
        gotoXY(20, 8);
        cout << "Intermediate";
        gotoXY(20, 9);
        cout << "Hard";
        gotoXY(20, 10);
        cout << "other";

        system("pause>nul"); // the >nul bit causes it the print no message

        if (GetAsyncKeyState(VK_DOWN) && x != 10) // down button pressed
        {
            gotoXY(18, x);
            cout << "  ";
            x++;
            gotoXY(18, x);
            cout << "->";
            menu_item++;
            continue;
        }

        if (GetAsyncKeyState(VK_UP) && x != 7) // up button pressed
        {
            gotoXY(18, x);
            cout << "  ";
            x--;
            gotoXY(18, x);
            cout << "->";
            menu_item--;
            continue;
        }

        if (GetAsyncKeyState(VK_RETURN))
        { // Enter key pressed
            switch (menu_item)
            {
            case 0:
            {
                makeBoard(5, 4, users);
                game(5, 4, users);
                break;
            }
            case 1:
            {
                makeBoard(12, 28, users);
                game(12, 28, users);
                break;
            }
            case 2:
            {
                makeBoard(20, 96, users);
                game(20, 96, users);
                break;
            }
            case 3:
            {
                cout << "tedade satr o soton:";
                cin >> m2;
                while (m2 < 5 || m2 > 20)
                {
                    cout << "not accepted enter new one";
                    cin >> m2;
                }

                cout << "tedade bomb";
                cin >> n2;
                while (n2 > m2 * m2)
                {
                    cout << "not accepted enter new one";
                    cin >> n2;
                }

                makeBoard(m2, n2, users);
                game(m2, n2, users);
                break;
            }
            }
        }
    }
    gotoXY(20, 21);
}
void game(int m, int n, user users[])
{
    user us5 = users[4];
    int firstmove = 0;
    int x = 1, y = 1;
    bool running = true;
    clear_screen();
    gotoXY(0, 0);
    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < m; col++)
        {
            cout << board[row][col][us5.num] << " ";
        }
        cout << endl;
    }

    // daryafte vorodi row va col az user
    for (int i = 0; endgame; i++)
    {
        while (running)
        {
            char chr = getch();
            if ((chr == 'a' || chr == 'A') && y > 1)
            {
                y--;
                cout << y << x << endl;
            }
            if ((chr == 'd' || chr == 'D') && y < m)
            {
                y++;
                cout << y << x << endl;
            }
            if ((chr == 'W' || chr == 'w') && x > 1)
            {
                x--;
                cout << y << x << endl;
            }
            if ((chr == 's' || chr == 'S') && x < m)
            {
                x++;
                cout << y << x << endl;
            }
            if (chr == ' ')
            {
                firstmove = 0;
                break;
            }
            if (chr == 'f' || chr == 'F')
            {
                firstmove = 1;
                break;
            }
            if (chr == 'q' || chr == 'Q')
            {

                for (int row = 0; row < m; row++)
                {
                    for (int col = 0; col < m; col++)
                    {
                        board[row][col][us5.num] = '*';
                        mines[row][col][us5.num] = '0';
                    }
                }

                menu(users);
            }
            if (chr == 'o' || chr == 'O')
            {
                if (load1)
                {
                    for (int row = 0; row < m; row++)
                    {
                        for (int col = 0; col < m; col++)
                        {
                            board1[row][col][us5.num] = board[row][col][us5.num];
                            mines1[row][col][us5.num] = mines[row][col][us5.num];
                        }
                    }

                    m1 = m;
                    n1 = n;
                    load1 = false;
                }
                else if (load2)
                {
                    for (int row = 0; row < m; row++)
                    {
                        for (int col = 0; col < m; col++)
                        {
                            board2[row][col][us5.num] = board[row][col][us5.num];
                            mines2[row][col][us5.num] = mines[row][col][us5.num];
                        }
                    }

                    M2 = m;
                    N2 = n;
                    load2 = false;
                }
                else if (load3)
                {
                    for (int row = 0; row < m; row++)
                    {
                        for (int col = 0; col < m; col++)
                        {
                            board3[row][col][us5.num] = board[row][col][us5.num];
                            mines3[row][col][us5.num] = mines[row][col][us5.num];
                        }
                    }

                    m3 = m;
                    n3 = n;
                    load3 = false;
                }
                if (load4)
                {
                    for (int row = 0; row < m; row++)
                    {
                        for (int col = 0; col < m; col++)
                        {
                            board4[row][col][us5.num] = board[row][col][us5.num];
                            mines4[row][col][us5.num] = mines[row][col][us5.num];
                        }
                    }

                    m4 = m;
                    n4 = n;
                    load4 = false;
                    load1 = true;
                }

                menu(users);
            }
        }

        // check kardn in k khane entekhabi tekrari nabashe
        while (board[x - 1][y - 1] == mines[x - 1][y - 1])
        {
            cout << "That position has already been revealed." << endl
                 << endl;
            game(m, n, users);
        }

        // parcham gozari va bardashtn
        if (firstmove == 1)
        {
            if (board[x - 1][y - 1][us5.num] == '#')
                board[x - 1][y - 1][us5.num] = '*';
            else
                board[x - 1][y - 1][us5.num] = '#';
            clear_screen();

            for (int row = 0; row < m; row++)
            {
                for (int col = 0; col < m; col++)
                {

                    cout << board[row][col][us5.num] << " ";
                }
                cout << endl;
            }
        }

        // check kardne inke khone entekhabi bomb dashte ya n

        if (firstmove == 0)
        {
            if (board[x - 1][y - 1][us5.num] == '#')
            {
                play_beep();
                cout << "you can't reveal that position, it has a flag.first remove the flag and retry" << endl;
                delay(2000);
                game(m, n, users);
            }

            if (mines[x - 1][y - 1][us5.num] == '@')
            {

                change_color_rgb(255, 0, 0);
                play_beep();
                cout << "\nOpps! You stepped on a mine!" << endl;
                cout << "Game Over!" << endl
                     << endl;
                delay(2000);

                reset_color();
                clear_screen();

                for (int row = 0; row < m; row++)
                {
                    for (int col = 0; col < m; col++)
                    {
                        cout << mines[row][col][us5.num] << " ";
                    }
                    cout << endl;
                }
                delay(5000);

                clear_screen();
                menu(users);
            }
            else
            {
                board[x - 1][y - 1][us5.num] = mines[x - 1][y - 1][us5.num];
                sideMines(m, n, x, y, us5);
                clear_screen();

                for (int row = 0; row < m; row++)
                {
                    for (int col = 0; col < m; col++)
                    {
                        cout << board[row][col][us5.num] << " ";
                    }
                    cout << endl;
                }
                num = win(m);

                if (num == m * m - n)
                {

                    change_color_rgb(0, 255, 0);
                    cout << "\nCongrats! You've cleared all the mines!" << endl;
                    us5.score+=m;
                    reset_color();
                    delay(2000);

                    clear_screen();
                    menu(users);
                }
            }
        }
    }
    
}
void loadgame1(int m, int n, user users[])
{
    user us5 = users[4];
    int firstmove = 0;
    int x = 1, y = 1;
    bool running = true;
    clear_screen();
    gotoXY(0, 0);

    {
        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < m; col++)
            {
                cout << board1[row][col][us5.num] << " ";
            }
            cout << endl;
        }

        // daryafte vorodi row va col az user
        for (int i = 0; endgame; i++)
        {
            while (running)
            {
                char chr = getch();
                if ((chr == 'a' || chr == 'A') && y > 1)
                {
                    y--;
                    cout << y << x << endl;
                }
                if ((chr == 'd' || chr == 'D') && y < m)
                {
                    y++;
                    cout << y << x << endl;
                }
                if ((chr == 'W' || chr == 'w') && x > 1)
                {
                    x--;
                    cout << y << x << endl;
                }
                if ((chr == 's' || chr == 'S') && x < m)
                {
                    x++;
                    cout << y << x << endl;
                }
                if (chr == ' ')
                {
                    firstmove = 0;
                    break;
                }
                if (chr == 'f' || chr == 'F')
                {
                    firstmove = 1;
                    break;
                }
                if (chr == 'q' || chr == 'Q')
                {

                    menu(users);
                }
                if (chr == 'o' || chr == 'O')
                {

                    menu(users);
                }
            }

            // check kardn in k khane entekhabi tekrari nabashe
            while (board1[x - 1][y - 1] == mines1[x - 1][y - 1])
            {
                cout << "That position has already been revealed." << endl
                     << endl;
                loadgame1(m, n, users);
            }

            // parcham gozari va bardashtn
            if (firstmove == 1)
            {
                if (board1[x - 1][y - 1][us5.num] == '#')
                    board1[x - 1][y - 1][us5.num] = '*';
                else
                    board1[x - 1][y - 1][us5.num] = '#';
                clear_screen();

                for (int row = 0; row < m; row++)
                {
                    for (int col = 0; col < m; col++)
                    {

                        cout << board1[row][col][us5.num] << " ";
                    }
                    cout << endl;
                }
            }

            // check kardne inke khone entekhabi bomb dashte ya n

            if (firstmove == 0)
            {
                if (board1[x - 1][y - 1][us5.num] == '#')
                {
                    play_beep();
                    cout << "you can't reveal that position, it has a flag.first remove the flag and retry" << endl;
                    loadgame1(m, n, users);
                }

                if (mines1[x - 1][y - 1][us5.num] == '@')
                {

                    change_color_rgb(255, 0, 0);
                    play_beep();
                    cout << "\nOpps! You stepped on a mine!" << endl;
                    cout << "Game Over!" << endl
                         << endl;
                    reset_color();
                    clear_screen();

                    for (int row = 0; row < m; row++)
                    {
                        for (int col = 0; col < m; col++)
                        {
                            cout << mines1[row][col][us5.num] << " ";
                        }
                        cout << endl;
                    }
                    clear_screen();
                    menu(users);
                }
                else
                {
                    board1[x - 1][y - 1][us5.num] = mines1[x - 1][y - 1][us5.num];
                    sideMines(m, n, x, y, us5);
                    clear_screen();

                    for (int row = 0; row < m; row++)
                    {
                        for (int col = 0; col < m; col++)
                        {
                            cout << board1[row][col][us5.num] << " ";
                        }
                        cout << endl;
                    }
                    num = win(m);

                    if (num == m * m - n)
                    {

                        change_color_rgb(0, 255, 0);
                        cout << "\nCongrats! You've cleared all the mines!" << endl;
                        us5.score++;
                        reset_color();
                        clear_screen();
                        menu(users);
                    }
                }
            }
        }
    }
    if (us5.score == 0)
    {
        user us4 = users[3];
        us4 = us5;
    }
    else
        bubbleSort(users);
}
void loadgame2(int m, int n, user users[])
{
    user us5 = users[4];
    int firstmove = 0;
    int x = 1, y = 1;
    bool running = true;
    clear_screen();
    gotoXY(0, 0);

    {
        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < m; col++)
            {
                cout << board2[row][col][us5.num] << " ";
            }
            cout << endl;
        }

        // daryafte vorodi row va col az user
        for (int i = 0; endgame; i++)
        {
            while (running)
            {
                char chr = getch();
                if ((chr == 'a' || chr == 'A') && y > 1)
                {
                    y--;
                    cout << y << x << endl;
                }
                if ((chr == 'd' || chr == 'D') && y < m)
                {
                    y++;
                    cout << y << x << endl;
                }
                if ((chr == 'W' || chr == 'w') && x > 1)
                {
                    x--;
                    cout << y << x << endl;
                }
                if ((chr == 's' || chr == 'S') && x < m)
                {
                    x++;
                    cout << y << x << endl;
                }
                if (chr == ' ')
                {
                    firstmove = 0;
                    break;
                }
                if (chr == 'f' || chr == 'F')
                {
                    firstmove = 1;
                    break;
                }
                if (chr == 'q' || chr == 'Q')
                {

                    menu(users);
                }
                if (chr == 'o' || chr == 'O')
                {

                    menu(users);
                }
            }

            // check kardn in k khane entekhabi tekrari nabashe
            while (board2[x - 1][y - 1] == mines2[x - 1][y - 1])
            {
                cout << "That position has already been revealed." << endl
                     << endl;
                loadgame2(m, n, users);
            }

            // parcham gozari va bardashtn
            if (firstmove == 1)
            {
                if (board2[x - 1][y - 1][us5.num] == '#')
                    board2[x - 1][y - 1][us5.num] = '*';
                else
                    board2[x - 1][y - 1][us5.num] = '#';
                clear_screen();

                for (int row = 0; row < m; row++)
                {
                    for (int col = 0; col < m; col++)
                    {

                        cout << board2[row][col][us5.num] << " ";
                    }
                    cout << endl;
                }
            }

            // check kardne inke khone entekhabi bomb dashte ya n

            if (firstmove == 0)
            {
                if (board2[x - 1][y - 1][us5.num] == '#')
                {
                    play_beep();
                    cout << "you can't reveal that position, it has a flag.first remove the flag and retry" << endl;
                    loadgame2(m, n, users);
                }

                if (mines2[x - 1][y - 1][us5.num] == '@')
                {

                    change_color_rgb(255, 0, 0);
                    play_beep();
                    cout << "\nOpps! You stepped on a mine!" << endl;
                    cout << "Game Over!" << endl
                         << endl;
                    reset_color();
                    clear_screen();

                    for (int row = 0; row < m; row++)
                    {
                        for (int col = 0; col < m; col++)
                        {
                            cout << mines2[row][col][us5.num] << " ";
                        }
                        cout << endl;
                    }
                    clear_screen();
                    menu(users);
                }
                else
                {
                    board2[x - 1][y - 1][us5.num] = mines2[x - 1][y - 1][us5.num];
                    sideMines(m, n, x, y, us5);
                    clear_screen();

                    for (int row = 0; row < m; row++)
                    {
                        for (int col = 0; col < m; col++)
                        {
                            cout << board2[row][col][us5.num] << " ";
                        }
                        cout << endl;
                    }
                    num = win(m);

                    if (num == m * m - n)
                    {

                        change_color_rgb(0, 255, 0);
                        cout << "\nCongrats! You've cleared all the mines!" << endl;
                        us5.score++;
                        reset_color();
                        clear_screen();
                        menu(users);
                    }
                }
            }
        }
    }
    if (us5.score == 0)
    {
        user us4 = users[3];
        us4 = us5;
    }
    else
        bubbleSort(users);
}
void loadgame3(int m, int n, user users[])
{
    user us5 = users[4];
    int firstmove = 0;
    int x = 1, y = 1;
    bool running = true;
    clear_screen();
    gotoXY(0, 0);

    {
        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < m; col++)
            {
                cout << board3[row][col][us5.num] << " ";
            }
            cout << endl;
        }

        // daryafte vorodi row va col az user
        for (int i = 0; endgame; i++)
        {
            while (running)
            {
                char chr = getch();
                if ((chr == 'a' || chr == 'A') && y > 1)
                {
                    y--;
                    cout << y << x << endl;
                }
                if ((chr == 'd' || chr == 'D') && y < m)
                {
                    y++;
                    cout << y << x << endl;
                }
                if ((chr == 'W' || chr == 'w') && x > 1)
                {
                    x--;
                    cout << y << x << endl;
                }
                if ((chr == 's' || chr == 'S') && x < m)
                {
                    x++;
                    cout << y << x << endl;
                }
                if (chr == ' ')
                {
                    firstmove = 0;
                    break;
                }
                if (chr == 'f' || chr == 'F')
                {
                    firstmove = 1;
                    break;
                }
                if (chr == 'q' || chr == 'Q')
                {

                    menu(users);
                }
                if (chr == 'o' || chr == 'O')
                {

                    menu(users);
                }
            }

            // check kardn in k khane entekhabi tekrari nabashe
            while (board3[x - 1][y - 1] == mines3[x - 1][y - 1])
            {
                cout << "That position has already been revealed." << endl
                     << endl;
                loadgame3(m, n, users);
            }

            // parcham gozari va bardashtn
            if (firstmove == 1)
            {
                if (board3[x - 1][y - 1][us5.num] == '#')
                    board3[x - 1][y - 1][us5.num] = '*';
                else
                    board3[x - 1][y - 1][us5.num] = '#';
                clear_screen();

                for (int row = 0; row < m; row++)
                {
                    for (int col = 0; col < m; col++)
                    {

                        cout << board3[row][col][us5.num] << " ";
                    }
                    cout << endl;
                }
            }

            // check kardne inke khone entekhabi bomb dashte ya n

            if (firstmove == 0)
            {
                if (board3[x - 1][y - 1][us5.num] == '#')
                {
                    play_beep();
                    cout << "you can't reveal that position, it has a flag.first remove the flag and retry" << endl;
                    loadgame3(m, n, users);
                }

                if (mines3[x - 1][y - 1][us5.num] == '@')
                {

                    change_color_rgb(255, 0, 0);
                    play_beep();
                    cout << "\nOpps! You stepped on a mine!" << endl;
                    cout << "Game Over!" << endl
                         << endl;
                    reset_color();
                    clear_screen();

                    for (int row = 0; row < m; row++)
                    {
                        for (int col = 0; col < m; col++)
                        {
                            cout << mines3[row][col][us5.num] << " ";
                        }
                        cout << endl;
                    }
                    clear_screen();
                    menu(users);
                }
                else
                {
                    board3[x - 1][y - 1][us5.num] = mines3[x - 1][y - 1][us5.num];
                    sideMines(m, n, x, y, us5);
                    clear_screen();

                    for (int row = 0; row < m; row++)
                    {
                        for (int col = 0; col < m; col++)
                        {
                            cout << board3[row][col][us5.num] << " ";
                        }
                        cout << endl;
                    }
                    num = win(m);

                    if (num == m * m - n)
                    {

                        change_color_rgb(0, 255, 0);
                        cout << "\nCongrats! You've cleared all the mines!" << endl;
                        us5.score++;
                        reset_color();
                        clear_screen();
                        menu(users);
                    }
                }
            }
        }
    }

    if (us5.score == 0)
    {
        user us4 = users[3];
        us4 = us5;
    }
    else
        bubbleSort(users);
}
void loadgame4(int m, int n, user users[])
{
    user us5 = users[4];
    int firstmove = 0;
    int x = 1, y = 1;
    bool running = true;
    clear_screen();
    gotoXY(0, 0);

    {
        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < m; col++)
            {
                cout << board4[row][col][us5.num] << " ";
            }
            cout << endl;
        }

        // daryafte vorodi row va col az user
        for (int i = 0; endgame; i++)
        {
            while (running)
            {
                char chr = getch();
                if ((chr == 'a' || chr == 'A') && y > 1)
                {
                    y--;
                    cout << y << x << endl;
                }
                if ((chr == 'd' || chr == 'D') && y < m)
                {
                    y++;
                    cout << y << x << endl;
                }
                if ((chr == 'W' || chr == 'w') && x > 1)
                {
                    x--;
                    cout << y << x << endl;
                }
                if ((chr == 's' || chr == 'S') && x < m)
                {
                    x++;
                    cout << y << x << endl;
                }
                if (chr == ' ')
                {
                    firstmove = 0;
                    break;
                }
                if (chr == 'f' || chr == 'F')
                {
                    firstmove = 1;
                    break;
                }
                if (chr == 'q' || chr == 'Q')
                {

                    menu(users);
                }
                if (chr == 'o' || chr == 'O')
                {

                    menu(users);
                }
            }

            // check kardn in k khane entekhabi tekrari nabashe
            while (board4[x - 1][y - 1] == mines4[x - 1][y - 1])
            {
                cout << "That position has already been revealed." << endl
                     << endl;
                loadgame4(m, n, users);
            }

            // parcham gozari va bardashtn
            if (firstmove == 1)
            {
                if (board4[x - 1][y - 1][us5.num] == '#')
                    board4[x - 1][y - 1][us5.num] = '*';
                else
                    board4[x - 1][y - 1][us5.num] = '#';
                clear_screen();

                for (int row = 0; row < m; row++)
                {
                    for (int col = 0; col < m; col++)
                    {

                        cout << board4[row][col][us5.num] << " ";
                    }
                    cout << endl;
                }
            }

            // check kardne inke khone entekhabi bomb dashte ya n

            if (firstmove == 0)
            {
                if (board4[x - 1][y - 1][us5.num] == '#')
                {
                    play_beep();
                    cout << "you can't reveal that position, it has a flag.first remove the flag and retry" << endl;
                    loadgame4(m, n, users);
                }

                if (mines4[x - 1][y - 1][us5.num] == '@')
                {

                    change_color_rgb(255, 0, 0);
                    play_beep();
                    cout << "\nOpps! You stepped on a mine!" << endl;
                    cout << "Game Over!" << endl
                         << endl;
                    reset_color();
                    clear_screen();

                    for (int row = 0; row < m; row++)
                    {
                        for (int col = 0; col < m; col++)
                        {
                            cout << mines4[row][col][us5.num] << " ";
                        }
                        cout << endl;
                    }
                    clear_screen();
                    menu(users);
                }
                else
                {
                    board4[x - 1][y - 1][us5.num] = mines4[x - 1][y - 1][us5.num];
                    sideMines(m, n, x, y, us5);
                    clear_screen();

                    for (int row = 0; row < m; row++)
                    {
                        for (int col = 0; col < m; col++)
                        {
                            cout << board4[row][col][us5.num] << " ";
                        }
                        cout << endl;
                    }
                    num = win(m);

                    if (num == m * m - n)
                    {

                        change_color_rgb(0, 255, 0);
                        cout << "\nCongrats! You've cleared all the mines!" << endl;
                        us5.score++;
                        reset_color();
                        clear_screen();
                        menu(users);
                    }
                }
            }
        }
    }
    if (us5.score == 0)
    {
        user us4 = users[3];
        us4 = us5;
    }
    else
        bubbleSort(users);
}
void sideMines(int m, int n, int x, int y, user us5)
{
    if (mines[x - 1][y - 1][us5.num] == '0')
    {
        for (int x1 = x - 2; x1 != x + 1; x1++)
        {
            for (int y1 = y - 2; y1 != y + 1; y1++)
            {
                if (x1 >= 0 && x1 <= m - 1)
                {
                    if (y1 >= 0 && y1 <= m - 1)
                    {
                        board[x1][y1][us5.num] = mines[x1][y1][us5.num];
                        if (mines[x1][y1][us5.num] == '0')
                        {
                            for (int x2 = x - 3; x2 != x + 3; x2++)
                            {
                                for (int y2 = y - 3; y2 != y + 3; y2++)
                                {
                                    if (x2 >= 0 && x2 <= m - 1)
                                    {
                                        if (y2 >= 0 && y2 <= m - 1)
                                        {
                                            if (mines[x2][y2][us5.num] != '@')
                                            {
                                                board[x2][y2][us5.num] = mines[x2][y2][us5.num];
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
int win(int m)
{
    int num = 0;
    for (int x = 0; x < m; x++)
    {
        for (int y = 0; y < m; y++)
        {
            if (board[x][y] == mines[x][y])
            {
                num += 1;
            }
        }
    }
    return num;
}
int main()
{
    user us1, us2, us3, us4, us5;
    user users[5] = {us1, us2, us3, us4, us5};
    us1.num = 1;
    us2.num = 2;
    us3.num = 3;
    us4.num = 4;
    us5.num = 5;
    us1.score = 0;
    us2.score = 0;
    us3.score = 0;
    us4.score = 0;
    us5.score = 0;

    clear_screen();
    cout << "name?";
    string name1;
    cin >> name1;
    users[4].name=name1;
    menu(users);
    return 0;
}