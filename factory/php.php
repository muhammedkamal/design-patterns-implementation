<?php

interface Product {
    public function use(): void;
}

class ConcreteProductA implements Product {
    public function use(): void {
        echo "Using ConcreteProductA\n";
    }
}

class ConcreteProductB implements Product {
    public function use(): void {
        echo "Using ConcreteProductB\n";
    }
}

interface Creator {
    public function createProduct(): Product;
}

class ConcreteCreatorA implements Creator {
    public function createProduct(): Product {
        return new ConcreteProductA();
    }
}

class ConcreteCreatorB implements Creator {
    public function createProduct(): Product {
        return new ConcreteProductB();
    }
}

$creator1 = new ConcreteCreatorA();
$product1 = $creator1->createProduct();
$product1->use();

$creator2 = new ConcreteCreatorB();
$product2 = $creator2->createProduct();
$product2->use();

?>