#include <iostream>

// Visitor pattern (https://stackoverflow.com/questions/10116057/visitor-pattern-explanation)
//
// Visitor pattern is used to implement double dispatch. 
// In plain words it means that the code that gets executed 
// depends on runtime types of two objects.

// When you call a regular virtual function, it is a single dispatch: 
// the piece of code that gets executed depends on the runtime type 
// of a single object, namely, the one the virtual method of which 
// you are calling.

// With the visitor pattern, the method that is being called ultimately 
// depends on the type of two objects - the type of the object implementing 
// the equipmentVisitor, and the type of the object on which you 
// call accept (i.e. the equipmentVisited subclass).



// Step 1: Define the Visitor interface
class ShapeVisitor 
{
public:
    virtual void visitCircle(class Circle* circle) = 0;
    virtual void visitSquare(class Square* square) = 0;
};

// Step 2: Define concrete element classes
class Shape 
{
public:
    virtual void accept(ShapeVisitor* visitor) = 0;
};

class Circle : public Shape 
{
public:
    double radius;

    Circle(double r) : radius(r) {}

    void accept(ShapeVisitor* visitor) override 
    {
        visitor->visitCircle(this);
    }
};

class Square : public Shape 
{
public:
    double side;

    Square(double s) : side(s) {}

    void accept(ShapeVisitor* visitor) override 
    {
        visitor->visitSquare(this);
    }
};

// Step 3: Implement concrete visitors
class AreaVisitor : public ShapeVisitor 
{
public:
    void visitCircle(Circle* circle) override 
    {
        double area = 3.14159265359 * circle->radius * circle->radius;
        std::cout << "Area of Circle: " << area << std::endl;
    }

    void visitSquare(Square* square) override 
    {
        double area = square->side * square->side;
        std::cout << "Area of Square: " << area << std::endl;
    }
};

// Here we are adding another API for the objects.
// We are adding new API to the shapes called "PrintName" without touching
// the existing shape classes.
class PrintNameVisitor : public ShapeVisitor 
{
public:
    void visitCircle(Circle* circle) override 
    {
        std::cout << "Shape name: Circle " << std::endl;
    }

    void visitSquare(Square* square) override 
    {
        std::cout << "Shape name: Square" << std::endl;
    }
};


int main() 
{
    Circle circle(5.0);
    Square square(4.0);

    AreaVisitor areaVisitor;

    circle.accept(&areaVisitor);
    square.accept(&areaVisitor);

    PrintNameVisitor printNameVisitor;

    circle.accept(&printNameVisitor);
    square.accept(&printNameVisitor);


    return 0;
}