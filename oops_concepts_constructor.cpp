#include <iostream>
using namespace std ;


class A {
   int num ;
   public:

   A (){
        cout<<"I am parent"<<endl;
    }
};

class B : public  A{
    public:
    B(){
        cout<<"I am child"<<endl;
    }
};

int main()
{
    B obj;
    return 0;
}
