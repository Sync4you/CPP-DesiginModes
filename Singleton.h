#pragma once
//单例模式
#include<memory>
#include<mutex>

/*
class Singleton {
private:
	static Singleton* m_instance;

private:
	Singleton() { std::cout << "constructor" << std::endl; }
	Singleton(Singleton&) = delete;
	Singleton& operator = (const Singleton&) = delete;
public:
	~Singleton() { std::cout << "destructor" << std::endl; }
	static Singleton* getInstance() {
		if (m_instance == nullptr) {
			m_instance = new Singleton;
		}
		return m_instance;
	}
};

Singleton* Singleton::m_instance = nullptr;
//线程不安全懒汉
void testSingleton() {
	Singleton* ins1 = Singleton::getInstance();
	Singleton* ins2 = Singleton::getInstance();
	delete ins1;
	return;
}
*/


/*
class Singleton {
public:
	using Ptr = std::shared_ptr<Singleton>;
	~Singleton() {
		std::cout << "destructor" << std::endl;
	}
	Singleton(Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	static Ptr getInstance() {
		if (m_pInstance == nullptr) {
			std::lock_guard<std::mutex> lk(m_mutex);
			if (m_pInstance == nullptr) {
				m_pInstance = std::shared_ptr<Singleton>(new Singleton);
			}
		}
		return m_pInstance;
	}
private:
	Singleton() {
		std::cout << "constructor" << std::endl;
	}
private:
	static Ptr m_pInstance;
	static std::mutex m_mutex;
};
//线程安全、内存安全的懒汉式单例 （智能指针，锁）
Singleton::Ptr Singleton::m_pInstance = nullptr;
std::mutex Singleton::m_mutex;
void testSingleton() {
	Singleton::Ptr instance1 = Singleton::getInstance();
	Singleton::Ptr instance2 = Singleton::getInstance();
	return;
}
*/

/*
class Singleton {
public:
	~Singleton() {
		std::cout << "destructor" << std::endl;
	}
	Singleton(const Singleton&) = delete;
	Singleton& operator = (const Singleton&) = delete;
	static Singleton& getInstance() {
		static Singleton instance;
		return instance;
	}
private:
	Singleton() {
		std::cout << "constructor" << std::endl;
	}
};
//通过局部静态变量的特性保证了线程安全 , 不需要使用共享指针，代码简洁；
//注意在使用的时候需要声明单例的引用 Single& 才能获取对象。
void testSingleton() {
	Singleton& ins1 = Singleton::getInstance();
	Singleton& ins2 = Singleton::getInstance();
	return;
}
*/


/*
template<typename T>
class Singleton {
public:
	static T& getInstance()
	{
		static T instance;
		return instance;
	}
	virtual ~Singleton() {
		std::cout << "destructor" << std::endl;
	}
	Singleton(const Singleton&) = delete;
	Singleton& operator = (const Singleton&) = delete;
protected:
	Singleton() {
		std::cout << "constructor" << std::endl;
	}
};

class DerivedSingleton :public Singleton <DerivedSingleton>{
	friend class Singleton<DerivedSingleton>;
public:
	DerivedSingleton(const DerivedSingleton&) = delete;
	DerivedSingleton& operator=(const DerivedSingleton&) = delete;
private:
	DerivedSingleton() = default;
};

void testSingleton() {
	DerivedSingleton& ins1 = DerivedSingleton::getInstance();
	DerivedSingleton& ins2 = DerivedSingleton::getInstance();
	return;
}
*/
/*
以上实现一个单例的模板基类，使用方法如例子所示意，子类需要将自己作为模板参数T 传递给 Singleton 模板; 同时需要将基类声明为友元，这样才能调用子类的私有构造函数。

基类模板的实现要点是：

构造函数需要是 protected，这样子类才能继承；

使用了奇异递归模板模式CRTP(Curiously recurring template pattern)

get instance 方法和 2.2.3 的static local方法一个原理。

在这里基类的析构函数可以不需要 virtual ，因为子类在应用中只会用 Derived 类型，保证了析构时和构造时的类型一致
*/


//饿汉式

class Singleton {
public:
	static Singleton* Instance() {
		return ptr;
	}
	~Singleton() {
		std::cout << "des" << std::endl;
	}
private:
	static Singleton* ptr;
private:
	Singleton() { std::cout << "cons" << std::endl; }
	Singleton(const Singleton&) = delete;
	Singleton& operator = (const Singleton&) = delete;
};
Singleton* Singleton::ptr = new Singleton;


void testSingleton() {
	Singleton* ins1 = Singleton::Instance();
	Singleton* ins2 = Singleton::Instance();
	Singleton* ins3 = Singleton::Instance();
	delete ins3;
}