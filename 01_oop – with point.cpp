#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void func()
{
    cout << "func work" << endl;
}

void func2()
{

}

// модифікатори доступу
// public   - доступно для об'єкту
// private  - не доступно для об'єкту
// protected


// в класі по дефолту все private
// в структурі по дефолту все public

// get set - використовуються для доступу до приватних полів
// аксессор модифікатор 
class BankCard
{
private:
    // поля класу
    double balance;
    string number;
    int cvv;

    int randomValue(int min, int max)
    {
        return min + rand() % ((max + 1) - min);
    }
public:    
    void init()
    {
        balance = 0;
        cvv = randomValue(100, 999);

        for (size_t i = 0; i < 16; i++)
        {
            // int -> string
            number += to_string(randomValue(0, 9));
        }
    }

    // Поповнити
    void deposite(double value)
    {
        balance += value;
    }

    // Зняти
    void withdraw(double value)
    {
        if (balance >= value)
        {
            balance -= value;
        }
        else
        {
            cout << "Insufficient funds on the balance sheet" << endl;
        }
    }

    // inline методи
    inline double getBalance()
    {
        return balance;
    }

    int getCVV()
    {
        return cvv;
    }

    void setCVV(int value)
    {
        if (value >= 100 && value <= 999)
        {
            cvv = value;
        }
        else
        {
            cout << "Incorrent cvv" << endl;
        }
    }

    string getNumber(bool hidden = true)
    {
        string result = "";
        if (hidden)
        {
            result = "**** **** **** ";
            result += number.substr(12, 4);
        }
        else
        {
            for (size_t i = 0; i < 4; i++)
            {
                result += number.substr(i * 4, 4);
                result += " ";
            }

            /*for (size_t i = 0; i < number.length(); i++)
            {
                if (i % 4 == 0 && i != 0)
                {
                    result += " ";
                }
                result += number[i];
            }*/
        }

        return result;
    }

    void printInfo()
    {
        cout << "Number: " << getNumber(false) << endl;
        cout << "CVV: " << cvv << endl;
        cout << "Balance: " << balance << endl;
    }
};

class Point
{
private:
    int x = 5, y = 10, z = 2;
public:
    void setX(int v)
    {
        x = v;
    }
    void setY(int v)
    {
        y = v;
    }
    void setZ(int v)
    {
        z = v;
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

    int getZ()
    {
        return z;
    }

    void print()
    {
        cout << x << ", " << y << ", " << z << endl;
    }

    void input()
    {
        cout << "Enter x,y,z: ";
        cin >> x >> y >> z;
    }

    void saveToFile()
    {
        ofstream file("point.txt");
        if (file)
        {
            file << x << " " << y << " " << z;

            file.close();
        }
    }

    void loadFromFile()
    {
        ifstream file("point.txt");
        if (file)
        {
            file >> x >> y >> z;

            file.close();
        }
    }
};

int main()
{
    string str;

    srand(time(0));
    /*void(*funcPtr)() = func;*/ // покажчик на функцію

    // ООП - об'єктно орієнтоване програмування
    // Принципи ООП
    // 1 - Інкапсуляція 
    // 2 - Наслідування
    // 3 - Поліморфізм

    // змінні -> поля класу
    // функції -> методи класу




    //BankCard card; // об'єкт
    //BankCard* card2 = new BankCard();

    //card2->balance = 100;
    //cout << card2->balance << endl;

    //card.balance = 500;
    //cout << card.balance << endl;






    //BankCard* card = new BankCard();
    //BankCard* card2 = new BankCard();
    //BankCard* card3 = new BankCard();

    //card->init();
    //card2->init();
    //card3->init();

    //card->deposite(1000);
    //cout << card->getBalance() << endl;
    //card->withdraw(500);
    //cout << card->getBalance() << endl; // get метод -> отримати баланс

    ////card->setCVV(965); // set метод -> записати cvv
    //cout << "Card 1" << endl;
    //card->printInfo();
    //cout << "Card 2" << endl;
    //card2->printInfo();
    //cout << "Card 3" << endl;
    //card3->printInfo();


    //fstream f("", fstream::in | ios::out | ios::ate);

    Point p;
    p.saveToFile();
}
