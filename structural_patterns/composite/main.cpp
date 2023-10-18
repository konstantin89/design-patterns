#include <iostream>
#include <vector>
#include <memory>

// Composite design pattern
//
// Design pattern that allows you define leaf object and composite objects.
// Composite object contain multiple leaf objects.
// In the example below, we implement GUI objects.  
// A leaf is basic object, like line or button.
// Composite object is complex object that contains multiple leafs - like a panel.
//
// Its important that both leafs and the composites have uniform API for this pattern to work.
// In our example the API is Draw().

class GuiComponent
{
public:
    virtual void Draw() = 0;
};

// Leaf component
class Button : public GuiComponent
{
public:
    void Draw() override
    {
        std::cout << "Button::Draw()" << std::endl;
    }
};

// Leaf component
class Line : public GuiComponent
{
public:
    void Draw() override
    {
        std::cout << "Line::Draw()" << std::endl;
    }
};

// Composite component
class Panel : public GuiComponent
{
public:
    void Draw() override
    {
        std::cout << "Line::Panel()" << std::endl;

        for(auto& component : mComponents)
        {
            component->Draw();
        }
    }

    void Add(std::shared_ptr<GuiComponent> leafComponent)
    {
        mComponents.push_back(leafComponent);
    }

private: 
    std::vector<std::shared_ptr<GuiComponent>> mComponents;

};

int main()
{
    auto button = std::make_shared<Button>();
    auto line = std::make_shared<Line>();

    line->Draw();
    button->Draw();

    auto panel = std::make_shared<Panel>();
    auto buttonForPanel = std::make_shared<Button>();
    auto lineForPanel = std::make_shared<Line>();

    panel->Add(buttonForPanel);
    panel->Add(lineForPanel);

    panel->Draw();

    return 0;
}