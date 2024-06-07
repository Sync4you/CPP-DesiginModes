#pragma once
//代理模式
class  AbstractSubject
{
public:
    virtual void BuyTicket() = 0;
};
class User :public AbstractSubject
{
public:
    void BuyTicket()
    {
        std::cout << "用户购票" << std::endl;
    }
};
class Ctrip :public AbstractSubject
{
public:
    Ctrip(AbstractSubject* pBase)
    {
        this->pBase = pBase;
    }
    void BuyTicket()
    {
        std::cout << "携程购票" << std::endl;
    }
private:
    AbstractSubject* pBase;
};

void testProxy() {
    AbstractSubject* base = new User;
    base->BuyTicket();
    Ctrip* proxy = new Ctrip(base);
    proxy->BuyTicket();
    delete base;
    delete proxy;
    return;
}