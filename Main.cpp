#include "ShapeFactory.cpp"

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

	return 0; 
}