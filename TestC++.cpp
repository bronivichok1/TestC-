// Test22.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>


using namespace std;

class Weapon
{

public:
    Weapon() {};
    virtual ~Weapon() = 0;
    virtual void shoot() = 0;
};
Weapon::~Weapon() {};
class gun :public Weapon
{

public:
    int weight;
    string color;
    int age;
    gun() {};
    gun(string color)
    {
        this->color = color;
        this->weight = 0;
        this->age = 0;

        cout << "job" << endl;
    }
    gun(string color, int age) :gun(color)
    {
        this->age = age;
    }
    gun(string color, int age, int weight) :gun(color, age)
    {
        this->weight = weight;
    }
    ~gun() override
    {
        cout << "clear" << endl;
    }
    void shoot() override
    {
        cout << "Bang" << endl;
    }

    void shoting()
    {
        cout << "Bad" << endl;
    }

};
class speedgun : public gun
{
public:
    speedgun()
    {
        cout << "job" << endl;
    }
    ~speedgun() override
    {
        cout << "clear" << endl;
    }
    void shoot() override
    {
        cout << "Bang*3" << endl;
        return ::gun::shoot();
    }


};
class knife :public Weapon, public gun
{

public:
    knife()
    {
        cout << "job" << endl;
    }
    ~knife() override
    {
        cout << "clear" << endl;
    }
    void shoot() override
    {
        cout << "tyk" << endl;
    }

};
void foo()
{
    cout << "nice" << endl;
}

class people
{
public:
    void shoot(Weapon* weapon)
    {
        weapon->shoot();
    }
};
class IBicycle //"интерфейс в с++"
{
public:
    void virtual Ride() = 0;
    void virtual TheCorner()=0;
};
class Bicycle :public IBicycle
{
    void Ride() override
    {
        cout << "JobRide" << endl;
    }
    void TheCorner() override
    {
        cout<<"JobCorner"<<endl;
    }
};
class Human
{
public:
    void RideOn(IBicycle &bicycle)
    {
        bicycle.Ride();
        cout<<"Go"<<endl;
        bicycle.TheCorner();
        cout<<"Left"<<endl;
    }

};
int main()
{
    void(*foopoint)();
    foopoint = foo;
    foopoint();//указатель на метод в качестве параметра

    knife knife1;
    people people1;
    people1.shoot(&knife1);
    knife knife2;
    ((gun)knife2).shoot();
    
    Bicycle bicycle1;
    Human Human1;
    Human1.RideOn(bicycle1);

    string path = "Test.txt";
    ofstream foud;
    foud.open(path,ofstream::app);
    
    if (!foud.is_open())
    {
        cout << "error" << endl;
    }
    else 
    {
        foud<<"\ new data";
    }
    foud.close();

    ifstream fin;
    fin.open(path);

    if (!fin.is_open())
    {
        cout << "error" << endl;
    }
    else
    {
        string str;
        /*char ch;
        while (fin.get(ch))
        {
            cout << ch << endl;
        }*/
        while (!fin.eof())
        {
            str = "";
            getline(fin, str);
            cout << str << endl;
        }
    }
    fin.close();
    return 0;
}

