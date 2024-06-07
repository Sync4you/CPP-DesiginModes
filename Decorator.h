#pragma once

class Component {
public:
	virtual void operation() = 0;
};

class ConcreateComponent :public Component {
public:
	void operation() override {
		std::cout << "�������" << std::endl;
	}
};

class Decorator :public Component {
public:
    Decorator(Component* component) : m_component(component) {}
    void operation() override {
        if (m_component != nullptr) {
            m_component->operation();
        }
    }
protected:
    Component* m_component;
  
};


class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(Component* component) : Decorator(component) {}
    void operation() override {
        addBehaviorA();
        Decorator::operation();
    }
private:
    void addBehaviorA() {
        std::cout << "Ϊ������������Ϊ A" << std::endl;
    }
};

// ����װ����֮��
class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(Component* component) : Decorator(component) {}
    void operation() override {
        addBehaviorB();
        Decorator::operation();
    }
private:
    void addBehaviorB() {
        std::cout << "Ϊ������������Ϊ B" << std::endl;
    }
};

void testDecorator() {
    Component* com = new ConcreateComponent();
    Component* decoratorA = new ConcreteDecoratorA(com);
    Component* decoratorB = new ConcreteDecoratorB(decoratorA);
    decoratorB->operation();
    delete decoratorB;
    delete decoratorA;
    delete com;


}