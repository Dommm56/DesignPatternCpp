#include <iostream>
using namespace std;
    
class IShape
{
    public:
        IShape() {}
        virtual ~IShape() {}
        virtual void draw() = 0;    // "= 0" part makes this method pure virtual, and
        // also makes this class abstract.  
};

class Rectangle : public IShape 
{
    void draw() {
        cout << "A rectangle shape" << endl;
    }
};

class Circle : public IShape
{
    void draw() {
        cout << "A circle shape" << endl;
    }
};

class Triangle : public IShape
{
    void draw() {
        cout << "A Triangle shape" << endl;
    }
};

class Square : public IShape
{
    void draw() {
        cout << "A square shape" << endl;
    }
};


