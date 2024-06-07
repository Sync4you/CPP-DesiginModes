#include <memory>  

// 抽象处理者  
class Handler {
public:
	virtual ~Handler() {}
	virtual void HandleRequest(int request) = 0;
	virtual void SetNext(std::unique_ptr<Handler> next) = 0;

protected:
	std::unique_ptr<Handler> next;
};

// 具体处理者A  
class ConcreteHandlerA : public Handler {
public:
	void SetNext(std::unique_ptr<Handler> next) override {
		this->next = std::move(next);
	}

	void HandleRequest(int request) override {
		if (request >= 0 && request < 10) {
			std::cout << "ConcreteHandlerA handled request " << request << std::endl;
		}
		else if (next) {
			next->HandleRequest(request);
		}
		else {
			std::cout << "No handler could process request " << request << std::endl;
		}
	}
};

// 具体处理者B  
class ConcreteHandlerB : public Handler {
public:
	void SetNext(std::unique_ptr<Handler> next) override {
		this->next = std::move(next);
	}

	void HandleRequest(int request) override {
		if (request >= 10 && request < 20) {
			std::cout << "ConcreteHandlerB handled request " << request << std::endl;
		}
		else if (next) {
			next->HandleRequest(request);
		}
		else {
			std::cout << "No handler could process request " << request << std::endl;
		}
	}
};

void testChainOfDuty() {
	std::unique_ptr<Handler> handleA = std::make_unique<ConcreteHandlerA>();
	std::unique_ptr<Handler> handleB = std::make_unique<ConcreteHandlerB>();

	handleA->SetNext(std::move(handleB));
	handleA->HandleRequest(5);
	handleA->HandleRequest(10); 
	handleA->HandleRequest(50);

	return;
}