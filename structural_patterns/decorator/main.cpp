#include <iostream>
#include <string>

// The Decorator design pattern is a structural design pattern in C++ that allows you to dynamically   
// add behaviors or responsibilities to objects without altering their code.
// This pattern is used to extend the functionality of objects in a flexible and reusable way. 
// It is a useful alternative to sub-classing for adding behavior to classes.
// Decorator classes implement the same API as the components they are adding functionality to.
//
// Decorator pattern key components:
//
// Component Interface 
//      This is the common interface or abstract class that both the concrete components (base objects) 
//      and decorators must implement. It defines the methods that can be used to perform a basic operation.
//
// Concrete Component 
//      This is the base class that implements the Component interface. It represents the original 
//      object to which decorators can be added.
//
// Decorator
//      This is an abstract class or interface that also implements the Component interface. Decorators have a reference 
//      to a Component and can add their own behavior before or after delegating to the wrapped Component.
//
// Concrete Decorators
//      These are concrete classes derived from the Decorator class. They add specific functionality to the 
//      wrapped Component.

// App std out:
//
// Formatted Text: <u><i><b>Hello, Decorator Pattern!</b></i></u>
//
// NewDecorator::f(), calling DecoratorBaseClass::f()
// DecoratorClass::f(), calling  mBase->f()
// NewDecorator::f(), calling DecoratorBaseClass::f()
// DecoratorClass::f(), calling  mBase->f()
// NewDecorator::f(), calling DecoratorBaseClass::f()
// DecoratorClass::f(), calling  mBase->f()
// NewDecorator::f(), calling DecoratorBaseClass::f()
// DecoratorClass::f(), calling  mBase->f()
// BaseClass::f()


//! \brief: POC for the class structure used in this pattern. 
void ClassStructurePoc();

// Component Interface
class TextFormat 
{
public:
    virtual std::string format(const std::string& text) = 0;
    virtual ~TextFormat() {}
};

// Concrete Component
class PlainText : public TextFormat 
{
public:
    std::string format(const std::string& text) override 
    {
        return text;
    }
};

// Decorator
class TextDecorator : public TextFormat {
protected:
    TextFormat* wrappedText;

public:
    TextDecorator(TextFormat* text) : wrappedText(text) {}

    std::string format(const std::string& text) override 
    {
        return wrappedText->format(text);
    }
};

// Concrete Decorators
class BoldText : public TextDecorator 
{
public:
    BoldText(TextFormat* text) : TextDecorator(text) {}

    std::string format(const std::string& text) override 
    {
        return "<b>" + TextDecorator::format(text) + "</b>";
    }
};

class ItalicText : public TextDecorator {
public:
    ItalicText(TextFormat* text) : TextDecorator(text) {}

    std::string format(const std::string& text) override 
    {
        return "<i>" + TextDecorator::format(text) + "</i>";
    }
};

class UnderlineText : public TextDecorator 
{
public:
    UnderlineText(TextFormat* text) : TextDecorator(text) {}

    std::string format(const std::string& text) override 
    {
        return "<u>" + TextDecorator::format(text) + "</u>";
    }
};

int main() 
{
    TextFormat* plainText = new PlainText();
    TextFormat* boldText = new BoldText(plainText);
    TextFormat* italicText = new ItalicText(boldText);
    TextFormat* formattedText = new UnderlineText(italicText);

    std::string text = "Hello, Decorator Pattern!";
    std::string result = formattedText->format(text);

    std::cout << "Formatted Text: " << result << std::endl;

    delete formattedText;
    delete italicText;
    delete boldText;
    delete plainText;

    ClassStructurePoc();

    return 0;
}

///////////////////////////// Classes structure POC ////////////////////////////////////

class BaseClassInterface
{
public:
    virtual void f() = 0;
};

class BaseClass : public BaseClassInterface
{
public:
    virtual void f()
    {
        std::cout << "BaseClass::f()" << std::endl;
    }
};

class DecoratorBaseClass : public BaseClass
{
public:
    BaseClassInterface *mBase;

    DecoratorBaseClass(BaseClassInterface *base) : mBase(base)
    {

    }
    
    void f() override
    {
        std::cout << "DecoratorClass::f(), calling  mBase->f()" << std::endl;
        return mBase->f();
    }
};

class NewDecorator : public DecoratorBaseClass
{
public:

    NewDecorator(BaseClassInterface *base) : DecoratorBaseClass(base)
    {

    }
    
    void f() override
    {
        std::cout << "NewDecorator::f(), calling DecoratorBaseClass::f()" << std::endl;
        DecoratorBaseClass::f();
    }
};

void ClassStructurePoc()
{
    BaseClassInterface *ptr1 = new BaseClass();
    BaseClassInterface *decPtr1 = new NewDecorator(ptr1);
    BaseClassInterface *decPtr2 = new NewDecorator(decPtr1);
    BaseClassInterface *decPtr3 = new NewDecorator(decPtr2);
    BaseClassInterface *decPtr4 = new NewDecorator(decPtr3);

    decPtr4->f();
}
