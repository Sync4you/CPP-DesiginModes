#pragma once
//����ģʽ
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
        std::cout << "�û���Ʊ" << std::endl;
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
        std::cout << "Я�̹�Ʊ" << std::endl;
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