#include<iostream>
using namespace std ;

class Singleton {
    private:
    static Singleton* instance;
    Singleton (){
        cout<<"This is the constructor called"<<endl;
    }

    public:
    static Singleton* getinstance(){
        return instance;
    }


};
 Singleton* Singleton::instance=new Singleton();

int main()
{
    Singleton *obj=Singleton::getinstance();
    Singleton *obj1=Singleton::getinstance();
    return 0;
}
