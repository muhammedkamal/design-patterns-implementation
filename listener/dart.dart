import 'dart:async';

// المستقبل
abstract class Listener {
  void onEvent(int data);
}

// المرسل
class Sender {
  final _listeners = <Listener>[];

  void addListener(Listener listener) {
    _listeners.add(listener);
  }

  void removeListener(Listener listener) {
    _listeners.remove(listener);
  }

  void sendData(int data) {
    for (final listener in _listeners) {
      listener.onEvent(data);
    }
  }
}

// تطبيق على سبيل المثال
class MyListener implements Listener {
  @override
  void onEvent(int data) {
    print('Received event with data: $data');
  }
}

void main() {
  final sender = Sender();
  final listener1 = MyListener();
  final listener2 = MyListener();

  sender.addListener(listener1);
  sender.addListener(listener2);

  sender.sendData(10);

  sender.removeListener(listener1);

  sender.sendData(20);
}
