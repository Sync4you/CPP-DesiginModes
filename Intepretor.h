#pragma once
#include<string>
class Context1 {
private:
	int m_num;
	int m_res;
public:
	Context1(int num) { m_num = num; }
	void setNum(int num) {
		m_num = num;
	}
	int getNum() { return m_num; }
	void setRes(int res)
	{
		m_res = res;
	}

	int getRes()
	{
		return m_res;
	}
};
class Expression
{
public:
    virtual void interpreter(Context1* context) = 0;
};

class PlusExpression : public Expression
{
public:
    virtual void interpreter(Context1* context)
    {
        int num = context->getNum();
        num++;
        context->setNum(num);
        context->setRes(num);
    }
};

class MinusExpression : public Expression
{
public:
    virtual void interpreter(Context1* context)
    {
        int num = context->getNum();
        num--;
        context->setNum(num);
        context->setRes(num);
    }
};

void testInterpretor() {
    Context1* pcxt = new Context1(10);
    Expression* e1 = new PlusExpression();

    e1->interpreter(pcxt);
    cout << "PlusExpression: " << pcxt->getRes() << endl;

    Expression* e2 = new MinusExpression();

    e2->interpreter(pcxt);
    cout << "MinusExpression: " << pcxt->getRes() << endl;

    delete e1;
    delete e2;

    delete pcxt;
    return;
}