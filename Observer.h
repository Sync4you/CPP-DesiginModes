#pragma once
#include<list>
class AbsHero {
public:
	virtual void update() = 0;
};
class HeroA :public AbsHero {
public:
	HeroA() { std::cout << "HeroA." << std::endl; }
	virtual void update() override {
		std::cout << "HeroA update" << std::endl;
	}
};

class HeroB :public AbsHero {
public:
	HeroB() { std::cout << "HeroB." << std::endl; }
	virtual void update() override {
		std::cout << "HeroB update" << std::endl;
	}
};

class HeroC :public AbsHero {
public:
	HeroC() { std::cout << "HeroC." << std::endl; }
	virtual void update() override {
		std::cout << "HeroC update" << std::endl;
	}
};

class AbsBoss {
public:
	virtual void addHero(AbsHero* h) = 0;
	virtual void deleteHero(AbsHero* h) = 0;
	virtual void notify() = 0;
};

class BossA :public AbsBoss {
public:
	virtual void addHero(AbsHero * h) override {
		this->pHeroLst.push_back(h);
	}
	virtual void deleteHero(AbsHero* h) override {
		this->pHeroLst.remove(h);
	}
	virtual void notify() {
		for (auto it = this->pHeroLst.begin(); it != this->pHeroLst.end(); ++it)
		{
			(*it)->update();
		}
	}
private:
	std::list<AbsHero*> pHeroLst;
};

void testObserver(){
	AbsHero * hA = new HeroA;
	AbsHero* hB = new HeroB;
	AbsHero* hC = new HeroC;

	AbsBoss* bossA = new BossA;
	bossA->addHero(hA);
	bossA->addHero(hB);
	bossA->addHero(hC);
	std::cout << "HeroC died" << std::endl;
	bossA->deleteHero(hC);
	std::cout << "BossA died" << std::endl;
	bossA->notify();
	return;
}