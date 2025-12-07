#include<iostream>
using namespace std ;


class Itext{
    public:
    virtual string write()=0;
    virtual ~Itext(){}
};

class text : public Itext{
    string txt;
    public:
    text (string txt){
        this->txt=txt;
    }
    
    string write()override{
        return txt;
    }
    
};

class Decorate : public Itext{
    
    protected:
    Itext* str;
    public:
    Decorate(Itext* s){
        str=s;
    }

    virtual ~Decorate(){
        delete str;
    }
    
};

class Italic : public Decorate{
   public:
   Italic (Itext* s):Decorate(s){}
   string write ()override{
    return str->write()+ " adding Italic font ";
   }
   
};

class Bold : public Decorate{
   public:
   Bold (Itext* s):Decorate(s){}
   string write ()override{
    return str->write()+ " adding bold font ";
   }
   
};



int main()
{
    Itext* obj =new Bold (new Italic ( new text ("I am the text")));
    cout<<obj->write()<<endl;

    delete obj;
    return 0;
}
