#pragma once
//����ģʽ
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
//�̲߳���ȫ����
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
//�̰߳�ȫ���ڴ氲ȫ������ʽ���� ������ָ�룬����
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
//ͨ���ֲ���̬���������Ա�֤���̰߳�ȫ , ����Ҫʹ�ù���ָ�룬�����ࣻ
//ע����ʹ�õ�ʱ����Ҫ�������������� Single& ���ܻ�ȡ����
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
����ʵ��һ��������ģ����࣬ʹ�÷�����������ʾ�⣬������Ҫ���Լ���Ϊģ�����T ���ݸ� Singleton ģ��; ͬʱ��Ҫ����������Ϊ��Ԫ���������ܵ��������˽�й��캯����

����ģ���ʵ��Ҫ���ǣ�

���캯����Ҫ�� protected������������ܼ̳У�

ʹ��������ݹ�ģ��ģʽCRTP(Curiously recurring template pattern)

get instance ������ 2.2.3 ��static local����һ��ԭ��

���������������������Բ���Ҫ virtual ����Ϊ������Ӧ����ֻ���� Derived ���ͣ���֤������ʱ�͹���ʱ������һ��
*/


//����ʽ

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