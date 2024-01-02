#include <conio.h>
#include <iostream>
#include <string>
using namespace std;

class atm
{
private:
    long int accountNo;
    string userName;
    int pin;
    string mobileNo;
    double balance;

public:
    void setData(long int accountVar, string userVar, int pinVar, string mobileVar, double balanceVar)
    {
        accountNo = accountVar;
        userName = userVar;
        mobileNo = mobileVar;
        pin = pinVar;
        balance = balanceVar;
    }

    long int getAccount()
    {
        return accountNo;
    }

    string getUser()
    {
        return userName;
    }

    int getPin()
    {
        return pin;
    }

    string getMobile()
    {
        return mobileNo;
    }

    double getBalance()
    {
        return balance;
    }

    void setMobile(string mobileOld, string mobileNew)
    {
        if (mobileNo == mobileOld)
        {
            mobileNo = mobileNew;
            cout << "Mobile No Updated Successfully" << endl;
            getch();
        }
        else
        {
            cout << "Invalid Mobile No" << endl;
            getch();
        }
    }

    void cashWithdraw(int amountVar)
    {
        if (amountVar > 0 && amountVar <= balance)
        {
            balance -= amountVar;
            cout << "Please Collect your cash" << endl;
            cout << "Remaining Balance = " << balance;
            getch();
        }
        else
        {
            cout << "Invalid Amount" << endl;
            getch();
        }
    }
};

int main()
{
    int choice = 0, userPin;
    long int userAccount;

    system("cls");

    atm user;

    user.setData(1234567, "Nihal", 1111, "9087654321", 45000.99);

    do
    {
        system("cls");

        cout << "***WELCOME TO ATM***" << endl;

        cout << "Enter the Account No - ";
        cin >> userAccount;
        cout << "Enter the Pin - ";
        cin >> userPin;

        if (userAccount == user.getAccount() && userPin == user.getPin())
        {
            do
            {
                int amount = 0;
                string mobileOld, mobileNew;

                system("cls");

                cout << endl
                     << "**** Welcome to ATM *****" << endl;
                cout << endl
                     << "Select Options ";
                cout << endl
                     << "1. Check Balance";
                cout << endl
                     << "2. Cash withdraw";
                cout << endl
                     << "3. Show User Details";
                cout << endl
                     << "4. Update Mobile no.";
                cout << endl
                     << "5. Exit" << endl;
                cin >> choice;

                switch (choice)
                {
                case 1:
                    cout << "Your Balance is - " << user.getBalance();
                    getch();
                    break;

                case 2:
                    cout << "Input the Amount to Withdraw = ";
                    cin >> amount;
                    user.cashWithdraw(amount);
                    getch();
                    break;

                case 3:
                    cout << "User Details are " << endl;
                    cout << endl
                         << "-> Account no = " << user.getAccount();
                    cout << endl
                         << "-> Name       = " << user.getUser();
                    cout << endl
                         << "-> Balance    = " << user.getBalance();
                    cout << endl
                         << "-> Mobile No. = " << user.getMobile();
                    getch();
                    break;

                case 4:
                    cout << "Enter the Old Mobile No - ";
                    cin >> mobileOld;

                    cout << "Enter the New Mobile No - ";
                    cin >> mobileNew;

                    user.setMobile(mobileOld, mobileNew);
                    getch();
                    break;

                case 5:
                    exit(0);

                default:
                    cout << "Invalid choice !!!" << endl;
                }

            } while (1);
        }

        else
        {
            cout << "User Details are invalid!!" << endl;
            getch();
        }

    } while (1);

    return 0;
}
