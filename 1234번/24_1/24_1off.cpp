#include <iostream>

class A {
double x;
public:
    A (double input_x = 0) : x(input_x) {}
    double GetX() const { return x; }
};

class B {
int x;
public:
	B (int init_x = 0) : x(init_x) {}
	void SetX(int input_x) { x = input_x; }
	int GetX() const { return x; }
};

std::ostream& operator << (std::ostream& os, const B& b) {
	os << b.GetX();
	return os;
}

class C {
int x;
public:
	C (int init_x = 0) : x(init_x) {}
	int GetX() const {return x;}

	C operator += (const C& c) {
		x = x + c.GetX();
		C result_c(x);
		return result_c;
	}
};

class Super{
int x;
public:
	Super(int init_x) : x(init_x) { std::cout << "Super" << ' '; }
	void Print() { std::cout << x; }
	virtual ~Super() { std::cout << "~Super"<< std::endl; }
};

class Sub : public Super {
int y;
public:
	Sub(int init_x, int init_y) : Super(init_x), y(init_y) { std::cout << "Sub" << std::endl; }
	void Print() { Super::Print();	 std::cout << ", " << y; }
	~Sub() {std::cout << "~Sub" << ' '; }
};



int main(){

	// 1. 아래 코드에서 주석과 같이 출력되도록 A 클래스를 정의하라.

	// 한 개의 private 접근 권한의 데이터 멤버를 가진다(추가적인 데이터 멤버 없음).

	// 생성자에 초기값이 없는 경우에는 0으로 초기화 한다.

	// 생성자와 GetX만 overloding 없이 한 개씩만 정의한다. 

	std::cout << "\n### 1 ###" << std::endl;

	// 답안이 작성되면 아래의 /*****와 *****/를 제거하라.(제거하지 않으면 채점하지 않음)

	

	A a1(1.5), a2;

	const A a3(3.2);

	std::cout << a1.GetX() << ", " << a2.GetX() << ", " << a3.GetX() << std::endl;

	// Print: 1.5, 0, 3.2



	// 2. 아래 코드에서 주석과 같이 출력되도록 B 클래스를 정의하라.

	// 한 개의 private 접근 권한의 데이터 멤버를 가진다(추가적인 데이터 멤버 없음).

	// 생성자에 초기값이 없는 경우에는 0으로 초기화 한다.

	// 생성자, SetX과 << 연산자를 overloding 없이 한 개씩 정의한다. 

	// << 연산자는 비멤버로 정의하며, 추가적인 멤버 함수를 1개 더 사용할 수 있다.

	std::cout << "\n### 2 ###" << std::endl;

	// 답안이 작성되면 아래의 /*****와 *****/를 제거하라.(제거하지 않으면 채점하지 않음)



	B b1(1), b2;

	const B b3(3);

	b1.SetX(10);

	std::cout << b1 << ", " << b2 << ", " << b3 << std::endl;

	// Print: 10, 0, 3



	// 3. 아래 코드에서 주석과 같이 출력되도록 C 클래스를 정의하라.

	// 한 개의 private 접근 권한의 데이터 멤버를 가진다(추가적인 데이터 멤버 없음).

	// 생성자에 초기값이 없는 경우에는 0으로 초기화 한다.

	// 생성자, GetX와 += 연산자만 overloding 없이 한 개씩만 정의한다. 

	// += 연산자는 멤버로 정의한다.

	std::cout << "\n### 3 ###" << std::endl;

	// 답안이 작성되면 아래의 /*****와 *****/를 제거하라.(제거하지 않으면 채점하지 않음)



	const C c1(10);

	C c2(5), c3;

	c3 = c2 += c1;

	std::cout << c2.GetX() << ", " << c3.GetX() << std::endl;

	// Print: 15, 15




	// 4. 아래 코드에서 주석과 같이 출력되도록 Super와 Sub 클래스를 정의하라.

	// 두 개의 클래스는 상속 관계이며, 각각 한 개의 private 접근 권한의 데이터 멤버를 가진다(추가적인 데이터 멤버 없음).

	// 생성자에 초기값이 없는 경우에는 0으로 초기화 한다.

	// "Super"와 "~Super"의 출력은 Super 클래스에서 출력하며, "Sub"와 "~Sub"의 출력은 Sub 클래스에서 출력한다.

	// 생성자, 소멸자, Print 함수만 overloading 없이 정의한다.

	std::cout << "\n### 4 ###" << std::endl;

	// 답안이 작성되면 아래의 /*****와 *****/를 제거하라.(제거하지 않으면 채점하지 않음)



	Super* p1 = new Sub(1, 2);		// Print: "Super" "Sub"

	Sub* p2 = dynamic_cast<Sub*>(p1);

	p1->Print();				// Print: 1

	std::cout << std::endl;

	if (p2) p2->Print();			// Print: 1, 2

	std::cout << std::endl;

	delete p1;				// Print: "~Sub" "~Super"




}
