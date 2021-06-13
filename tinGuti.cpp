#include <iostream>
#include <iomanip>
#include <algorithm>
#include <limits>

class Game
{
    enum class Player
    {
        none = '-',
        human = 'X',
        computer = 'O'
    };

    struct Move
    {
        unsigned int x = -1;
        unsigned int y = -1;
        unsigned int p = -1;
        unsigned int q = -1;
    };

    Player board[3][3];
    int moveCount=0;

public:

    Game()
    {
        for (unsigned int j = 0; j < 3; j++)
        {
            board[0][j] = Player::computer;
            board[1][j] = Player::none;
            board[2][j] = Player::human;
        }
    }

    void printBoard()
    {
        std::cout << "+-----------------+";
        for (unsigned int i = 0; i < 3; i++)
        {
            std::cout << "\n|";
            for (unsigned int j = 0; j < 3; j++)
            {
                std::cout << std::setw(3) << static_cast<char>(board[i][j]) << std::setw(3) << " |";
            }
        }
        std::cout << "\n+-----------------+\n";
    }

    bool isTie()
    {
        if(moveCount<20)
            return false;
        else
            return true;
    }

    bool checkWin(Player player)
    {
            // Check horizontals
            if (board[1][0] == player && board[1][1] == player && board[1][2] == player)
                return true;

            // Check verticals
            if (board[0][1] == player && board[1][1] == player && board[2][1] == player)
                return true;

        // Check diagonals
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
            return true;

        if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
            return true;

        return false;
    }
    //ai move condition
    Move aiMoveCondition(int a, int b)
    {
        int score = std::numeric_limits<int>::max();
        Move move1;
        Move move;
        move1.x=a;move1.y=b;
        if(a==0 && b==0)
        {
            if(board[0][1] == Player::none)
            {
                    move1.p=0;move1.q=1;
                    board[a][b]=Player::none;
                    board[move1.p][move1.q]=Player::computer;
                    int temp = maxSearch();

                    if (temp < score)
                    {
                        score = temp;
                        move.x = move1.x;
                        move.y = move1.y;

                        move.p=move1.p;
                        move.q=move1.q;
                    }
                    board[a][b] = Player::computer;
                    board[move1.p][move1.q] = Player::none;
            }


            if(board[1][0] == Player::none)
                {
                    move1.p=1;move1.q=0;
                    board[a][b]=Player::none;
                    board[move1.p][move1.q]=Player::computer;
                    int temp = maxSearch();

                    if (temp < score)
                    {
                        score = temp;
                        move.x = move1.x;
                        move.y = move1.y;

                        move.p=move1.p;
                        move.q=move1.q;
                    }
                    board[a][b] = Player::computer;
                    board[move1.p][move1.q] = Player::none;
                }
            if(board[1][1] == Player::none)
                {
                    move1.p=1;move1.q=1;
                    board[a][b]=Player::none;
                    board[move1.p][move1.q]=Player::computer;
                    int temp = maxSearch();

                    if (temp < score)
                    {
                        score = temp;
                        move.x = move1.x;
                        move.y = move1.y;

                        move.p=move1.p;
                        move.q=move1.q;
                    }
                    board[a][b] = Player::computer;
                    board[move1.p][move1.q] = Player::none;
                }
        }
        if(a==0 && b==1)
        {
            if(board[0][0] == Player::none)
                {
                    move1.p=0;move1.q=0;
                    board[a][b]=Player::none;
                    board[move1.p][move1.q]=Player::computer;
                    int temp = maxSearch();

                    if (temp < score)
                    {
                        score = temp;
                        move.x = move1.x;
                        move.y = move1.y;

                        move.p=move1.p;
                        move.q=move1.q;
                    }
                    board[a][b] = Player::computer;
                    board[move1.p][move1.q] = Player::none;
                }
            if(board[1][1] == Player::none)
                {
                    move1.p=1;move1.q=1;
                    board[a][b]=Player::none;
                    board[move1.p][move1.q]=Player::computer;
                    int temp = maxSearch();

                    if (temp < score)
                    {
                        score = temp;
                        move.x = move1.x;
                        move.y = move1.y;

                        move.p=move1.p;
                        move.q=move1.q;
                    }
                    board[a][b] = Player::computer;
                    board[move1.p][move1.q] = Player::none;
                }
            if(board[0][2] == Player::none)
                {
                    move1.p=0;move1.q=2;
                    board[a][b]=Player::none;
                    board[move1.p][move1.q]=Player::computer;
                    int temp = maxSearch();

                    if (temp < score)
                    {
                        score = temp;
                        move.x = move1.x;
                        move.y = move1.y;

                        move.p=move1.p;
                        move.q=move1.q;
                    }
                    board[a][b] = Player::computer;
                    board[move1.p][move1.q] = Player::none;
                }
        }
        if(a==0 && b==2)
        {
            if(board[0][1] == Player::none)
                {
                    move1.p=0;move1.q=1;
                    board[a][b]=Player::none;
                    board[move1.p][move1.q]=Player::computer;
                    int temp = maxSearch();

                    if (temp < score)
                    {
                        score = temp;
                        move.x = move1.x;
                        move.y = move1.y;

                        move.p=move1.p;
                        move.q=move1.q;
                    }
                    board[a][b] = Player::computer;
                    board[move1.p][move1.q] = Player::none;
                }
            if(board[1][1] == Player::none)
                {
                    move1.p=1;move1.q=1;
                    board[a][b]=Player::none;
                    board[move1.p][move1.q]=Player::computer;
                    int temp = maxSearch();

                    if (temp < score)
                    {
                        score = temp;
                        move.x = move1.x;
                        move.y = move1.y;

                        move.p=move1.p;
                        move.q=move1.q;
                    }
                    board[a][b] = Player::computer;
                    board[move1.p][move1.q] = Player::none;
                }
            if(board[1][2] == Player::none)
                {
                    move1.p=1;move1.q=2;
                    board[a][b]=Player::none;
                    board[move1.p][move1.q]=Player::computer;
                    int temp = maxSearch();

                    if (temp < score)
                    {
                        score = temp;
                        move.x = move1.x;
                        move.y = move1.y;

                        move.p=move1.p;
                        move.q=move1.q;
                    }
                    board[a][b] = Player::computer;
                    board[move1.p][move1.q] = Player::none;
                }
        }
        if(a==1 && b==0)
        {
            if(board[0][0] == Player::none)
                {
                    move1.p=0;move1.q=0;
                    board[a][b]=Player::none;
                    board[move1.p][move1.q]=Player::computer;
                    int temp = maxSearch();

                    if (temp < score)
                    {
                        score = temp;
                        move.x = move1.x;
                        move.y = move1.y;

                        move.p=move1.p;
                        move.q=move1.q;
                    }
                    board[a][b] = Player::computer;
                    board[move1.p][move1.q] = Player::none;
                }
            if(board[1][1] == Player::none)
                {
                    move1.p=1;move1.q=1;
                    board[a][b]=Player::none;
                    board[move1.p][move1.q]=Player::computer;
                    int temp = maxSearch();

                    if (temp < score)
                    {
                        score = temp;
                        move.x = move1.x;
                        move.y = move1.y;

                        move.p=move1.p;
                        move.q=move1.q;
                    }
                    board[a][b] = Player::computer;
                    board[move1.p][move1.q] = Player::none;
                }
            if(board[2][0] == Player::none)
                {
                    move1.p=2;move1.q=0;
                    board[a][b]=Player::none;
                    board[move1.p][move1.q]=Player::computer;
                    int temp = maxSearch();

                    if (temp < score)
                    {
                        score = temp;
                        move.x = move1.x;
                        move.y = move1.y;

                        move.p=move1.p;
                        move.q=move1.q;
                    }
                    board[a][b] = Player::computer;
                    board[move1.p][move1.q] = Player::none;

                }
        }
        if(a==1 && b==2)
        {
            if(board[0][2] == Player::none)
                {
                    move1.p=0;move1.q=2;
                    board[a][b]=Player::none;
                    board[move1.p][move1.q]=Player::computer;
                    int temp = maxSearch();

                    if (temp < score)
                    {
                        score = temp;
                        move.x = move1.x;
                        move.y = move1.y;

                        move.p=move1.p;
                        move.q=move1.q;
                    }
                    board[a][b] = Player::computer;
                    board[move1.p][move1.q] = Player::none;
                }
            if(board[1][1] == Player::none)
                {
                    move1.p=1;move1.q=1;
                    board[a][b]=Player::none;
                    board[move1.p][move1.q]=Player::computer;
                    int temp = maxSearch();

                    if (temp < score)
                    {
                        score = temp;
                        move.x = move1.x;
                        move.y = move1.y;

                        move.p=move1.p;
                        move.q=move1.q;
                    }
                    board[a][b] = Player::computer;
                    board[move1.p][move1.q] = Player::none;
                }
            if(board[2][2] == Player::none)
                {
                    move1.p=2;move1.q=2;
                    board[a][b]=Player::none;
                    board[move1.p][move1.q]=Player::computer;
                    int temp = maxSearch();

                    if (temp < score)
                    {
                        score = temp;
                        move.x = move1.x;
                        move.y = move1.y;

                        move.p=move1.p;
                        move.q=move1.q;
                    }
                    board[a][b] = Player::computer;
                    board[move1.p][move1.q] = Player::none;
                }
        }
        if(a==2 && b==0)
        {
            if(board[1][0] == Player::none)
                {
                    move1.p=1;move1.q=0;board[a][b]=Player::none;
                    board[move1.p][move1.q]=Player::computer;
                    int temp = maxSearch();

                    if (temp < score)
                    {
                        score = temp;
                        move.x = move1.x;
                        move.y = move1.y;

                        move.p=move1.p;
                        move.q=move1.q;
                    }
                    board[a][b] = Player::computer;
                    board[move1.p][move1.q] = Player::none;
                }
            if(board[1][1] == Player::none)
                {
                    move1.p=1;move1.q=1;board[a][b]=Player::none;
                    board[move1.p][move1.q]=Player::computer;
                    int temp = maxSearch();

                    if (temp < score)
                    {
                        score = temp;
                        move.x = move1.x;
                        move.y = move1.y;

                        move.p=move1.p;
                        move.q=move1.q;
                    }
                    board[a][b] = Player::computer;
                    board[move1.p][move1.q] = Player::none;
                }
            if(board[2][1] == Player::none)
                {
                    move1.p=2;move1.q=1;
                    board[a][b]=Player::none;
                    board[move1.p][move1.q]=Player::computer;
                    int temp = maxSearch();

                    if (temp < score)
                    {
                        score = temp;
                        move.x = move1.x;
                        move.y = move1.y;

                        move.p=move1.p;
                        move.q=move1.q;
                    }
                    board[a][b] = Player::computer;
                    board[move1.p][move1.q] = Player::none;
                }
        }
        if(a==2 && b==1)
        {
            if(board[2][0] == Player::none)
                {
                    move1.p=2;move1.q=0;
                    board[a][b]=Player::none;
                    board[move1.p][move1.q]=Player::computer;
                    int temp = maxSearch();

                    if (temp < score)
                    {
                        score = temp;
                        move.x = move1.x;
                        move.y = move1.y;

                        move.p=move1.p;
                        move.q=move1.q;
                    }
                    board[a][b] = Player::computer;
                    board[move1.p][move1.q] = Player::none;
                }
            if(board[1][1] == Player::none)
                {
                    move1.p=1;move1.q=1;
                    board[a][b]=Player::none;
                    board[move1.p][move1.q]=Player::computer;
                    int temp = maxSearch();

                    if (temp < score)
                    {
                        score = temp;
                        move.x = move1.x;
                        move.y = move1.y;

                        move.p=move1.p;
                        move.q=move1.q;
                    }
                    board[a][b] = Player::computer;
                    board[move1.p][move1.q] = Player::none;
                }
            if(board[2][2] == Player::none)
                {
                    move1.p=2;move1.q=2;
                    board[a][b]=Player::none;
                    board[move1.p][move1.q]=Player::computer;
                    int temp = maxSearch();

                    if (temp < score)
                    {
                        score = temp;
                        move.x = move1.x;
                        move.y = move1.y;

                        move.p=move1.p;
                        move.q=move1.q;
                    }
                    board[a][b] = Player::computer;
                    board[move1.p][move1.q] = Player::none;
                }
        }
        if(a==2 && b==2)
        {
            if(board[1][2] == Player::none)
                {
                    move1.p=1;move1.q=2;
                    board[a][b]=Player::none;
                    board[move1.p][move1.q]=Player::computer;
                    int temp = maxSearch();

                    if (temp < score)
                    {
                        score = temp;
                        move.x = move1.x;
                        move.y = move1.y;

                        move.p=move1.p;
                        move.q=move1.q;
                    }
                    board[a][b] = Player::computer;
                    board[move1.p][move1.q] = Player::none;
                }
            if(board[1][1] == Player::none)
                {
                    move1.p=1;move1.q=1;
                    board[a][b]=Player::none;
                    board[move1.p][move1.q]=Player::computer;
                    int temp = maxSearch();

                    if (temp < score)
                    {
                        score = temp;
                        move.x = move1.x;
                        move.y = move1.y;

                        move.p=move1.p;
                        move.q=move1.q;
                    }
                    board[a][b] = Player::computer;
                    board[move1.p][move1.q] = Player::none;
                }
            if(board[2][1] == Player::none)
                {
                    move1.p=2;move1.q=1;
                    board[a][b]=Player::none;
                    board[move1.p][move1.q]=Player::computer;
                    int temp = maxSearch();

                    if (temp < score)
                    {
                        score = temp;
                        move.x = move1.x;
                        move.y = move1.y;

                        move.p=move1.p;
                        move.q=move1.q;
                    }
                    board[a][b] = Player::computer;
                    board[move1.p][move1.q] = Player::none;
                }
        }
        if(a==1 && b==1)
        {
            if(board[0][0] == Player::none)
                {
                    move1.p=0;move1.q=0;
                    board[a][b]=Player::none;
                    board[move1.p][move1.q]=Player::computer;
                    int temp = maxSearch();

                    if (temp < score)
                    {
                        score = temp;
                        move.x = move1.x;
                        move.y = move1.y;

                        move.p=move1.p;
                        move.q=move1.q;
                    }
                    board[a][b] = Player::computer;
                    board[move1.p][move1.q] = Player::none;
                }
            if(board[0][1] == Player::none)
                {
                    move1.p=0;move1.q=1;
                    board[a][b]=Player::none;
                    board[move1.p][move1.q]=Player::computer;
                    int temp = maxSearch();

                    if (temp < score)
                    {
                        score = temp;
                        move.x = move1.x;
                        move.y = move1.y;

                        move.p=move1.p;
                        move.q=move1.q;
                    }
                    board[a][b] = Player::computer;
                    board[move1.p][move1.q] = Player::none;
                }
            if(board[0][2] == Player::none)
                {
                    move1.p=0;move1.q=2;
                    board[a][b]=Player::none;
                    board[move1.p][move1.q]=Player::computer;
                    int temp = maxSearch();

                    if (temp < score)
                    {
                        score = temp;
                        move.x = move1.x;
                        move.y = move1.y;

                        move.p=move1.p;
                        move.q=move1.q;
                    }
                    board[a][b] = Player::computer;
                    board[move1.p][move1.q] = Player::none;
                }
            if(board[1][0] == Player::none)
                {
                    move1.p=1;move1.q=0;
                    board[a][b]=Player::none;
                    board[move1.p][move1.q]=Player::computer;
                    int temp = maxSearch();

                    if (temp < score)
                    {
                        score = temp;
                        move.x = move1.x;
                        move.y = move1.y;

                        move.p=move1.p;
                        move.q=move1.q;
                    }
                    board[a][b] = Player::computer;
                    board[move1.p][move1.q] = Player::none;
                }
            if(board[1][2] == Player::none)
                {
                    move1.p=1;move1.q=2;
                    board[a][b]=Player::none;
                    board[move1.p][move1.q]=Player::computer;
                    int temp = maxSearch();

                    if (temp < score)
                    {
                        score = temp;
                        move.x = move1.x;
                        move.y = move1.y;

                        move.p=move1.p;
                        move.q=move1.q;
                    }
                    board[a][b] = Player::computer;
                    board[move1.p][move1.q] = Player::none;
                }
            if(board[2][0] == Player::none)
                {
                    move1.p=2;move1.q=0;
                    board[a][b]=Player::none;
                    board[move1.p][move1.q]=Player::computer;
                    int temp = maxSearch();

                    if (temp < score)
                    {
                        score = temp;
                        move.x = move1.x;
                        move.y = move1.y;

                        move.p=move1.p;
                        move.q=move1.q;
                    }
                    board[a][b] = Player::computer;
                    board[move1.p][move1.q] = Player::none;

                }
            if(board[2][1] == Player::none)
                {
                    move1.p=2;move1.q=1;
                    board[a][b]=Player::none;
                    board[move1.p][move1.q]=Player::computer;
                    int temp = maxSearch();

                    if (temp < score)
                    {
                        score = temp;
                        move.x = move1.x;
                        move.y = move1.y;

                        move.p=move1.p;
                        move.q=move1.q;
                    }
                    board[a][b] = Player::computer;
                    board[move1.p][move1.q] = Player::none;
                }
            if(board[2][2] == Player::none)
                {
                    move1.p=2;move1.q=2;
                    board[a][b]=Player::none;
                    board[move1.p][move1.q]=Player::computer;
                    int temp = maxSearch();

                    if (temp < score)
                    {
                        score = temp;
                        move.x = move1.x;
                        move.y = move1.y;

                        move.p=move1.p;
                        move.q=move1.q;
                    }
                    board[a][b] = Player::computer;
                    board[move1.p][move1.q] = Player::none;
                }

        }
        return move;
    }
    ///////////////////////////////////////////////////////////////////

    Move minimax()
    {
        int score = std::numeric_limits<int>::max();
        Move move;
        Move test;
        int p,q;

        for ( int i = 0; i < 3; i++)
        {
            for ( int j = 0; j < 3; j++)
            {
                if (board[i][j] == Player::computer)
                {
                    test=aiMoveCondition(i,j);
                    board[i][j]=Player::none;
                    board[test.p][test.q]=Player::computer;

                    int temp = maxSearch();

                    if (temp < score)
                    {
                        score = temp;
                        move.x = i;
                        move.y = j;

                        move.p=test.p;
                        move.q=test.q;
                    }
                    board[i][j] = Player::computer;
                    board[test.p][test.q] = Player::none;
                }
            }
        }

        return move;
    }
    int maxCount=0;
    int maxSearch()
    {

        maxCount++;
        if (checkWin(Player::human)) { return 10; }
        else if (checkWin(Player::computer)) { return -10; }
        else if (isTie()) { return 0; }
        int score = std::numeric_limits<int>::min();
        Move test;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == Player::human)
                {

                    test=aiMoveCondition(i,j);
                    board[test.p][test.q] = Player::human;
                    board[i][j] = Player::none;

                    if(maxCount<10)
                    {
                        score = std::max(score, minSearch());
                    }

                    board[i][j] = Player::human;
                    board[test.p][test.q] = Player::none;
                }
            }
        }

        return score;

    }

    int minSearch()
    {
        Move test;
        int p,q;
        if (checkWin(Player::human)) { return 10; }
        else if (checkWin(Player::computer)) { return -10; }
        else if (isTie()) { return 0; }

        int score = std::numeric_limits<int>::max();

        for (unsigned int i = 0; i < 3; i++)
        {
            for (unsigned int j = 0; j < 3; j++)
            {
                if (board[i][j] == Player::computer)
                {
                    test=aiMoveCondition(i,j);

                    board[test.p][test.q] = Player::computer;
                    board[i][j] = Player::none;
                    score = std::min(score, maxSearch());
                    board[i][j] = Player::computer;
                    board[test.p][test.q] = Player::none;
                }
            }
        }

        return score;
    }

    void getHumanMove()
    {
        int fail = 1;
        unsigned int x = -1, y = -1;//destination
        unsigned int a = -1, b = -1;//source

        do
        {
            std::cout << "Your Move from: ";

            char c;
            std::cin >> c;
            a = c - '0';
            std::cin >> c;
            b = c - '0';
            if(board[a][b]==Player::human)
                {
                    MoveCondition(a,b);

                    std::cout<<"\n";
                    std::cin.clear();

                    std::cout << "Your Move to: ";
                    char ch;
                    std::cin >> ch;
                    x = ch - '0';
                    std::cin >> ch;
                    y = ch - '0';
                    if(board[x][y]== Player::none)
                    {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        board[x][y] = Player::human;
                        board[a][b] = Player::none;
                        fail=0;
                    }
                    else
                    {
                        std::cout<<x<<y<<" is not free. \n";
                    }
                }
            else
                std::cout<<"wrong input... !! try again. \n ";



        } while (fail!=0);


    }
    void MoveCondition(int a,int b)
    {
        if(a==0 && b==0)
        {
            if(board[0][1] == Player::none)
                    std::cout<<" "<<01;
            if(board[1][0] == Player::none)
                    std::cout<<" "<<10;
            if(board[1][1] == Player::none)
                    std::cout<<" "<<11;
        }
        if(a==0 && b==1)
        {
            if(board[0][0] == Player::none)
                    std::cout<<" "<<00;
            if(board[1][1] == Player::none)
                    std::cout<<" "<<11;
            if(board[0][2] == Player::none)
                    std::cout<<" "<<02;
        }
        if(a==0 && b==2)
        {
            if(board[0][1] == Player::none)
                    std::cout<<" "<<01;
            if(board[1][1] == Player::none)
                    std::cout<<" "<<11;
            if(board[1][2] == Player::none)
                    std::cout<<" "<<12;
        }
        if(a==1 && b==0)
        {
            if(board[0][0] == Player::none)
                    std::cout<<" "<<00;
            if(board[1][1] == Player::none)
                    std::cout<<" "<<11;
            if(board[2][0] == Player::none)
                    std::cout<<" "<<20;
        }
        if(a==1 && b==2)
        {
            if(board[0][2] == Player::none)
                    std::cout<<" "<<02;
            if(board[1][1] == Player::none)
                    std::cout<<" "<<11;
            if(board[2][2] == Player::none)
                    std::cout<<" "<<22;
        }
        if(a==2 && b==0)
        {
            if(board[1][0] == Player::none)
                    std::cout<<" "<<10;
            if(board[1][1] == Player::none)
                    std::cout<<" "<<11;
            if(board[2][1] == Player::none)
                    std::cout<<" "<<21;
        }
        if(a==2 && b==1)
        {
            if(board[2][0] == Player::none)
                    std::cout<<" "<<20;
            if(board[1][1] == Player::none)
                    std::cout<<" "<<11;
            if(board[2][2] == Player::none)
                    std::cout<<" "<<22;
        }
        if(a==2 && b==2)
        {
            if(board[1][2] == Player::none)
                    std::cout<<" "<<12;
            if(board[1][1] == Player::none)
                    std::cout<<" "<<11;
            if(board[2][1] == Player::none)
                    std::cout<<" "<<21;
        }
        if(a==1 && b==1)
        {
            if(board[0][0] == Player::none)
                    std::cout<<" "<<00;
            if(board[0][1] == Player::none)
                    std::cout<<" "<<01;
            if(board[0][2] == Player::none)
                    std::cout<<" "<<02;
            if(board[1][0] == Player::none)
                    std::cout<<" "<<10;
            if(board[1][2] == Player::none)
                    std::cout<<" "<<12;
            if(board[2][0] == Player::none)
                    std::cout<<" "<<20;
            if(board[2][1] == Player::none)
                    std::cout<<" "<<21;
            if(board[2][2] == Player::none)
                    std::cout<<" "<<22;
        }

    }
    void play()
    {
        int turn = 0;
        bool exit = false;

        printBoard();
        std::cout << " X : Human\n O : Computer\n - : none\n";
        std::cout << "Enter your move in coordinate form[row, col]. ex: 02\n";

        do
        {
            // human move
            if (turn == 0)
            {
                getHumanMove();
                turn=1;
                moveCount++;
                if (checkWin(Player::human))
                {
                    std::cout << "Human Wins\n";
                    exit = true;
                }
            }
            else
            {
                std::cout << "\nComputer Move: ";

                Move aimove = minimax();
                std::cout << aimove.x << aimove.y << " To " << aimove.p << aimove.q <<"\n";
                board[aimove.x][aimove.y] = Player::none;//source
                board[aimove.p][aimove.q] = Player::computer;//destination
                turn=0;

                if (checkWin(Player::computer))
                {
                    std::cout << "Computer Wins\n";
                    exit = true;
                }
            }

            if (isTie())
            {
                std::cout << "\n*** Tie ***\n";
                exit = true;
            }
            printBoard();

        } while (!exit);
    }
};

int main()
{
    Game tinguti;
    tinguti.play();
    std::cin.ignore();
}


