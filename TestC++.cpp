// Test22.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

class Weapon
{

public:
    Weapon()
    {
        cout << "job" << endl;
    }
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

    void shoting();

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
void gun::shoting()
{
    cout << "Bad" << endl;
}
class people
{
public:
    void shoot(Weapon* weapon)
    {
        weapon->shoot();
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
    knife1.shoting;

    return 0;
}

