#pragma once
//ге╫сдёй╫
class Device {
public:
	virtual bool isEnabled() = 0;
	virtual void enable() = 0;
	virtual void disable() = 0;
	virtual ~Device() {}
};

class TV : public Device {
    bool on = false;
public:
    bool isEnabled() override {
        return on;
    }

    void enable() override {
        on = true;
        std::cout << "TV is turned on.\n";
    }

    void disable() override {
        on = false;
        std::cout << "TV is turned off.\n";
    }
};

// Concrete Implementor 2
class Radio : public Device {
    bool on = false;
public:
    bool isEnabled() override {
        return on;
    }

    void enable() override {
        on = true;
        std::cout << "Radio is turned on.\n";
    }

    void disable() override {
        on = false;
        std::cout << "Radio is turned off.\n";
    }
};

class RemoteControl {
protected:
    Device* device;
public:
    RemoteControl(Device* d) : device(d) {}
    virtual void togglePower() {
        if (device->isEnabled()) {
            device->disable();
        }
        else {
            device->enable();
        }
    }
    virtual ~RemoteControl() {}
};

class AdvancedRemoteControl : public RemoteControl {
public:
    AdvancedRemoteControl(Device* d) : RemoteControl(d) {}
    void mute() {
        std::cout << "Device is muted.\n";
    }
};

void testBridge() {
    Device* tv = new TV();
    RemoteControl* remote = new RemoteControl(tv);
    remote->togglePower();

    Device* radio = new Radio();
    AdvancedRemoteControl* advancedRemote = new AdvancedRemoteControl(radio);
    advancedRemote->togglePower();
    advancedRemote->mute();

    delete tv;
    delete radio;
    delete remote;
    delete advancedRemote;
    return;
}