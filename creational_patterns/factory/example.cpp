#include <iostream>
#include <memory>

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