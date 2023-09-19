#include <iostream>
#include <string>
#include <unordered_map>

// Step 1: Define the Document Prototype Interface
class DocumentPrototype 
{
public:
    virtual DocumentPrototype* clone() const = 0;
    virtual void fillContent(const std::string& content) = 0;
    virtual void print() const = 0;
};

// Step 2: Create Concrete Document Prototypes
class Letter : public DocumentPrototype 
{
public:
    Letter() : header_("Letter Header"), footer_("Letter Footer"), content_("") 
    {

    }

    DocumentPrototype* clone() const override 
    {
        return new Letter(*this);
    }

    void fillContent(const std::string& content) override 
    {
        content_ = content;
    }

    void print() const override 
    {
        std::cout << header_ << std::endl;
        std::cout << content_ << std::endl;
        std::cout << footer_ << std::endl;
    }

private:
    std::string header_;
    std::string footer_;
    std::string content_;
};

class Report : public DocumentPrototype 
{
public:
    Report() : header_("Report Header"), footer_("Report Footer"), content_("") 
    {

    }

    DocumentPrototype* clone() const override 
    {
        return new Report(*this);
    }

    void fillContent(const std::string& content) override 
    {
        content_ = content;
    }

    void print() const override {
        std::cout << header_ << std::endl;
        std::cout << content_ << std::endl;
        std::cout << footer_ << std::endl;
    }

private:
    std::string header_;
    std::string footer_;
    std::string content_;
};

// Step 3: Create a Document Template Registry to manage prototypes
class DocumentTemplateRegistry 
{
public:
    DocumentTemplateRegistry()
    {
        // Initialize the registry with default document prototypes
        registry_["letter"] = new Letter();
        registry_["report"] = new Report();
    }

    DocumentPrototype* getPrototype(const std::string& type) const 
    {
        auto it = registry_.find(type);
        if (it != registry_.end()) {
            return it->second->clone();
        }
        return nullptr; // Prototype not found
    }

private:
    std::unordered_map<std::string, DocumentPrototype*> registry_;
};

int main() 
{
    // Step 4: Client Code
    DocumentTemplateRegistry templateRegistry;

    // Clone document templates and fill content
    DocumentPrototype* letter = templateRegistry.getPrototype("letter");
    DocumentPrototype* report = templateRegistry.getPrototype("report");

    if (letter && report) 
    {
        letter->fillContent("Dear John,\n\nThis is a letter.");
        report->fillContent("Monthly Sales Report:\n\nTotal Sales: $100,000");

        // Print documents
        std::cout << "Letter Template:" << std::endl;

        std::cout << "---" << std::endl;
        letter->print();
        std::cout << std::endl << "---" << std::endl;

        std::cout << "\nReport Template:" << std::endl;

        std::cout << "---" << std::endl;
        report->print();
        std::cout << std::endl << "---" << std::endl;
    }

    // Clean up
    delete letter;
    delete report;

    return 0;
}
