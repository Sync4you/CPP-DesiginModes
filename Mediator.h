#pragma once
//中介者模式

class Mediator;
class Colleague {
public:
	Colleague(Mediator * pm):mediator(pm){}
	virtual void Send(char* mess) = 0;
protected:
	Mediator* mediator;
};

class Collegue1 :public Colleague {
public:
	Collegue1(Mediator* pm) :Colleague(pm) {};
	virtual void Send(char* mess);
	void notify(char* mess) {
		std::cout << "collegue 1 got message:" << mess << std::endl;
	}
};

class Collegue2 :public Colleague {
public:
	Collegue2(Mediator* pm) :Colleague(pm) {};
	virtual void Send(char* mess);
	void notify(char* mess) {
		std::cout << "collegue 1 got message:" << mess << std::endl;
	}
};

class Mediator {
public:
	virtual void Send(char* mess, Colleague* coll) = 0;
};
void Collegue1::Send(char* message) {
	this->mediator->Send(message, this);
}

void Collegue2::Send(char* message) {
	this->mediator->Send(message, this);
}
class ConcreteMediator : public Mediator
{
public:
    //重写声明方法 实现了两个对象得通信
    void Send(char* message, Colleague* pColleague)
    {
        Collegue1* pConcreteColleague1 = dynamic_cast<Collegue1*>(pColleague);

        if (pConcreteColleague1)
        {
            std::cout << "消息来自同事1" << std::endl;

            if (m_pColleague2)
            {
                m_pColleague2->notify(message);
            }
        }
        else
        {
            std::cout << "消息来自同事2" << std::endl;
            if (m_pColleague1)
            {
                m_pColleague1->notify(message);
            }
        }
    }

    //具体主管了解改组下的所有得同事.... 所以拥有同事1和同事2得所有属性
    void setColleague1(Colleague* pColleague)
    {
        m_pColleague1 = dynamic_cast<Collegue1*>(pColleague);
    }

    void setColleague2(Colleague* pColleague)
    {
        m_pColleague2 = dynamic_cast<Collegue2*>(pColleague);
    }

private:
    Collegue1* m_pColleague1; //同事1
    Collegue2* m_pColleague2; //同事2 
};

void testMediator(){
    Mediator* med = new ConcreteMediator();
    Collegue1* coll1 = new Collegue1(med);
    Collegue2* coll2 = new Collegue2(med);
    ConcreteMediator* con = dynamic_cast<ConcreteMediator*>(med);
    con->setColleague1(coll1);
    con->setColleague2(coll2);
    char mess[128] = "fuck you";
    coll1->Send(mess);
    char mess1[128] = "fuck you, too";
    coll2->Send(mess1);

    delete coll1;
    delete coll2;
    delete med;
    return;
}