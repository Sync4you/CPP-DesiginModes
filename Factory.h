#pragma once

class AbstractProduct {
public:
	virtual void makeProduct() = 0;

};

class AbstractFactory {
public:
	virtual AbstractProduct* createProduct() = 0;
};

class PlaneProduct : public AbstractProduct {
public:
	void makeProduct() override {
		std::cout << "plane product" << std::endl;
	}
	virtual ~PlaneProduct() {
		delete this;
	}
};

class PlaneFactory : public AbstractFactory {
public:
	AbstractProduct* createProduct() override {
		return new PlaneProduct;
	}
	virtual ~PlaneFactory() {
		delete this;
	}
};

class RocketProduct :public AbstractProduct
{
public:
	void makeProduct() override
	{
		std::cout << "rocket product" << std::endl;
	}
	virtual ~RocketProduct() {
		delete this;
	}
};

class RocketFactory :public AbstractFactory
{
public:
	AbstractProduct* createProduct()override
	{
		return new RocketProduct;
	}
	virtual ~RocketFactory() {
		delete this;
	}
};
void testFactory()
{
	AbstractFactory* factory = new PlaneFactory;
	AbstractProduct* pro = factory->createProduct();
	pro->makeProduct();
	factory = new RocketFactory;
	pro = factory->createProduct();
	pro->makeProduct();

	delete factory;
	delete pro;
	
	return ;
}