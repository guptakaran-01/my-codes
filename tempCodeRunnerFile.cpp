#include <iostream>
#include <vector>
using namespace std;


class Isort{
   public:
   void sort()=0;
};

class Quicksort : public Isort{
    public:
    void sort()override{
        cout<<"Quick Sort Logic"<<endl;
    }
};

class mergesort : public Isort{
    public:
    void sort()override{
        cout<<"merge sort Logic"<<endl;
    }
};

class bubblesort : public Isort{
    public:
    void sort()override{
        cout<<"bubble sort Logic"<<endl;
    }
};

class client{
   private:
   Isort* stretegy;
   public:
   client(string type){
    this->stretegy=type;
   }
   
   void sortarray(vector<int> & arr){
    stretegy->sort(arr);
   }

};

int main()
{
    vector<int>arr={13,2,14,12,4};
    client obj=new client(Quicksort);
    obj->sortarray(arr);

    
    return 0;
}
