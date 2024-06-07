#pragma once
//²ßÂÔÄ£Ê½
class Strategy {
public:
	virtual void execute() = 0;
};

class StrategyA : public Strategy {
public:
	void execute() override {
		std::cout << "Strategy A" << std::endl;
	}
};
class StrategyB :public Strategy {
public:
	void execute() override {
		std::cout << "Strategy B" << std::endl;
	}
};


class Context {
public:
	Context(Strategy* strategy) : m_str(strategy) {
	}
	void setStrategy(Strategy* strategy) {
		m_str = strategy;
	}
	void executeStrategy() {
		m_str->execute();
	}

private:
	Strategy* m_str;
};
void testStrategy() {
	Context con(new StrategyA());
	con.executeStrategy();
	con.setStrategy(new StrategyB());
	con.executeStrategy();
	return ;

}