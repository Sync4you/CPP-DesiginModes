#pragma once
//Adapter.h 
#ifndef _ADAPTER_H_ 
#define _ADAPTER_H_ 
class Target
{
public:
	Target();
	virtual ~Target();
	virtual void Request();
};
class Adaptee
{
public:
	Adaptee();
	~Adaptee();
	void SpecificRequest();
};
class Adapter :public Target
{
public:
	Adapter(Adaptee* ade);
	~Adapter();
	void Request();
private:
	Adaptee* _ade;
};
#endif //~_ADAPTER_H_ 


Target::Target()
{
}
Target::~Target()
{
}
void Target::Request()
{
	std::cout << "Target::Request" << std::endl;
}
Adaptee::Adaptee()
{
}
Adaptee::~Adaptee()
{
}
void Adaptee::SpecificRequest()
{
	std::cout << "Adaptee::SpecificRequest" << std::endl;
}
Adapter::Adapter(Adaptee* ade)
{
	this->_ade = ade;
}
Adapter::~Adapter()
{
}
void Adapter::Request()
{
	_ade->SpecificRequest();
}

void testAdaptor() {
	Adaptee* ade = new Adaptee;
	Target* adt = new Adapter(ade);
	adt->Request();
	return;
}