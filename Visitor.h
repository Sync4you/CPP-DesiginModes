#pragma once
#include<list>

class Man;
class Woman;

class Action {
public:
	virtual void getManResult(Man* man) = 0;
	virtual void getWomanResult(Woman* woman) = 0;
private:

};
class Success :public Action {
public:
	void getManResult(Man* man) override {
		std::cout << "Man success" << std::endl;
	}
	void getWomanResult(Woman* woman) override {
		std::cout << "Woman success" << std::endl;
	}

};

class Fail :public Action {
public:
	void getManResult(Man* man) override {
		std::cout << "Man failure" << std::endl;
	}
	void getWomanResult(Woman* woman) override {
		std::cout << "Woman failure" << std::endl;
	}
};
class Person {
public:
	virtual void accept(Action* action) = 0;
};

class Man :public Person {
public:
	void accept(Action* action) override {
		action->getManResult(this);
	}
};

class Woman :public Person {
public:
	void accept(Action* action) override {
		action->getWomanResult(this);
	}
};

class ObejectStructure{
public:
	void attach(Person* p) {
		persons.push_back(p);
	}
	void detach(Person* p) {
		persons.remove(p);
		delete p;
	}

	void display(Action* action) {
		for (auto v : persons) {
			v->accept(action);
		}
	}
private:
	std::list<Person *> persons;
};

void testVisitor() {
	ObejectStructure* obs = new ObejectStructure;
	obs->attach(new Man);
	obs->attach(new Woman);
	Success* suc = new Success;
	obs->display(suc);
	Fail* fail = new Fail;
	obs->display(fail);
	return;
}