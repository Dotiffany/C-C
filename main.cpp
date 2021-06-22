#include <iostream>
#include <cstdlib>
using namespace std;

int wallet = 100;
int sum = 0;
int count = 0;
int num1, num2, num3;

// Main function
int main()
{
    int option;
    cout << "Welcome to the Three card game !\n";
    cout << "Player will have $100 free in their performance!\n";
    cout << "If your money in your wallet is less than $10, the game will stop since you lose!";
    cout <<"1.Help\n";
    cout << "2.Specify your betting position for the three cards\n";
    cout << "3.Generate 3 random numbers for the three cards\n";
    cout << "4.Check player's performance\n";
    cout << "5.Quit\n";
    cout << "Enter your option:";
    cin >> option;
    if (option == 1)
        cout << endl;
    else if (option == 2)
    {
        if (wallet < 10)
        {
            cout << "Sorry you do not have enough money to play!";
        }
        else {
            Betting();
            exit(0);
        }    
    }
    else if (option == 3)
    {
        Number();
        exit(0);
    }
    else if (option == 4)
    {
        Performance();
    }
    else {
        exit(0);
    }
    return 0;
}

// Betting function for three positions
int Betting()
{
    int position;
    cout << "Choosing one of three position:";
    cout << "1. The sum of three cards from 5 to 10 or 20 to 25 ($10)";
    cout << "2. The sum of three cards from 1 to 20 and even ($15)";
    cout << "3. The sum of three cards from 20 to 31 and 2 cards with the same numbers ($30)";
    cin >> position;
    if (position == 1)
    {
        Number();
        if (((sum <= 10)&&(sum >= 5)) || ((sum >= 20)&&(sum <= 25)))
        {
            wallet = wallet + 10;
            cout << "Congratulation you won $10!";
        }
        else {
            wallet = wallet - 10;
            cout << "Oh No! You lose $10!";
        }
    }
    else if (position == 2)
    {
        Number();
        if (((sum >= 1)&&(sum <= 20)) && (sum % 2 ==0))
        {
            wallet = wallet +15;
            cout << "Congratulation you won $15!";
        }
        else {
            wallet = wallet - 15;
            cout << "Oh No! You lose $15!";
        }
    }
    else {
        Number();
        if (((sum >= 20)&&(sum <= 31)) && ((num1 == num2)||(num1 == num3)||(num2 == num3)))
        {
            wallet = wallet + 30;
            cout << "Congratulation you won $30!";
        }
        else {
            wallet = wallet - 30;
            cout << "Oh No! You lose $30!";
        }
    }

}

// Function for three random numbers from 1 to 13
int Number()
{
    int num1 = (1 + (rand()%14));
    int num2 = (1 + (rand()%14));
    int num3 = (1 + (rand()%14));
    sum = (num1 + num2 + num3);
    cout << "Random number one:" << num1 << endl;
    cout << "Random number two:" << num2 << endl;
    cout << "Rnadom number three:" << num3 << endl;
}

// Repeat function and count the time that function runs
float repeat()
{
    char repeat;
    int count =0;
    cout << "Do your want to continue (Y/N):";
    cin >> repeat;
    if (repeat == 'Y')
    {
        count++;
        cout << "The game has been run:" << count << "times" << endl;
        main();
    }
}

// Checking wallet
int Performance()
{
    cout << "Total money you have now:" << wallet << endl;
    int MoneyWin = wallet - 100;
    cout << "The money that you gain:" << MoneyWin << endl;
    int MoneyLose = 100 - wallet;
    cout << "The money that you lose:" << MoneyLose << endl;
    main();
}
