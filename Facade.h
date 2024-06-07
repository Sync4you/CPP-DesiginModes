#pragma once
//���ģʽ
#include <iostream>
using namespace std;

//���ӻ���
class Television {
public:
    void on() {
        cout << "���ӻ���" << endl;
    }
    void off() {
        cout << "���ӻ��ر�" << endl;
    }
};

//����
class Light {
public:
    void on() {
        cout << "�ƴ�" << endl;
    }
    void off() {
        cout << "�ƹر�" << endl;
    }
};

//����
class Audio {
public:
    void on() {
        cout << "�����" << endl;
    }
    void off() {
        cout << "����ر�" << endl;
    }
};

//��˷�
class Microphone {
public:
    void on() {
        cout << "��˷��" << endl;
    }
    void off() {
        cout << "��˷�ر�" << endl;
    }
};

//DVD
class DVDplayer {
public:
    void on() {
        cout << "DVD��" << endl;
    }
    void off() {
        cout << "DVD�ر�" << endl;
    }
};

//��Ϸ��
class GameMachine {
public:
    void on() {
        cout << "��Ϸ����" << endl;
    }
    void off() {
        cout << "��Ϸ���ر�" << endl;
    }
};

//���ģʽ
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
    //KTV����������
    ktv->onKTV();
}
