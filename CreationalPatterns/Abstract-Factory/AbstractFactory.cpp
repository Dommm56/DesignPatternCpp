#include <string>
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


class ShapeFactory 
{
public:
    virtual IShape* drawRectangle() = 0;
    virtual IShape* drawCircle() = 0;
    virtual IShape* drawTriangle() = 0;
    virtual IShape* drawSquare() = 0;
};

class SimpleShapeFactory : public ShapeFactory {
public:
    IShape* drawRectangle() {
        return new Rectangle;
    }
    IShape* drawCircle() {
        return new Circle;
    }
    IShape* drawTriangle() {
        return new Triangle;
    }
    IShape* drawSquare() {
        return new Square;
    } 
};

int main()
{
    ShapeFactory* factory = new SimpleShapeFactory;
    IShape* shapes[4];

    shapes[0] = factory->drawRectangle();
    shapes[1] = factory->drawCircle();
    shapes[2] = factory->drawTriangle();
    shapes[3] = factory->drawSquare();

    for (int i = 0; i < 4; i++) {
        shapes[i]->draw();
    }

    delete factory;
    return 0;
}
