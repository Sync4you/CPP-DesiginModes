#pragma once
class Product {
public:
	virtual void use() = 0;
};
class ProductA : public Product {
public:
	void use() override {
		std::cout << "product A" << std::endl;
	}
};

class ProductB : public Product {
public:
	void use() override {
		std::cout << "product B" << std::endl;
	}
};



class SimpleFactory {
public:
	static Product* createProduct(char type) {
		switch (type)
		{
		case 'A':
			return new ProductA();
		case 'B':
			return new ProductB();
		default:
			return nullptr;
		}
	}
};

void testSimpleFactory()
{
	Product* proA = SimpleFactory::createProduct('A');
	Product* proB = SimpleFactory::createProduct('B');
	proA->use();
	proB->use();
	delete proA;
	delete proB;
	return;
}