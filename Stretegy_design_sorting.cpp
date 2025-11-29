#include <iostream>
#include <vector>
using namespace std;

class Isort
{
public:
    virtual void sort(vector<int> &arr) = 0;
    virtual ~Isort() {}
};

class Quicksort : public Isort
{
public:
    void sort(vector<int> &arr) override
    {
        cout << "Quick Sort Logic" << endl;
    }
};

class mergesort : public Isort
{
public:
    void sort(vector<int> &arr) override
    {
        cout << "merge sort Logic" << endl;
    }
};

class bubblesort : public Isort
{
public:
    void sort(vector<int> &arr) override
    {
        cout << "bubble sort Logic" << endl;
    }
};

class client
{
private:
    Isort *stretegy;

public:
    client(string type)
    {
        if (type == "quick")
        {
            stretegy = new Quicksort();
        }
        else if (type == "merge")
        {
            stretegy = new mergesort();
        }
        else if (type == "bubble")
        {
            stretegy = new bubblesort();
        }
        else
        {
            stretegy = nullptr;
        }
    }

    void sortarray(vector<int> &arr)
    {
        stretegy->sort(arr);
    }

    ~client()
    {
        delete stretegy; // prevent memory leak
    }
};

int main()
{
    vector<int> arr = {13, 2, 14, 12, 4};
    client obj("quick");
    obj.sortarray(arr);

    return 0;
}
