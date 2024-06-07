#pragma once
#include<memory>

class State {
public:
	virtual void handle() = 0;
	virtual ~State(){}
};
class StateA :public State {
public:
	void handle() override {
		std::cout << "handle in state A" << std::endl;
	}

};

class StateB :public State {
public:
	void handle() override {
		std::cout << "handle in state B" << std::endl;
	}
};

class ContextState {
private:
	std::unique_ptr<State> state;
public:
	ContextState():state(nullptr){}
	void setState(std::unique_ptr<State> newState) {
		state = std::move(newState);
	}
	void request() {
		if (state)
			state->handle();
	}
};
void testState() {
	ContextState *context = new ContextState();
	std::unique_ptr<State> stda = std::make_unique<StateA>();
	std::unique_ptr<State> stdb = std::make_unique<StateB>();

	context->setState(std::move(stda));
	context->request();

	context->setState(std::move(stdb));
	context->request();


	delete context;
	return;

}