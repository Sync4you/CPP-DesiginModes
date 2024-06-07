#pragma once
//原型模式
#ifndef _PROTOTYPE_H_ 
#define _PROTOTYPE_H_ 
class Prototype
{
public:
	virtual ~Prototype();
	virtual Prototype* Clone() const = 0;
protected:
	Prototype();
private:
};
class ConcretePrototype :public Prototype
{
public:
	ConcretePrototype();
	ConcretePrototype(const
		ConcretePrototype& cp);
	~ConcretePrototype();
	Prototype* Clone() const;
protected:
private:
};
#endif //~_PROTOTYPE_H_ 

Prototype::Prototype()
{
}
Prototype::~Prototype()
{
}
Prototype* Prototype::Clone() const
{
	return 0;
}
ConcretePrototype::ConcretePrototype()
{
}
ConcretePrototype::~ConcretePrototype()
{
}
ConcretePrototype::ConcretePrototype(const
	ConcretePrototype& cp)
{
	std::cout << "ConcretePrototype copy ..." << std::endl;
}
Prototype* ConcretePrototype::Clone() const
{
	return new ConcretePrototype(*this);
}

void testPrototype() {
	Prototype* p = new ConcretePrototype();
	Prototype* p1 = p->Clone();
	return ;
}