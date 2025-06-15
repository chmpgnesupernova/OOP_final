#include <iostream>
#include <vector>
#include <string>

class A {
double x;
public:
    A (double xx = 0) : x(xx) {}
    double GetX() const { return x; }
};    

class B {
int x;
public:
    B (int xx = 0) : x(xx) {}
    int GetX() const { return x; } 
    void SetX(int input_x) { x = input_x; }
};


std::ostream& operator << (std::ostream& os, const B& b) {
    os << b.GetX();
    return os;
} 

class C {
std::string name;
std::vector<double> score = {0, 0};
double mean;
public:
    C (std::string input_name = "Anonymous", double input_score1 = 0, double input_score2 = 0) : name (input_name) 
    {   score[0] = input_score1;    score[1] = input_score2;    mean = (input_score1 + input_score2) / 2;   }
    friend std::ostream& operator << (std::ostream& os, const C& c);
};

std::ostream& operator << (std::ostream& os, const C& c) {
    os << c.name << ' ' << c.score[0] << ' '  << c.score[1] << ' '  << c.mean;
    return os;
}

class Base {
int x;
public:
    Base (int input_x = 0) : x(input_x) {}
    virtual int Get() const { return x; }    
};

class Derived : public Base {
int y;
public:
    Derived (int input_x = 0, int input_y = 0) : Base(input_x), y(input_y) {}
    int Get() const override { return Base::Get() + y; }
};

std::ostream& operator<< (std::ostream& os, const Base& base){
    os << base.Get();
    return os;
}



int main() {

    	std::cout << "### 1 ###" << std::endl;

    	// 1. 아래의 조건을 만족하는 A 클래스를 정의하라.

    	// 1개의 데이터 멤버(data member, private 접근 권한의 x)를 가진다.

    	// 1개의 생성자(constructor, x를 초기화), 1개의 GetX 멤버 함수(member function, x를 반환)를 가진다.

    	// 설명되지 않은 멤버는 추가할 수 없다.


       

    	const A a1, a2{ 10. }, a3{ 12.5 };

    	std::cout << a1.GetX() << ' ' << a2.GetX() << ' ' << a3.GetX() << '\n';

    	// 출력: 0 10 12.5

 

    	std::cout << "\n### 2 ###" << std::endl;

    	// 2. 아래의 조건을 만족하는 B 클래스와 비멤버(non-member) 연산자(<<)를 정의하라.

    	// 1개의 데이터 멤버(private 접근 권한의 x)를 가진다.

    	// 1개의 생성자(x를 초기화), GetX 멤버 함수(x를 반환)와 SetX 멤버 함수(x를 수정)를 가진다.

    	// 비멤버 연산자(<<)는 x를 출력하며 friend로 지정할 수 없다.

    	// 설명되지 않은 멤버는 추가할 수 없다.

    	const B b1, b2(10);

    	B b3;

    	b3.SetX(5);

    	std::cout << b1 << ' ' << b2 << ' ' << b3 << '\n';

    	// 출력: 0 10 5

 

    	std::cout << "\n### 3 ###" << std::endl;

    	// 3. 아래의 조건을 만족하는 C 클래스와 비멤버 연산자(<<)를 정의하라.

    	// 3개의 데이터 멤버(private 접근 권한의 name, score, mean)를 가진다.

    	// - name은 문자열, score는 실수를 저장하는 벡터(크기는 2)

    	// - mean은 두 score 요소의 평균

    	// 1개의 생성자(name, score, mean를 초기화)를 가진다.

    	// 비멤버 연산자(<<)는 아래의 예와 같이 멤버를 출력하며 friend를 사용한다.

    	// 설명되지 않은 멤버는 추가할 수 없다.

    	C c1, c2("Thomas", 84), c3("Sophia", 90.5, 75.4);

    	std::cout << c1 << ' '  << c2  << ' ' << c3 << '\n';

    	// 출력: Anonymous 0 0 0 Thomas 84 0 42 Sophia 90.5 75.4 82.95

 

    	std::cout << "\n### 4 ###" << std::endl;

    	// 4. 아래의 조건을 만족하는 Base/Derived 클래스와 비멤버 연산자(<<)를 정의하라.

    	// Base 클래스는 1개의 데이터 멤버(private 접근 권한의 x)를 가진다.

    	// Base 클래스는 1개의 생성자(x를 초기화)와 1개의 멤버 함수(Get)를 가진다.

    	// Base 클래스의 Get 함수는 x를 반환한다.

    	// Derived 클래스는 Base 클래스의 파생 클래스(derived class)이다.

    	// Derived 클래스는 1개의 데이터 멤버(private 접근 권한의 y)를 가진다.

    	// Derived 클래스는 1개의 생성자(x, y를 초기화)와 1개의 멤버 함수(Get)를 가진다.

    	// Derived 클래스의 Get 함수는 x와 y의 합을 반환

    	// 비멤버 연산자(<<)는 1개만 정의되며 아래의 예와 같이 출력된다.

    	// 설명되지 않은 멤버는 추가할 수 없다.

    	const std::vector<Base> v1 = { Base(), Base(2) };

    	const std::vector<Derived> v2 = { Derived(), Derived(3), Derived(2, 5) };

    	for (const Base& b : v1)

           	std::cout << b << ' '; // 출력: 0 2

    	std::cout << '\n';

    	for (const Base& b : v2)

           	std::cout << b << ' '; // 출력: 0 3 7

    	std::cout << '\n';

}