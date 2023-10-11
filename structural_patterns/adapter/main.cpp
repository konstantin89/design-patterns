#include <iostream>
#include <memory>
#include <vector>

// Adapter (aka Wrapper)
//
// The Adapter design pattern is a structural pattern used to make two incompatible
// interfaces work together. It allows objects with incompatible interfaces to collaborate.
//
// In the example below, TextShape class is adapter for ExternalLibraryTextDrawing.
// ExternalLibraryTextDrawing is class from external library that doesn't implements 
// the Draw API that is mandatory for all Shape classes.

class ExternalLibraryTextDrawing
{
public:
    void DrawText()
    {
        std::cout << "External library API is drawing text" << std::endl;
    }
};

class Shape
{
public:
    virtual void Draw() = 0;
};

class CircleShape : public Shape
{
public:
    void Draw() override
    {
        std::cout << "Drawing circle" << std::endl;
    }
};

class LineShape : public Shape
{
public:
    void Draw() override
    {
        std::cout << "Drawing line" << std::endl;
    }
};

class TextShape : public Shape
{
private:
    ExternalLibraryTextDrawing mTextDrawer;

public:
    void Draw() override
    {
        mTextDrawer.DrawText();
    }
};

int main()
{
    using ShapePtr = std::shared_ptr<Shape>;
    std::vector<ShapePtr> shapes;

    shapes.push_back(std::make_shared<CircleShape>());
    shapes.push_back(std::make_shared<LineShape>());
    shapes.push_back(std::make_shared<TextShape>());

    for(auto shape : shapes)
    {
        shape->Draw();
    }

    return 0;
}