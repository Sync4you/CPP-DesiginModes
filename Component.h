#include<list>
#include<string>
#include<memory>
#include<algorithm>
//���ģʽ
class Component1
{
protected:
    std::string name;
public:
    Component1(std::string str) :name(str) {}
    virtual void display() = 0;
    virtual void add(Component1*) = 0;
    virtual void remove(Component1*) = 0;
    virtual ~Component1() {}
};

class Composite :public Component1
{
private:
    std::list<std::shared_ptr<Component1>>elements;
public:
    Composite(std::string str) :Component1(str) {}
    void add(Component1* element)
    {
        auto it = std::find_if(elements.begin(), elements.end(),
            [element](std::shared_ptr<Component1>ptr) {return element == ptr.get(); });
        if (it == elements.end())
        {
            elements.push_back(std::shared_ptr<Component1>(element));
        }
    }
    void remove(Component1* element)
    {
        auto it = std::find_if(elements.begin(), elements.end(),
            [element](std::shared_ptr<Component1>ptr) {return element == ptr.get(); });
        if (it == elements.end())
        {
            return;
        }
        elements.erase(it);
    }
    void display()
    {
        for (auto it = elements.cbegin(); it != elements.cend(); ++it)
        {
            (*it)->display();   //��̬����
        }
    }
};

class Leaf : public Component1
{
public:
    Leaf(std::string str) :Component1(str) {}
    void display()
    {
        std::cout << name << std::endl;
    }
    void add(Component1* element)
    {
        std::cout << "Leaf cannot add" << std::endl;
    }
    void remove(Component1* element)
    {
        std::cout << "Leaf cannot remove" << std::endl;
    }
};
void testComponent() {

    Component1* p = new Composite("����");
    p->add(new Leaf("�Ͼ���"));
    p->add(new Leaf("������"));
    Component1* p1 = new Composite("֣��");
    p1->add(new Leaf("֣��"));
    p1->add(new Leaf("������"));
    p->add(p1);
    p->display();
    return;
}