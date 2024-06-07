#pragma once
#include<string>

class Command {
public:
	virtual void excute() = 0;
};

class ConcreteCommand :public Command {
private:
	std::string	receiver;
public:
	ConcreteCommand(const std::string & receiver):receiver(receiver){}
	void excute() override {
		std::cout << "command executed by " << receiver << std::endl;
	}

};


class Invoker {
private:
	Command* comm;
public:
	void setCommand(Command* comm) { this->comm = comm; }
	void execute() {
		comm->excute();
	}
};

void testCommand() {
	ConcreteCommand comm("receiver A");
	comm.excute();

	Invoker inv;
	inv.setCommand(&comm);
	inv.execute();

	return;
}