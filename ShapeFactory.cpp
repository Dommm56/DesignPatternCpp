#include <string>
#include "ShapeClasses.cpp"
using namespace std;
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

    

