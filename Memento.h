#pragma once
#include <string>
#include<iostream>
#include <string>
//备忘录模式
using namespace std;
class Originator
{
public:
	std::string getState() const
	{
		return state;
	}

	void setState(const std::string& state)
	{
		this->state = state;
	}

	//保存一个状态对象Memento   即用当前状态的值去创建一个Memento然后将其返回
	Memento SaveStateMemento()
	{
		return Memento(state);
	}

	//通过备忘录对象，恢复状态
	void getStateFromMemento(Memento memento)
	{
		state = memento.getState();
	}
private:
	std::string state;
};



class Memento
{
public:
	explicit Memento(const std::string& state)
		: state(state)
	{
	}

	std::string getState() const
	{
		return state;
	}

private:
	std::string state;
};



#include <vector>

class Caretaker
{
public:
	void add(Memento memento)
	{
		mementoList.push_back(memento);
	}

	//获取到第index个Originator的备忘录对象（即备忘录状态）
	Memento get(int index)
	{
		return mementoList[index];
	}
private:
	//在mementoList中会有很多备忘录对象
	std::vector<Memento> mementoList;
};

void testMemento() {
	Originator originator;
	Caretaker caretaker;
	originator.setState("状态1，攻击力为100");

	//保存当前状态
	caretaker.add(originator.SaveStateMemento());

	//受到debuff，攻击力下降
	originator.setState("状态2，攻击力为80");
	//保存状态
	caretaker.add(originator.SaveStateMemento());

	cout << "当前的状态：" << originator.getState() << endl;
	cout << "debuff时间结束，回到状态1" << endl;
	originator.getStateFromMemento(caretaker.get(0));
	cout << "恢复到状态1后的状态：" << originator.getState();
	return ;
}