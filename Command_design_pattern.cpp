#include <iostream>
using namespace std;

class Icommand
{
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual ~Icommand() {}
};

class Light
{
public:
    void on()
    {
        cout << "Light is ON" << endl;
    }
    void off()
    {
        cout << "Light is OFF" << endl;
    }
};

class LightCommand : public Icommand
{
    Light *l;

public:
    LightCommand(Light *l)
    {
        this->l = l;
    }
    void execute()
    {
        l->on();
    }
    void undo()
    {
        l->off();
    }

    ~LightCommand()
    {
    }
};

class Remote
{
    Icommand *com;
    bool val;

public:
    Remote(Icommand *command)
    {
        this->com = command;
        val = false;
    }
    void perform()
    {
        if (val == false)
        {
            com->execute();
        }
        else
        {
            com->undo();
        }
        val = !val;
    }

    ~Remote()
    {
        delete (com);
    }
};

int main()
{
    Light *l1 = new Light;
    Icommand *Lee = new LightCommand(l1);

    Remote *rem = new Remote(Lee);
    rem->perform();
    rem->perform();

    delete rem;
    delete l1;

    return 0;
}
