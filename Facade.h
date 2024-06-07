#pragma once
//外观模式
#include <iostream>
using namespace std;

//电视机类
class Television {
public:
    void on() {
        cout << "电视机打开" << endl;
    }
    void off() {
        cout << "电视机关闭" << endl;
    }
};

//灯类
class Light {
public:
    void on() {
        cout << "灯打开" << endl;
    }
    void off() {
        cout << "灯关闭" << endl;
    }
};

//音响
class Audio {
public:
    void on() {
        cout << "音响打开" << endl;
    }
    void off() {
        cout << "音响关闭" << endl;
    }
};

//麦克风
class Microphone {
public:
    void on() {
        cout << "麦克风打开" << endl;
    }
    void off() {
        cout << "麦克风关闭" << endl;
    }
};

//DVD
class DVDplayer {
public:
    void on() {
        cout << "DVD打开" << endl;
    }
    void off() {
        cout << "DVD关闭" << endl;
    }
};

//游戏机
class GameMachine {
public:
    void on() {
        cout << "游戏机打开" << endl;
    }
    void off() {
        cout << "游戏机关闭" << endl;
    }
};

//外观模式
class KTVMode {
public:
    KTVMode() {
        pTV = new Television;
        pLight = new Light;
        pAudio = new Audio;
        pMicrophone = new Microphone;
        pDvd = new DVDplayer;
    }

    void onKTV() {
        pTV->on();
        pLight->off();
        pAudio->on();
        pMicrophone->on();
        pDvd->on();
    }

    void offKTV() {
        pTV->off();
        pLight->off();
        pAudio->off();
        pMicrophone->off();
        pDvd->off();
    }

    ~KTVMode() {
        delete pTV;
        delete pLight;
        delete pAudio;
        delete pMicrophone;
        delete pDvd;
    }
private:
    Television* pTV;
    Light* pLight;
    Audio* pAudio;
    Microphone* pMicrophone;
    DVDplayer* pDvd;
};

void testFacade() {
    KTVMode* ktv = new KTVMode;
    //KTV包厢来人了
    ktv->onKTV();
}
