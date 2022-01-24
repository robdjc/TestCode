#include <iostream>

using namespace std;

class Entity
{
public:
    virtual string GetName() {return "Entity"; }
};

class Player : public Entity {
public:
    std::string m_name;

    Player (const string& name) : m_name(name) {}

    string GetName() { return m_name; }
};

void PrintName(Entity& e) {
    cout << e.GetName() << endl;
}

int main()
{
    cout << sizeof(float) << endl;
    cout << sizeof(Entity) << endl;
    cout << sizeof(std::string) << endl;
    cout << sizeof(Player) << endl;

    Entity e;

    Player p("Player 1");

    PrintName(e);
    PrintName(p);
   
    return 0;
}
