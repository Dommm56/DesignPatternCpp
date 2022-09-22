#include <string>
#include <iostream>
using namespace std;

class IShape 
{
public:
	virtual ~IShape() {};
	virtual string getShape() = 0;
};

class Circle : public IShape
{
public: 
	~Circle() {};

	 string getShape()
	 {
		  return "Circle";
	 }
};

class Square : public IShape
{
public: 
	~Square() {};
	  
	string getShape()
	  {
		  return "Square";
	  }
};
/*
 * Creator
 * contains the implementation for all of the methods
 * to manipulate products except for the factory method
 */
class Creator
{
public:
	virtual ~Creator() {};
	virtual IShape* createCircle() = 0;
	virtual IShape* createSquare() = 0;
	virtual void removeShape(IShape *ishape) = 0;
};

//implements factory method that is responsible for creating
//one or more concrete products ie.it is class that has
//the knowledge of how to create the products
class ConcreteCreator : public Creator
{
public:
	~ConcreteCreator() {};

	IShape* createCircle()
	{
		return new Circle();
	}
	IShape* createSquare()
	{
		return new Square();
	}
	void removeShape(IShape *ishape)
	{
		delete ishape;
	}
};

int main()
{
	Creator* creator = new ConcreteCreator();
	IShape* s1 = creator->createCircle();
	cout << "Shape: " + s1->getShape() << endl;
	creator->removeShape(s1);

	IShape* s2 = creator->createSquare();
	cout << "Shape: " + s2->getShape() << endl;
	creator->removeShape(s2);

	delete creator;
	return 0;
}
