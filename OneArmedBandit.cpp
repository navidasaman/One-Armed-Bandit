#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

int main()
{
    int balance = 0;                        // Player starts with 0 kr in their account
    int bet;                                // Player has the possibility to bet
    int winnings;                           // Calculated winnings
    void GameRules();                       // Function containing game rules
    int InsertMoney(int balance);           // Function which gives player option to insert 100, 300 or 500 kr.
    int RowAmount(int RowsWon, int bet);    // Calculates how many rows that were aligned
    GameRules();
    bool GameLoop = 1;
    while (GameLoop)
    {
        // Option to refill bank balance is given when the balance reacehes 0 kr
        string answer;
        if (balance == 0)
        {
            bool LowBalanceloop = 1;
            while (LowBalanceloop)
            {
                cout << "Your account balance is low! Insert money to proceed? yes/no? " << endl;
                cin >>
                answer;
                if (answer == "yes" || answer == "YES" || answer == "Yes")
                {
                    balance = InsertMoney(balance); // Function is called alongside the
                    value of the new balance
                    cout << "You inserted " << balance << "kr" << endl;
                    break;
                }
                else if (answer == "no" || answer == "NO" || answer == "No")
                {
                    cout << "Goodbye!" << endl;
                    exit(0);
                }
            }
        }
        // Player has the choice to play
        bool ReplayLoop = 1;
        string replay;

        while (ReplayLoop)
        {
            cout << "Type in: Play or Exit?" << endl;
            cin >> replay;

            if (replay == "Play" || replay == "PLAY" || replay == "play")
            {
                cout << "Make a bet" << endl;
                cin >> bet;

                cout << endl;
                while (bet > balance)
                {
                    cout << "You only have: " << balance << "kr in your account !" << " Please make a valid bet." << endl;
                    cin >>
                    bet;
                }
                break;
            }
            else if (replay == "Exit" || replay == "EXIT" || replay == "exit")
            {
                cout << "Goodbye! Enjoy your money." << endl;
                cout << endl;
                exit(0);
            }
        }

        // generates vertically randomised symbol
        char Letters[] = {'A', 'O', 'X'};
        char gamematrix[3][3];
        int y;
        int x;
        for (y = 0; y < 3; y++)
        {
            for (x = 0; x < 3; x++) // generates horizontally randomised symbol
            {
                gamematrix[y][x] = Letters[rand() % 3];
                cout << gamematrix[y][x];
            }
            cout << endl;
        }
        cout << endl;
        // If player wins:
        int RowsWon = 0;
        // Player wins diagonally
        if (gamematrix[0][0] == gamematrix[1][1] && gamematrix[0][0] == gamematrix[2][2])
        {
            RowsWon++;
        }
        // Player wins diagonally
        if (gamematrix[0][2] == gamematrix[1][1] && gamematrix[0][2] == gamematrix[2][0])
        {
            RowsWon++;
        }
        // if player wins vertically on the first row
        if (gamematrix[0][0] == gamematrix[1][0] && gamematrix[0][0] == gamematrix[2][0])
        {
            RowsWon++;
        }
        // if player wins vertically on the second row
        if (gamematrix[0][1] == gamematrix[1][1] && gamematrix[0][1] == gamematrix[2][1])
        {
            RowsWon++;
        }
        // if player wins vertically on the third row
        if (gamematrix[0][2] == gamematrix[1][2] && gamematrix[0][2] == gamematrix[2][2])
        {
            RowsWon++;
        }
        // if player wins horizontally on the first row
        if (gamematrix[0][0] == gamematrix[0][1] && gamematrix[0][0] == gamematrix[0][2])
        {
            RowsWon++;
        }
        // if player wins horizontally on the second row
        if (gamematrix[1][0] == gamematrix[1][1] && gamematrix[1][0] == gamematrix[1][2])
        {
            RowsWon++;
        }
        // if player wins horizontally on the third row
        if (gamematrix[2][0] == gamematrix[2][1] && gamematrix[2][0] == gamematrix[2][2])
        {
            RowsWon++;
        }
        // Win or loss is displayed
        winnings = RowAmount(RowsWon, bet);
        cout << "Number of rows aligned: " << RowsWon << "." << endl;
        balance = (balance + winnings) - bet;
        cout << "Balance: " << balance << endl;
    }
    return 0;
}
// Function with the game rules
void GameRules()
{
    cout << "Welcome to the slot machine: one armed bandit!" << endl;
    cout << "You can win by achieving three identical symbols horizontally, / or diagonally " << endl; 
    cout << " - You have the option to insert 100, 300 or 500 kr" << endl;
    cout << " - You then have the option to bet money per round" << endl;
    cout << " One row gives 2 * bet" << endl;
    cout << " Two rows gives 3 * bet" << endl;
    cout << " Three rows gives 4 * bet" << endl;
    cout << " Four rows gives 5 * bet" << endl;
    cout << " Five rows gives 7 * bet" << endl;
    cout << " Six rows gives 8 * bet" << endl;
    cout << " Eight rows gives 10 * bet" << endl;
    cout << " Lets start!" << endl;
    cout << endl;
}
// Function which returns balance and uses parameter
int InsertMoney(int balance)
{
    int InserT;
    bool MoneyLoop = 1;
    while (MoneyLoop)
    {
        cout << "Insert 100, 300 or 500 kr" << endl;
        cin >> InserT;

        if (InserT == 100 || InserT == 300 || InserT == 500)
        {
            balance = balance + InserT;
            return balance;
            break;
        }
        else
        {
            cout << "Invalid amount!" << endl;
        }
    }
    return 0;
}
// Function which returns winnings and uses parameters
int RowAmount(int RowsWon, int bet)
{
    int WinningAmount = 0;
    switch (RowsWon)
    {
    case 1:
        WinningAmount = (bet * 2);
        cout << "Congratulations, You won " << WinningAmount << "kr!" << endl;
        return WinningAmount;
        break;
    case 2:
        WinningAmount = (bet * 3);
        cout << "Congratulations, You won " << WinningAmount << "kr!" << endl;
        return WinningAmount;
        break;
    case 3:
        WinningAmount = (bet * 4);
        cout << "Congratulations, You won " << WinningAmount << "kr!" << endl;
        return WinningAmount;
        break;
    case 4:
        WinningAmount = (bet * 5);
        cout << "Congratulations, You won " << WinningAmount << "kr!" << endl;
        return WinningAmount;
        break;
    case 5:
        WinningAmount = (bet * 7);
        cout << "Congratulations, You won " << WinningAmount << "kr!" << endl;
        return WinningAmount;
    case 6:
        WinningAmount = (bet * 8);
        cout << "Congratulations, You won " << WinningAmount << "kr!" << endl;
        return WinningAmount;
        break;
    case 8:
        WinningAmount = bet * 10;
        cout << "Congratulations, You won " << WinningAmount << "kr!" << endl;
        return WinningAmount;
        break;
    case 0:
        cout << "You lost the bet of: " << bet << "kr" << endl;
        WinningAmount = 0;
        return WinningAmount;
        break;
    }
    return 0;
}