#include <iostream>
#include <vector>
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

class fan 
{
public:
    void on()
    {
        cout << "Fan is ON" << endl;
    }
    void off()
    {
        cout << "Fan is OFF" << endl;
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

class FanCommand : public Icommand{
    fan* f;
    public:
    FanCommand(fan* f){
        this->f=f;
    }

    void execute(){
        f->on();
    }
    void undo(){
        f->off();
    }
    ~FanCommand(){}
};

class Remote
{
    static const int button=4;
    Icommand *com[button];
    bool val[button];

public:
    Remote()
    {
        for(int i=0 ; i<button ; i++){
            com[i]=nullptr;
            val[i]=false;
        }
    }

    void setcommand(Icommand* cmd , int index){
        if(index < button && index>=0){
            if(com[index]!=nullptr){
                delete com[index];
            }
                com[index]=cmd;
                val[index]=false ;
            
        }
    }

    void perform(int index)
    {
           if(index <= button && index>=0 && com[index]!=nullptr){
            if(val[index]==false){
                com[index]->execute();
            }else{
                com[index]->undo();
            }
            val[index]=!val[index];
           }
           else{
            cout<<"No command is assigned to the index"<<endl;
           }
    }

    ~Remote()
    {
        for(int i=0 ; i<button ; i++){
            delete com[i];
        }
    }
};

int main()
{
    Light *l1 = new Light;
    fan* f1=new fan;

    Remote *rem = new Remote();
    rem->setcommand((new LightCommand(l1)),0);
    rem->setcommand((new FanCommand(f1)),1);
    
    rem->perform(0);
    rem->perform(1);

    rem->perform(0);
    rem->perform(1);

    rem->perform(2);



    delete rem;
    delete l1;

    return 0;
}
