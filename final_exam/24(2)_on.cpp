#include <iostream>
#include <vector>

class A {
int x;
public:
	A ( int xx = 0 ) : x(xx) {}
	void Print() const {std::cout << x << ' ';}
};

class B {
int x;
public:
	B(int xx = 0) : x(xx) {}
	int GetX() const { return x; }
	B operator + (const B& b1) const {
		B add_b(x + b1.GetX());
		return add_b;
	}
};

std::ostream& operator << (std::ostream& os, const B& b){
	os << b.GetX();
	return os;
}


class C {
int n1, n2;
public:
	C(int nn1 = 0, int nn2 = 0) : n1(nn1), n2(nn2) {}
	operator int() {return n1 + n2;}
};

/*


    	std::cout << "\n### 4 ###" << std::endl;

    	// 4. 아래의 조건을 만족하는 Base와 Derived 클래스를 정의하라.

    	// Base 클래스는 1개의 데이터 멤버(private 접근 권한의 x)를 가진다.

    	// Base 클래스는 1개의 생성자(x를 초기화)와 한 개의 멤버 함수(Get)를 가진다.

    	// Base 클래스의 Get 함수는 x를 반환한다.

    	// Derived 클래스는 Base 클래스의 파생 클래스(derived class)이다.

    	// Derived 클래스는 1개의 데이터 멤버(private 접근 권한의 y)를 가진다.

    	// Derived 클래스는 1개의 생성자(x, y를 초기화)와 1개의 멤버 함수(Get)를 가진다.

    	// Derived 클래스의 Get 함수는 x와 y의 합을 반환한다.

    	// 설명되지 않은 멤버는 추가할 수 없다.

    	const std::vector<Base> v1 = { Base(), Base(2) };

    	const std::vector<Derived> v2 = { Derived(), Derived(3), Derived(2, 5) };

    	for (const Base& b : v1)

           	std::cout << b.Get() << ' '; // 출력: 0 2

    	std::cout << '\n';

 

    	for (const Base& d : v2)

           	std::cout << d.Get() << ' ';  // 출력: 0 3 7

    	std::cout << '\n';

*/
class Base{
int x;
public:
	Base(int xx = 0) : x(xx){}
	virtual int Get() const {return x;}

};

class Derived : public Base {
int y;
public:
	Derived (int xx = 0, int yy = 0) : Base(xx), y(yy) {}
	int Get() const override {return Base::Get() + y;}

};



int main() {

    	std::cout << "### 1 ###" << std::endl;

    	// 1. 아래의 조건을 만족하는 A 클래스를 정의하라.

    	// 1개의 데이터 멤버(data member, private 접근 권한의 x)를 가진다.

 // 1개의 생성자(constructor, x를 초기화), 1개의 Print 멤버 함수(member function, x 출력)를 가진다.

 // 설명되지 않은 멤버는 추가할 수 없다.

    	const A a1, a2{ 5 }, a3{ 10 };   	

    	a1.Print();

    	a2.Print();

    	a3.Print();

    	std::cout << '\n';

    	// 출력: 0 5 10

  	

    	std::cout << "\n### 2 ###" << std::endl;


    	// 2. 아래의 조건을 만족하는 B 클래스와 비멤버(non-member) 연산자(<<)를 정의하라.

    	// 1개의 데이터 멤버(private 접근 권한의 x)를 가진다.

    	// 1개의 생성자(x를 초기화), GetX 멤버 함수(x를 반환)와 + 멤버 연산자(x를 더한 객체를 반환)를 가진다.

    	// 비멤버 연산자(<<)는 x를 출력하며 friend로 지정할 수 없다.

    	// 설명되지 않은 멤버는 추가할 수 없다.


    	B b1;

    	const B b2(5), b3(10);

    	b1 = b2 + b3;

    	std::cout << b1 << ' ' << b2 << ' ' << b3 << '\n'; // 출력: 15 5 10




    	std::cout << "\n### 3 ###" << std::endl;

    	// 3. 아래의 조건을 만족하는 C 클래스를 정의하라.

    	// 2개의 데이터 멤버(private 접근 권한의 n1, n2)를 가진다.

    	// 1개의 생성자(n1과 n2를 초기화)와 1개의 형변환(int) 멤버 연산자(n1+n2을 반환)를 가진다.

    	// 아래 출력은 형변환 연산자가 정의되어 묵시적 변환(implicit conversion)으로 출력된다.

    	// 설명되지 않은 멤버는 추가할 수 없다.

    	C c1, c2(5), c3(1, 2);

    	std::cout << c1 << ' '  << c2  << ' ' << c3 << '\n';    	// 출력: 0 5 3

 

 

    	std::cout << "\n### 4 ###" << std::endl;

    	// 4. 아래의 조건을 만족하는 Base와 Derived 클래스를 정의하라.

    	// Base 클래스는 1개의 데이터 멤버(private 접근 권한의 x)를 가진다.

    	// Base 클래스는 1개의 생성자(x를 초기화)와 한 개의 멤버 함수(Get)를 가진다.

    	// Base 클래스의 Get 함수는 x를 반환한다.

    	// Derived 클래스는 Base 클래스의 파생 클래스(derived class)이다.

    	// Derived 클래스는 1개의 데이터 멤버(private 접근 권한의 y)를 가진다.

    	// Derived 클래스는 1개의 생성자(x, y를 초기화)와 1개의 멤버 함수(Get)를 가진다.

    	// Derived 클래스의 Get 함수는 x와 y의 합을 반환한다.

    	// 설명되지 않은 멤버는 추가할 수 없다.

    	const std::vector<Base> v1 = { Base(), Base(2) };

    	const std::vector<Derived> v2 = { Derived(), Derived(3), Derived(2, 5) };

    	for (const Base& b : v1)

           	std::cout << b.Get() << ' '; // 출력: 0 2

    	std::cout << '\n';

 

    	for (const Base& d : v2)

           	std::cout << d.Get() << ' ';  // 출력: 0 3 7

    	std::cout << '\n';

 

    	std::cout << "\n### 5 ###" << std::endl;

    	// 5. 아래의 조건을 만족하는 E 클래스 템플릿을 정의하라.

    	// E 클래스 템플릿은 3개의 데이터 멤버(private 접근 권한의 x, y, mean)를 가진다.

    	// E 클래스는 1개의 생성자와 1개의 Print 멤버 함수를 가진다.

    	// 생성자는 x, y를 파라메터로 초기화하고, x와 y의 평균을 mean에 저장한다.

    	// Print 함수는 x, y, mean을 순서대로 출력한다.

    	// x, y, mean이 char 타입인 경우에는 정수 값으로 출력되도록 explicit specialization 한다.

    	// auto 및 표준 함수는 사용할 수 없다.

    	// 설명되지 않은 멤버는 추가할 수 없다.

    	E<int> e1(10, 20), e2;

    	E<double> e3(20.2);

    	E<char> e4('A', 'C'); // 'A'는 ASCII 65, 'C'는 ASCII 67

 

    	e1.Print(); // 출력: 10 20 15

    	e2.Print(); // 출력: 0 0 0

    	e3.Print(); // 출력: 20.2 0 10.1

    	e4.Print(); // 출력: 65 67 66

    	std::cout << '\n';

  
/*
    	std::cout << "\n### 6 ###" << std::endl;

    	// 6. 아래의 조건을 만족하는 Fn1 함수 템플릿을 정의하라.

    	// Fn1 함수는 아래의 출력과 같이 container의 모든 요소를 출력한다.

    	// auto 및 표준 함수는 사용할 수 없다.

    	// 최대한 간략하게, 반복문과 iterator의 연산과 std::cout을 사용한다.

    	// 추가적으로 1개의 instance는 사용될 수 있다.

    	std::vector<int> x1{ 1, 2, 3, 4 };

    	std::vector<double> x2{ 1.5, 2.3, 3.2 };

    	std::list<int> x3{ 4, 7, 3, 2 };

    	Fn1(x1.begin(), x1.end()); // 출력: 1 2 3 4

    	Fn1(x2.begin(), x2.end()); // 출력: 1.5 2.3 3.2

    	Fn1(x3.begin(), x3.end()); // 출력: 4 7 3 2

    	std::cout << '\n';

 

    	std::cout << "\n### 7 ###" << std::endl;

    	// 7. 아래의 조건을 만족하는 Fn2 함수를 정의하라.

    	// Fn2 함수는 std::vector<int>에서 0보다 작은 요소를 제거한다.

    	// Fn2 함수는 std::vector<int>.erase, std::remove_if와 1개의 사용자 lambda 함수만 사용한다.

    	// 최대한 간략하게, 함수의 body는 1줄로 작성한다.

    	std::vector<int> z{ 1, 4, -2, 0, 8, -4, 7 };

    	

    	for (const auto& e : z)

           	std::cout << e << ' '; // 출력: 1 4 -2 0 8 -4 7

    	std::cout << '\n';

    	Fn2(z);

    	for (const auto& e : z)

           	std::cout << e << ' ';    	// 출력: 1 4 0 8 7

    	std::cout << '\n';
*/
}