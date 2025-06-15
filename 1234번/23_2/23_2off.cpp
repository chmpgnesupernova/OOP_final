#include <iostream>


class X1{
double x;
public:
    X1(double init_x = 0) : x(init_x) {}
    double GetX() const { return x; }
};

std::ostream& operator << (std::ostream& os, const X1& x1) {
    os << x1.GetX();
    return os;
}

class B2 {
public:
double x;
    B2(double init_x = 0 ) : x(init_x) {}
};

class D2 : public B2 {
public:
double x;
    D2(double init_x = 0, double init_y = 0) : B2(init_x), x(init_y) {}
};

/*// 3. 아래와 같이 동작하는 B31, B32, D3 클래스를 정의하라.
	// 1) 생성자를 overloading하지 않음, 2) 데이터 멤버는 private 접근 권한, 3) friend 선언 사용 금지, 4) 함수, 변수 및 수식의 사용을 최소화

    B31* pB31 = new D3(1, 0);

    B32* pB32 = new D3(3, 2);

    static_cast<B31>(*pB31).Print();	// 출력: 1

    static_cast<B32>(*pB32).Print();	// 출력: 2

	pB31->Print();	// 출력: 1, 0,

	pB32->Print();	// 출력: 3, 2, 

	std::cout << std::endl;

	delete pB31;		// 정상적으로 동작해야 함

	delete pB32;		// 정상적으로 동작해야 함*/

class B31 {
int x;
public:
    B31 (int init_x = 0) : x(init_x) {}
    virtual void Print(){   std::cout << x;   }
    virtual ~B31() {}
};

class B32 {
int x;
public:
    B32 (int init_x = 0) : x(init_x) {}
    virtual void Print(){   std::cout << x;    }
    virtual ~B32(){}
};

class D3 : public B31, public B32 {
public:
    D3 (int init_x1, int init_x2) : B31(init_x1), B32(init_x2) {}
    void Print() override { B31::Print();  std::cout << ", ";  B32::Print();  std::cout << ", ";     }
    ~D3(){}
};


int main(){

	std::cout << "\n### 1 ###" << std::endl;

	// 1. 아래와 같이 동작하는 X1 클래스를 정의하고, << 연산자(non member)를 overloading하라.

	// 1) 생성자를 overloading하지 않음, 2) 데이터 멤버는 private 접근 권한, 3) friend 선언 사용 금지, 4) 함수, 변수 및 수식의 사용을 최소화

X1 x1, x2(5.3);

const X1 x3(7.2);

std::cout << x1 << ", " << x2 << ", " << x3 << std::endl;		// 출력: 0, 5.3, 7.2, 


	std::cout << "\n### 2 ###" << std::endl;

	// 2. 아래와 같이 동작하는 B2, D2 클래스를 정의하라. 

	// 1) 생성자를 overloading하지 않음, 2) 데이터 멤버는 public 접근 권한, 3) 함수, 변수 및 수식의 사용을 최소화

D2 d1, d2(2.5, 3.2);

std::cout << d1.B2::x << ", " << d1.x << ", " << d2.B2::x << ", " << d2.x << std::endl; // 출력: 0, 0, 2.5, 3.2


	std::cout << "\n### 3 ###" << std::endl;

	// 3. 아래와 같이 동작하는 B31, B32, D3 클래스를 정의하라.

	// 1) 생성자를 overloading하지 않음, 2) 데이터 멤버는 private 접근 권한, 3) friend 선언 사용 금지, 4) 함수, 변수 및 수식의 사용을 최소화

    B31* pB31 = new D3(1, 0);

    B32* pB32 = new D3(3, 2);

    static_cast<B31>(*pB31).Print();	// 출력: 1

    static_cast<B32>(*pB32).Print();	// 출력: 2

	pB31->Print();	// 출력: 1, 0,

	pB32->Print();	// 출력: 3, 2, 

	std::cout << std::endl;

	delete pB31;		// 정상적으로 동작해야 함

	delete pB32;		// 정상적으로 동작해야 함





}