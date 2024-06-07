#pragma once
//Ä£°åÄ£Ê½
class DrinkTemplate {
public:
	virtual void Boil() = 0;
	virtual void Brew() = 0;
	virtual void Pour() = 0;
	virtual void Shake() = 0;
	virtual void Add() = 0;
	void Make() {
		Boil();
		Brew();
		Pour();
		Shake();
		Add();
	}
};


class Coffee :public DrinkTemplate {
public:
	void Boil() override {
		std::cout << "boil coffee" << std::endl;
	}
	void Brew() override {
		std::cout << "brew coffee" << std::endl;
	}
	void Pour() override {
		std::cout << "pour coffee" << std::endl;
	}
	void Shake() override {
		std::cout << "shake coffee" << std::endl;
	}
	void Add() override {
		std::cout << "add coffee" << std::endl;
	}

};

class Tea :public DrinkTemplate {
public:
		void Boil() override {
			std::cout << "boil tea" << std::endl;
		}
		void Brew() override {
			std::cout << "brew tea" << std::endl;
		}
		void Pour() override {
				std::cout << "pour tea" << std::endl;
		}
		void Shake() override {
				std::cout << "shake tea" << std::endl;
		}
		void Add() override {
				std::cout << "add tea" << std::endl;
		}
};
void testTemplate()
{
	Tea* tea = new Tea;
	tea->Make();

	Coffee* coffee = new Coffee;
	coffee->Make();

	delete tea;
	delete coffee;
}