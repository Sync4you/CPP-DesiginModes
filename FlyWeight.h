#pragma once
#include<utility>
#include<map>
//ÏíÔªÄ£Ê½
class Flyweight {
public:
	virtual void Operation(int n) = 0;
};

class FlyW1 : public Flyweight {
public:
	void Operation(int n) override {
		std::cout << "fly weight 1:" << n << std::endl;
	}
};

class FlyW2 : public Flyweight {
public:
	void Operation(int n) override {
		std::cout << "fly weight 2:" << n << std::endl;
	}
};

class FlyW3 : public Flyweight {
public:
	void Operation(int n) override {
		std::cout << "fly weight 3:" << n << std::endl;
	}
};

class FlyWFactory {
private:
	std::map<int, Flyweight*> flyw_map;
public:
	FlyWFactory()
	{
		flyw_map.insert(std::pair<int, Flyweight*>(1, new FlyW1()));
		flyw_map.insert(std::pair<int, Flyweight*>(2, new FlyW2()));
		flyw_map.insert(std::pair<int, Flyweight*>(3, new FlyW3()));

	}
	~FlyWFactory()
	{
		for (auto it = flyw_map.begin(); it != flyw_map.end(); ++it)
		{
			delete it->second;
		}
		flyw_map.clear();
	}
	Flyweight* getFlyWeight(int m) {
		return flyw_map[m];
	}

};

void testFlyWeight() {
	int state = 1;
	FlyWFactory* fac = new FlyWFactory();
	Flyweight* f1 = fac->getFlyWeight(1);
	f1->Operation(state++);

	Flyweight* f2 = fac->getFlyWeight(2);
	f2->Operation(state++);

	Flyweight* f3 = fac->getFlyWeight(3);
	f3->Operation(state++);

	delete fac;
}