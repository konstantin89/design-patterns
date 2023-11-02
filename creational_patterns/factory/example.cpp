#include <iostream>
#include <memory>

// The Factory Design Pattern is a creational design pattern that allows 
// subclasses to alter the type of objects that will be created. 

// Some factory design pattern variations:

// Simple Factory
// This is not a formal design pattern but a simple way to centralize 
// object creation. A single factory class or method is responsible for 
// creating objects based on input or a configuration. 
// The client code provides the necessary information, and the 
// factory returns the appropriate object.

// Factory Method (Virtual Constructor)
// The Factory Method pattern defines an interface for creating objects, 
// but the actual creation is deferred to concrete subclasses. 
// Each subclass provides its implementation of the factory method to create 
// specific objects. It allows for a family of related products to be created 
// without specifying the concrete classes.

// Abstract Factory
// The Abstract Factory pattern provides an interface for creating families 
// of related or dependent objects without specifying their concrete classes. 
// It's often used when you need to ensure that the created objects are compatible 
// and work together.

// Static Factory Method
// In some languages like C++, you can have static factory methods that are part 
// of the class itself and don't require instantiation. These methods create objects 
// based on the input parameters.

class Pizza
{
public:
    virtual void prepare() = 0;
    virtual void bake() = 0;
    virtual void cut() = 0;
    virtual void box() = 0;
};

class MargheritaPizza : public Pizza
{
    void prepare() override 
    {
        std::cout << "Preparing Margherita pizza" << std::endl;
    }

    void bake() override 
    {
        std::cout << "Baking Margherita pizza" << std::endl;
    }

    void cut() override 
    {
        std::cout << "Cutting Margherita pizza" << std::endl;
    }

    void box() override 
    {
        std::cout << "Boxing Margherita pizza" << std::endl;
    }
};

class VeggiePizza : public Pizza
{
    void prepare() override 
    {
        std::cout << "Preparing Veggie pizza" << std::endl;
    }

    void bake() override 
    {
        std::cout << "Baking Veggie pizza" << std::endl;
    }

    void cut() override 
    {
        std::cout << "Cutting Veggie pizza" << std::endl;
    }

    void box() override 
    {
        std::cout << "Boxing Veggie pizza" << std::endl;
    }
};

class PizzaFactory
{
public:
    enum class PizzaType
    {
        MargaritaPizza,
        VeggiePizza
    };

    std::shared_ptr<Pizza> CreatePizza(PizzaType type)
    {
        switch(type)
        {
            case PizzaType::MargaritaPizza:
                return std::make_shared<MargheritaPizza>();

            case PizzaType::VeggiePizza:
                return std::make_shared<VeggiePizza>();

            default:
                return NULL;
        }
    }
};

int main()
{
    // Factory design pattern decouples object creation from business logic.
    auto factory = std::make_unique<PizzaFactory>();

    std::shared_ptr<Pizza> pizza1 = factory->CreatePizza(PizzaFactory::PizzaType::MargaritaPizza);
    pizza1->prepare();
    pizza1->bake();
    pizza1->cut();
    pizza1->box();

    std::shared_ptr<Pizza> pizza2 = factory->CreatePizza(PizzaFactory::PizzaType::VeggiePizza);
    pizza2->prepare();
    pizza2->bake();
    pizza2->cut();
    pizza2->box();

    return 0;
}