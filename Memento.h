#pragma once
#include <string>
#include<iostream>
#include <string>
//����¼ģʽ
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

	//����һ��״̬����Memento   ���õ�ǰ״̬��ֵȥ����һ��MementoȻ���䷵��
	Memento SaveStateMemento()
	{
		return Memento(state);
	}

	//ͨ������¼���󣬻ָ�״̬
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

	//��ȡ����index��Originator�ı���¼���󣨼�����¼״̬��
	Memento get(int index)
	{
		return mementoList[index];
	}
private:
	//��mementoList�л��кܶ౸��¼����
	std::vector<Memento> mementoList;
};

void testMemento() {
	Originator originator;
	Caretaker caretaker;
	originator.setState("״̬1��������Ϊ100");

	//���浱ǰ״̬
	caretaker.add(originator.SaveStateMemento());

	//�ܵ�debuff���������½�
	originator.setState("״̬2��������Ϊ80");
	//����״̬
	caretaker.add(originator.SaveStateMemento());

	cout << "��ǰ��״̬��" << originator.getState() << endl;
	cout << "debuffʱ��������ص�״̬1" << endl;
	originator.getStateFromMemento(caretaker.get(0));
	cout << "�ָ���״̬1���״̬��" << originator.getState();
	return ;
}