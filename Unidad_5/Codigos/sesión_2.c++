class Base {
public:
    virtual void display() {
        std::cout << "Base display" << std::endl;
    }
};

class Derived : public Base {
public:
    void display() override {
        std::cout << "Derived display" << std::endl;
    }
};

Base b;
Derived d;
std::cout << "Vtable de Base: " << *(void**)&b << std::endl;
std::cout << "Vtable de Derived: " << *(void**)&d << std::endl;