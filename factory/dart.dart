abstract class Product {
  void use();
}

class ConcreteProductA implements Product {
  @override
  void use() {
    print('Using ConcreteProductA');
  }
}

class ConcreteProductB implements Product {
  @override
  void use() {
    print('Using ConcreteProductB');
  }
}

abstract class Creator {
  Product createProduct();
}

class ConcreteCreatorA implements Creator {
  @override
  Product createProduct() {
    return ConcreteProductA();
  }
}

class ConcreteCreatorB implements Creator {
  @override
  Product createProduct() {
    return ConcreteProductB();
  }
}

void main() {
  Creator creator1 = ConcreteCreatorA();
  Product product1 = creator1.createProduct();
  product1.use();

  Creator creator2 = ConcreteCreatorB();
  Product product2 = creator2.createProduct();
  product2.use();
}
