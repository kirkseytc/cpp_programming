#include <iostream>

using namespace std;

class MyClass {
    public:
        MyClass();
        MyClass(int num);
        void setNum(int newNum);
        int getNum();
    private:
        int num;
};

MyClass::MyClass(){
    num = -1;
}

MyClass::MyClass(int num){
    this->num = num;
}

void MyClass::setNum(int newNum){
    num = newNum;
}

int MyClass::getNum(){
    return num;
}

int main(){

    MyClass test(1);

    cout << test.getNum() << endl;

}