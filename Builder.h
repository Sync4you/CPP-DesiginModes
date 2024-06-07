#pragma once
#include <string>
#include<vector>
//建造者模式

class DeviceProduct
{
public:
	virtual ~DeviceProduct() {}
	virtual void setDisplay(std::string display) = 0;
	virtual void setHost(std::string host) = 0;
	virtual void setKeyBoard(std::string KeyBoard) = 0;
	virtual void setMouse(std::string mouse) = 0;
	virtual void show() = 0;
};

class Computer :public DeviceProduct {
public:
	~Computer() {}
	void setDisplay(std::string display)
	{
		m_vec.emplace_back(display);
	}
	void setHost(std::string host)
	{
		m_vec.emplace_back(host);
	}
	void setKeyBoard(std::string KeyBoard)
	{
		m_vec.emplace_back(KeyBoard);
	}
	void setMouse(std::string mouse)
	{
		m_vec.emplace_back(mouse);
	}
	void show()
	{
		std::cout << "----------组装电脑---------" << std::endl;
		for (auto& x : m_vec)
		{
			std::cout << x << std::endl;
		}
	}
private:
	std::vector<std::string> m_vec;
};

class AbstractBuilder {
public:
	AbstractBuilder():product(new Computer){}
	virtual ~AbstractBuilder(){}
	virtual void BuildDisplay(std::string display) = 0;
	virtual void BuildHost(std::string host) = 0;
	virtual void BuildKeyBoard(std::string KeyBoard) = 0;
	virtual void BuildMouse(std::string mouse) = 0;
	DeviceProduct* getProduct() {
		return product;
	}
protected:
	DeviceProduct* product;
};
class ComputerBuilder :public AbstractBuilder
{
public:
	~ComputerBuilder() {}
	void BuildDisplay(std::string display)
	{
		product->setDisplay(display);
	}
	void BuildHost(std::string host)
	{
		product->setHost(host);
	}
	void BuildKeyBoard(std::string KeyBoard)
	{
		product->setKeyBoard(KeyBoard);
	}
	void BuildMouse(std::string mouse)
	{
		product->setMouse(mouse);
	}
};

class Director {
public:
	Director(AbstractBuilder * builder):m_builder(builder){}
	~Director(){}
	DeviceProduct* createComputer(std::string display, std::string host,
		std::string keyboard, std::string mouse) {
		m_builder->BuildDisplay(display);
		m_builder->BuildHost(host);
		m_builder->BuildKeyBoard(keyboard);
		m_builder->BuildMouse(mouse);
		return m_builder->getProduct();
	}

private:
	AbstractBuilder* m_builder;
};

void testBuilder() {
	AbstractBuilder* computer_builder = new ComputerBuilder;
	Director* director = new Director(computer_builder);
	DeviceProduct* computer = director->createComputer("联想显示器", "外星人主机", "雷蛇键盘", "罗技鼠标");
	computer->show();

	delete computer_builder;
	delete director;
	delete computer;

	return;
}