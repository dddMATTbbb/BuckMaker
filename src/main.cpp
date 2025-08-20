#include <iostream>
#include <ctime>
#include <limits>
//show your balance and cash
void showBalance(double balance, double pocket);
//this allows you to deposit cash into the bank
double deposit(double pocket);
//this allows you to convert money in the bank into cash
double withdraw(double balance, double pocket);
//this allows you to earn money by typing a sentence CORRECTLY
double work();
//gambling game where you can earn money (chance of winning 1/3)
double play(double pocket);

int main()
{
    double balance = 100;
    double pocket = 250;
    double withdrawAmount = 0;
    double depositAmount = 0;
    int choice = 0;

    //set the seed for the random function based on time
    srand(time(NULL)); //for the time() function you need <ctime>!!
    
    do{
        std::cout << "Enter your choice:\n";
        std::cout << "1. Show balance\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Work\n";
        std::cout << "5. Play a game and maybe win money :)\n";
        std::cout << "6. Exit\n";
        std::cin >>choice;

        // check if input is valid
        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input!\n";
            continue;
        }

        //main menu for the player
        switch (choice)
        {
            case 1: showBalance(balance, pocket); //shows current balance and cash
                    break;
            case 2: depositAmount = deposit(pocket); //deposit money
                    balance += depositAmount;
                    pocket -= depositAmount;
                    showBalance(balance, pocket);
                    break;
            case 3: withdrawAmount = withdraw(balance, pocket); //withdraw money
                    balance -= withdrawAmount;
                    pocket += withdrawAmount;
                    showBalance(balance , pocket);
                    break;
            case 4: balance += work(); //perform work
                    break;
            case 5: pocket = play(pocket);// game of chance
                    break;
            case 6: std::cout << "Thanks for visiting!\n";
                    break;
            default:std::cout << "Invalid choice, try again\n";
                    break;
        }
    }while(choice != 6);

    return 0;
}
void showBalance(double balance, double pocket){
    std::cout << "Your balance is: " << balance << std::endl;
    std::cout << "Your pocket money is: " << pocket << std::endl;
}

double deposit(double pocket){
    double amount = 0;
    std::cout << "Enter amount to be deposited: ";
    std::cin >> amount;

    if (amount > pocket){
        std::cout << "You do not have that much money to deposit\n";
        return 0;
    }
    else if (amount <= 0){
        std::cout << "This is an invalid number\n";
        return 0;
    }
    else{
        return amount;
    }

}

double withdraw(double balance, double pocket){

    double amount = 0;
    std::cout << "Enter the amount to be withdrawn: ";
    std::cin >> amount;
    if (amount > balance){
        std:: cout << "Insufficient funds\n";
        return 0;
    }
    else if(amount < 0){
        std::cout << "That's not a valid amount\n";
        return 0;
    }
    else{
        return amount;
    }
}

double work() {
    //NOTE: You need std::string to define a string, not just 'string' as you do with 'int', because int is a built-in data type.
    //(Just like double, char, and bool) string isn't, but it is in the standard library(std)
    std::string answer = "i am working for a company";
    std::string answerUser;
    std::cout << "Type: 'i am working for a company' to collect 50 bucks\n";

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //you need <limits> for this function!!
    std::getline(std::cin, answerUser);

    if (answerUser == answer)
    {
        std::cout << "Good boyyyyy\n";
        return 50;
    }
    else
    {
        std::cout << "bad boyyyyyy\n";
        return 0;
    }
}

double play(double pocket){

    int num = (rand() % 3) + 1;
    int userNum;
    double userStake;

    std::cout << "Guess the number from 1 to 3. If you get it right, your stake will be doubled.\n";
    std::cout << "What is your stake?\n";
    std::cout << "Stake: ";
    std::cin >> userStake;
    
    if (userStake > pocket){
        std::cout << "You don't have that much money!\n";
    }
    else if (userStake < 0){
        std::cout << "Invalid number\n";
    }
    else if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(1000, '\n'); // removes incorrect input
        std::cout << "Invalid input, try again!\n";
    }
    else{
        std::cout << "What number do you think it is (1 through 3)?\n";
        std::cin >> userNum;
        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(1000, '\n'); // removes incorrect input
            std::cout << "Invalid input, try again!\n";
        }
        else if(userNum == num){
            std::cout << "Well done, you guessed the right number\n";
            pocket += userStake;
        }
        else{
            std::cout << "Unfortunately you didn't guess the correct number, the correct number was: " << num << "\n";
            pocket -= userStake;
        }
    }

    return pocket;
}


//credit: dddMATTbbb on github