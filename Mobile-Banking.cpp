#include<bits/stdc++.h>
#include<windows.h>

using namespace std;

class info
{
protected:
    string phonenumber;
    int operators,simtype;
public:
    void getsimtype()
    {
        cout << "1. PrePaid\t\t2. PostPaid" << endl;
        cin >> simtype;
    }
    void getoperators()
    {
        cout << "Which Operator?\n1. Airtel\t\t2. Robi\n3. Grameenphone\t\t4. Banglalink\n5. Teletalk" << endl;
        cin >> operators;
    }
    void getphnmber()
    {
        cout << "Enter Phone Number: ";
        cin >> phonenumber;
    }

    void nmeassage()
    {
        cout << "Your Transiction is Stopped!!!\n\tThank You!!!" << endl;
    }
};

class fileclass
{
protected:
    int balance, newbalance;
    int amount;
public:
    void getamount()
    {
        cout << "Enter Ammount: ";
        cin >> amount;
    }

    void sub_bal()
    {

        getamount();
        fstream file("balance.txt", ios::in);
        file >> balance;
        try
        {
            if(amount>20000 && amount>balance)
            {
                throw new exception();
            }

            else if(amount>20000)
            {
                throw "You Can't withdraw than tk. 20000/- \n";
            }
            else if(amount>balance)
            {
                throw amount-balance;
            }
            else if(amount<0)
            {
                throw "You can't give negative value\n";
            }
            else
            {
                newbalance = balance - amount;
                file.close();
                file.clear();
                file.open("balance.txt", ios::out);
                file << newbalance;
                file.close();
                cout << "Your Transaction Is Successfull!!\nThank You for using Bkash" << endl;
            }
        }
        catch(const char* m)
        {
            cout<<m<<endl;
        }
        catch(int deficit)
        {
            cout<<"You have a deficit of : "<<deficit<<endl<<endl;
        }
        catch(...)
        {
            cout<<"You have a deficit and You Can't withdraw than tk. 20000/-"<<endl<<endl;
        }
    }

    void add_bal()
    {
        getamount();
        double balance, newbalance;
        fstream file("balance.txt", ios::in);
        file >> balance;
        try
        {
            if(amount>20000)
            {
                throw "You can't cash in more than 20000/-\n";
            }
            else if(amount<0)
            {
                throw "You can't give negative value\n";
            }

            newbalance = balance + amount;
            file.close();
            file.clear();
            file.open("balance.txt", ios::out);
            file << newbalance;
            file.close();
            cout << "Your Transaction Is Successfull!!\nThank You for using Bkash" << endl;
        }
        catch(const char * mmm)
        {
            cout<<mmm<<endl;
        }
    }
};

class pay_bill :private info, fileclass
{
private:
    int choice, counter = 0;
public:
    void showbills()
    {
        cout << "Select Billers: \n 1. Palli Bidyut\t\t2. DESCO(Prepaid)\n 3. DESCO(Postpaid)\t\t4. NESCO\n 5. BTCL\t\t\t6. Carnival\n 7. BTEB" << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter Palli Bidyut ";
            info::getphnmber();

            fileclass::sub_bal();

        }
        else if (choice == 2)
        {
            cout << "Enter DESCO(Prepaid) ";
            info::getphnmber();

            fileclass::sub_bal();
        }
        else if (choice == 3)
        {
            cout << "Enter DESCO(Postpaid) ";
            info::getphnmber();

            fileclass::sub_bal();
        }
        else if (choice == 4)
        {
            cout << "Enter NESCO ";
            info::getphnmber();

            fileclass::sub_bal();
        }
        else if (choice == 5)
        {
            cout << "Enter BTCL ";
            info::getphnmber();

            fileclass::sub_bal();
        }
        else if (choice == 6)
        {
            cout << "Enter Carnival ";
            info::getphnmber();

            fileclass::sub_bal();
        }
        else if (choice == 7)
        {
            cout << "Enter BTEB ";
            info::getphnmber();

            fileclass::sub_bal();
        }
        else
        {
            while ((((choice != 1) || (choice != 2) || (choice != 3) || (choice != 4) || (choice != 5) || (choice != 6) || (choice != 7))) && (counter < 2))
            {
                cout << "Wrong Choice!! Try Again!!" << endl;
                cout << "Select Billers: \n 1. Palli Bidyut\t\t2. DESCO(Prepaid)\n 3. DESCO(Postpaid)\t\t4. NESCO\n 5. BTCL\t\t6. Carnival\n 7. BTEB" << endl;
                cin >> choice;
                if (choice == 1)
                {
                    cout << "Enter Palli Bidyut ";
                    info::getphnmber();

                    fileclass::sub_bal();
                }
                else if (choice == 2)
                {
                    cout << "Enter DESCO(Prepaid) ";
                    info::getphnmber();

                    fileclass::sub_bal();
                }
                else if (choice == 3)
                {
                    cout << "Enter DESCO(Postpaid) ";
                    info::getphnmber();

                    fileclass::sub_bal();
                }
                else if (choice == 4)
                {
                    cout << "Enter NESCO ";
                    info::getphnmber();

                    fileclass::sub_bal();
                }
                else if (choice == 5)
                {
                    cout << "Enter BTCL ";
                    info::getphnmber();

                    fileclass::sub_bal();
                }
                else if (choice == 6)
                {
                    cout << "Enter Carnival ";
                    info::getphnmber();

                    fileclass::sub_bal();
                }
                else if (choice == 7)
                {
                    cout << "Enter BTEB ";
                    info::getphnmber();

                    fileclass::sub_bal();
                }
                else
                {
                    counter++;
                }
            }
        }
    }
};

class cash_out : private info, fileclass
{
private:
    char confirm;
    int cshoutchoice;
public:
    void cshout()
    {
        cout << "1. From Agent\t\t2. From ATM" << endl;
        cin >> cshoutchoice;
        if (cshoutchoice == 1)
        {
            info::getphnmber();
            cout << "Are You Sure To Continue This Proccess: (y/n)";
            cin >> confirm;
            if (confirm == 'y')
            {
                fileclass::sub_bal();
            }
            else if (confirm == 'n')
            {
                info::nmeassage();
            }
        }
        else if (cshoutchoice == 2)
        {
            int atmotp = rand();
            cout << "Enter This Code in ATM Machine: " << atmotp << endl;
            cout << "Thank You!!" << endl;
            exit;
        }
        else
        {
            cout<<"Wrong choice..!!!"<<endl;
        }
    }
};

class make_payment : private info, fileclass
{
private:
    char confirm;
public:
    void getmakepayment()
    {
        cout << "Enter Merchant ";
        info::getphnmber();
        cout << "Are You Sure To Continue This Proccess: (y/n)";
        cin >> confirm;
        if (confirm == 'y')
        {
            fileclass::sub_bal();
        }
        else if (confirm == 'n')
        {
            info::nmeassage();
        }
    }
};

class addmoney : private info, fileclass
{
private:
    int addmoneychoice, bankchoice, counter = 0;
    string cardnumber, cardholdername;
public:
    void admoney()
    {
        cout << "1. Bank To Bkash\n2. Card To Bkash " << endl;
        cin >> addmoneychoice;
        if (addmoneychoice == 1)
        {
            cout << "Choose The Bank: \n1. BRAC BANK \t\t2. City Bank\n3. Dhaka Bank\t\t4. Midland Bank\n5. Mitual Trust Bank\t\t6. Standered Chatered Bank" << endl;
            cin >> bankchoice;
            if (bankchoice == 1)
            {
                char* linkChar = "https://ibanking.bracbank.com/bblonline/";
                ShellExecute(NULL, NULL, linkChar, NULL, NULL, SW_SHOWNORMAL);
            }
            else if (bankchoice == 2)
            {
                char* linkChar = "https://www.citytouch.com.bd:8443/loginn.html";
                ShellExecute(NULL, NULL, linkChar, NULL, NULL, SW_SHOWNORMAL);
            }
            else if (bankchoice == 3)
            {
                char* linkChar = "https://ib.dhakabank.com.bd";
                ShellExecute(NULL, NULL, linkChar, NULL, NULL, SW_SHOWNORMAL);
            }
            else if (bankchoice == 4)
            {
                char* linkChar = "https://ibanking.midlandbankbd.net/loginnpage";
                ShellExecute(NULL, NULL, linkChar, NULL, NULL, SW_SHOWNORMAL);
            }
            else if (bankchoice == 5)
            {
                char* linkChar = "https://ibank.mutualtrustbank.com/loginn/loginn.aspx";
                ShellExecute(NULL, NULL, linkChar, NULL, NULL, SW_SHOWNORMAL);
            }
            else if (bankchoice == 6)
            {
                char* linkChar = "https://www.online-banking.standardchartered.com/loginn/BD";
                ShellExecute(NULL, NULL, linkChar, NULL, NULL, SW_SHOWNORMAL);
            }
        }
        else if (addmoneychoice == 2)
        {
            cout << "Enter Card Number: ";
            cin >> cardnumber;
            cout << "Enter Cardholder's Name: ";
            cin >> cardholdername;
            fileclass::add_bal();
        }
        else
        {
            while ((addmoneychoice != 1 || addmoneychoice != 2) && counter < 2)
            {
                cout << "Wrong Choice!! Enter Again..." << endl;
                cout << "1. Bank To Bkash\n2. Card To Bkash: ";
                cin >> addmoneychoice;
                if (addmoneychoice == 1)
                {
                    cout << "Choose The Bank: \n1. BRAC BANK \t\t2. City Bank\n3. Dhaka Bank\t\t4. Midland Bank\n5. Mitual Trust Bank\t\t6. Standered Chatered Bank" << endl;
                    cin >> bankchoice;
                }
                else if (addmoneychoice == 2)
                {
                    cout << "Enter Card Number: ";
                    cin >> cardnumber;
                    cout << "Enter Cardholder's Name: ";
                    cin >> cardholdername;
                    fileclass::add_bal();
                }
                else
                {
                    counter++;
                }
            }
        }
    }
};

class mobile_recharge :private info, fileclass
{
private:
    char confirm;
public:
    void mobilerecharg()
    {
        cout << "Enter ";
        info::getphnmber();
        info::getsimtype();
        info::getoperators();
        cout << "Are You Sure To Continue This Proccess: (y/n)";
        cin >> confirm;
        if (confirm == 'y')
        {
            fileclass::sub_bal();
        }
        else if (confirm == 'n')
        {
            info::nmeassage();
        }
    }
};

class sendmoney :private info, fileclass
{
private:
    string confirm;
public:
    void smoney()
    {
        info::getphnmber();
        cout << "Are You Sure To Continue This Proccess: (y/n)";
        cin >> confirm;
        if (confirm == "y")
        {
            fileclass::sub_bal();
        }
        else
        {
            info::nmeassage();
        };
    }
};

class blanceinfo
{
public:
    void showbalance()
    {
        int balance;
        ifstream file("balance.txt");
        file >> balance;
        file.close();
        cout << "Your Current Balance Is: " << balance << endl;
    }
};

class options :private blanceinfo, sendmoney, mobile_recharge, addmoney, make_payment, cash_out, pay_bill
{
private:
    int choice;
public:
    void get_choice()
    {
        while (choice != 8)
        {
            cout << " 1. See Balance \t2. Send Money \n 3. Mobile Recharge \t4. Add Money \n 5. Make Payment \t6. Cash Out \n 7. Pay Bill \n 8. Exit" << endl;
            cin >> choice;
            if (choice == 1)
            {
                blanceinfo::showbalance();
            }
            else if (choice == 2)
            {
                sendmoney::smoney();
            }
            else if (choice == 3)
            {
                mobile_recharge::mobilerecharg();
            }
            else if (choice == 4)
            {
                addmoney::admoney();
            }
            else if (choice == 5)
            {
                make_payment::getmakepayment();
            }
            else if (choice == 6)
            {
                cash_out::cshout();
            }
            else if (choice == 7)
            {
                pay_bill::showbills();
            }
            exit;
        }
    }
};

class login :private options
{
private:
    string loginn_num, pin;
    int counter = 0;
public:
    void get_userinfo()
    {
        cout << "\n\n\t\t\t\t\t\t\t\t\t\t BKASH ACCOUNT" << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t  ";
        cin >> loginn_num;
        cout << "\n\n\t\t\t\t\t\t\t\t\t     ENTER YOUR BKASH PIN" << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t ";
        cin >> pin;
        ifstream myfile("password.txt");
        if (myfile.is_open())
        {
            string id, pass;
            while (myfile >> id >> pass)
            {
                if ((loginn_num == id) && (pin == pass))
                {
                    options::get_choice();
                }
                else if((loginn_num != id) || (pin != pass))
                {
                    while ((loginn_num != id) || (pin != pass) && (counter < 2))
                    {
                        cout << "\n\t\t\t\t\t\t\t\t\t\tWrong Information!! Try Again....." << endl;
                        cout << "\n\n\t\t\t\t\t\t\t\t\t\tBKASH ACCOUNT" << endl;
                        cout << "\t\t\t\t\t\t\t\t\t\t";
                        cin >> loginn_num;
                        cout << "\n\n\t\t\t\t\t\t\t\t\t     ENTER YOUR BKASH PIN" << endl;
                        cout << "\t\t\t\t\t\t\t\t\t\t";
                        cin >> pin;
                        if ((loginn_num == id) && (pin == pass))
                        {
                            options::get_choice();
                        }
                        else
                        {
                            counter++;
                        }
                    }
                }

            }
        }

    }
};

int main()
{
    srand((unsigned)time(0));

    cout << "\t\t\t\t\t\t\t\t\t\tWelcome to BKASH" << endl;
    cout << "\t\t\t\t\t\t\t\t\t      ********************\n\n" << endl;
    login l1;
    l1.get_userinfo();
}
