#include <functional>
#include <iostream>

using namespace std;
template <class T>
void doSomething(T lad) {
    int shit = 9;
    lad([&]() { cout << "i" << shit; });
}
struct Cmp {
    void operator()(function<void()> func) { func(); }
};
template <class T>
class Listenable {
    T value;
   public:
    T getValue() { return value; }
    Listenable(T _value) { value = _value; }
    void changeValue(function<void()> func) {
        func();
        // updateModel
    }
};
int main() {
    int dataasdf = 3;
    // Lambda 真的太他妈好用了！
    auto aFunc = [&dataasdf](function<void()> shit) {
        dataasdf++;
        shit();
    };
    function<void()> lds = bind(aFunc, []() {});
    function<void(function<void()>)> ano = aFunc;
    doSomething(aFunc);
    Listenable<int> theInt = 1;

    Cmp shity;
    doSomething(shity);
}
