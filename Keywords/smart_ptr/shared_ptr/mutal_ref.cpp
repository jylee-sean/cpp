#include <iostream>
#include <memory>

class B;
class C;

class A {
public:
    A() {
        std::cout << "A 생성자 호출" << std::endl;
    }
    ~A() {
        std::cout << "A 소멸자 호출" << std::endl;
    }
    void set_b(std::shared_ptr<B> b) {
        b_ = b;
    }
    void set_c(std::shared_ptr<C> c) {
        c_ = c;
    }
private:
    std::shared_ptr<B> b_;
    std::shared_ptr<C> c_;
};

class B {
public:
    B() {
        std::cout << "B 생성자 호출" << std::endl;
    }
    ~B() {
        std::cout << "B 소멸자 호출" << std::endl;
    }
    void set_a(std::shared_ptr<A> a) {
        a_ = a;
    }
    void set_c(std::shared_ptr<C> c) {
        c_ = c;
    }
private:
    std::shared_ptr<A> a_;
    std::shared_ptr<C> c_;
};

class C {
public:
    C() {
        std::cout << "C 생성자 호출" << std::endl;
    }
    ~C() {
        std::cout << "C 소멸자 호출" << std::endl;
    }
    void set_a(std::shared_ptr<A> a) {
        a_ = a;
    }
    void set_b(std::shared_ptr<B> b) {
        b_ = b;
    }
private:
    std::shared_ptr<A> a_;
    std::shared_ptr<B> b_;
};

int main() {
    std::shared_ptr<A> a(new A);
    std::shared_ptr<B> b(new B);
    std::shared_ptr<C> c(new C);

    a->set_b(b);
    a->set_c(c);

    b->set_a(a);
    b->set_c(c);

    c->set_a(a);
    c->set_b(b);

    std::cout << "a.use_count(): " << a.use_count() << std::endl;
    std::cout << "b.use_count(): " << b.use_count() << std::endl;
    std::cout << "c.use_count(): " << c.use_count() << std::endl;

    return 0;
}