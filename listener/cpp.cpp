#include <iostream>
#include <vector>

// المستقبل
class Listener {
public:
    virtual void onEvent(int data) = 0;
};

// المرسل
class Sender {
public:
    void addListener(Listener* listener) {
        listeners.push_back(listener);
    }
    
    void removeListener(Listener* listener) {
        listeners.erase(std::remove(listeners.begin(), listeners.end(), listener), listeners.end());
    }
    
    void sendData(int data) {
        for(auto listener : listeners) {
            listener->onEvent(data);
        }
    }

private:
    std::vector<Listener*> listeners;
};

// تطبيق على سبيل المثال
class MyListener : public Listener {
public:
    void onEvent(int data) override {
        std::cout << "Received event with data: " << data << std::endl;
    }
};

int main() {
    Sender sender;
    MyListener listener1;
    MyListener listener2;
    
    sender.addListener(&listener1);
    sender.addListener(&listener2);
    
    sender.sendData(10);
    
    sender.removeListener(&listener1);
    
    sender.sendData(20);
    
    return 0;
}
