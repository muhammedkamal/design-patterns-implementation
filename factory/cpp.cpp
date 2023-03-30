#include <iostream>
#include <memory>
#include <string>

class Product {
public:
    virtual void use() = 0;
};

class ConcreteProductA : public Product {
public:
    void use() override {
        std::cout << "Using ConcreteProductA" << std::endl;
    }
};

class ConcreteProductB : public Product {
public:
    void use() override {
        std::cout << "Using ConcreteProductB" << std::endl;
    }
};

class Creator {
public:
    virtual std::unique_ptr<Product> createProduct() = 0;
};

class ConcreteCreatorA : public Creator {
public:
    std::unique_ptr<Product> createProduct() override {
        return std::make_unique<ConcreteProductA>();
    }
};

class ConcreteCreatorB : public Creator {
public:
    std::unique_ptr<Product> createProduct() override {
        return std::make_unique<ConcreteProductB>();
    }
};

int main() {
    std::unique_ptr<Creator> creator1 = std::make_unique<ConcreteCreatorA>();
    std::unique_ptr<Product> product1 = creator1->createProduct();
    product1->use();

    std::unique_ptr<Creator> creator2 = std::make_unique<ConcreteCreatorB>();
    std::unique_ptr<Product> product2 = creator2->createProduct();
    product2->use();

    return 0;
}
