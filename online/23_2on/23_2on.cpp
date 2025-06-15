#include<iostream>
#include<vector>
#include<list>
#include<algorithm>

//1번 문제
class A {
double x;
public:
    A (double init_x = 0) :x(init_x) {}
    double Get() const { return x; } 
};

//2번 문제
/*
	B b1, b2(1.2);
	const B b3(2.5);
	b1.Get() += 1.5;
    b2.Get() += 2.9;
	std::cout << b1.Get() << ", " << b2.Get() << ", " << b3.Get() << std::endl;		// 출력: 1.5, 4.1, 2.5*/

class B {
double x;
public:
    B (double init_x = 0) : x(init_x) {}
    double& Get() { return x; }
    double Get() const {return x;}
};

//3번 문제
class C {
double x;
public:
    C (double init_x = 0) : x(init_x) {}
    double GetX() const { return x; }
    C operator + (const C& c) const { return C(x + c.GetX()); }
};

std::ostream& operator << (std::ostream& os, const C& c) {
    os << c.GetX();
    return os;
}

//4번 문제
class E {
int x;
public:
    E (int init_x = 0) : x(init_x) {}
    int Get() const { return x; }
};

class F : public E {
int y;
public:
    F (int init_x = 0, int init_y = 1) : E(init_x), y(init_y) {}
    int Get() const { return y; }
};

//5번 문제
class G {
int x;
public:
    G (int init_x = 0) : x(init_x) {}
    virtual int Get() const { return x; }
};

class H : public G {
int y;
public:
    H (int init_x = 0, int init_y = 0) : G(init_x), y(init_y) {}
    int Get() const override { return G::Get() + y; }
};

//6번 문제
template <typename T>
class K {
std::vector<T> v;
public:
    K (int size = 0, T init = 0) : v(size, init) {}
    void Print() const { for(const auto& e : v) std::cout << e << ", "; std::cout << std::endl; }
};

//7번 문제
template<typename T>
void Print (T iter1, T iter2) { 
    for (; iter1 != iter2; ++iter1) 
        std::cout << *iter1 << ", ";
    std::cout << std::endl;
 }

template<typename T>
void Fn(T& v) {
    v.erase(std::remove_if(v.begin(), v.end(), [&v](int t){ return (t < 0)||(t > 100); }), v.end());
}

int main() {

	std::cout << "\n### 1 ###" << std::endl;

	// 1. 아래와 같이 동작하는 A 클래스를 정의하라. 
	// 1) 생성자를 overloading하지 않음, 2) 데이터 멤버는 private 접근 권한, 3) 함수, 변수 및 수식의 사용을 최소화

	A a1, a2(1.2);
	const A a3(2.5);
	std::cout << a1.Get() << ", " << a2.Get() << ", " << a3.Get() << std::endl;		// 출력: 0, 1.2, 2.5


	std::cout << "\n### 2 ###" << std::endl;

	// 2. 아래와 같이 동작하는 B 클래스를 정의하라. 
	// 1) 생성자를 overloading하지 않음, 2) 데이터 멤버는 private 접근 권한, 3) 함수, 변수 및 수식의 사용을 최소화

	B b1, b2(1.2);
	const B b3(2.5);
	b1.Get() += 1.5;
    b2.Get() += 2.9;
	std::cout << b1.Get() << ", " << b2.Get() << ", " << b3.Get() << std::endl;		// 출력: 1.5, 4.1, 2.5


	std::cout << "\n### 3 ###" << std::endl;

	// 3. 아래와 같이 동작하는 C 클래스를 정의하라. << 연산자는 비멤버, + 연산자는 멤버로 정의
	// 1) 생성자를 overloading하지 않음, 2) 데이터 멤버는 private 접근 권한, 3) 함수, 변수 및 수식의 사용을 최소화

	C c1;

	const C c2(1.2), c3(2.5);

	std::cout << c1 << ", " << c2 << ", " << c3 << std::endl;		// 출력: 0, 1.2, 2.5
	C c4 = c3 + c2;
	std::cout << c4 << std::endl; // 출력: 3.7



    std::cout << "\n### 4 ###" << std::endl;

	// 4. 아래와 같이 동작하는 E와 F 클래스를 정의하라. 

	// 1) 생성자를 overloading하지 않음, 2) 데이터 멤버는 private 접근 권한, 3) 함수, 변수 및 수식의 사용을 최소화, 4) friend 선언 없음

	F f1, f2(3);
	const F f3(4, 5);
	std::cout << f1.E::Get() << ", " << f1.Get() << std::endl; // 출력: 0, 1
	std::cout << f2.E::Get() << ", " << f2.Get() << std::endl; // 출력: 3, 1
	std::cout << f3.E::Get() << ", " << f3.Get() << std::endl; // 출력: 4, 5


	std::cout << "\n### 5 ###" << std::endl;

	// 5. 아래와 같이 동작하는 G와 H 클래스를 정의하라. (g1.Get()의 결과는 2, g2.Get()의 결과는 2+4)
	// 1) 생성자를 overloading하지 않음, 2) 데이터 멤버는 private 접근 권한, 3) 함수, 변수 및 수식의 사용을 최소화, 4) friend 선언 없음

	const H h1(2, 4);
	G g1 = h1; 
	const G& g2 = h1;
	std::cout << g1.Get() << ", " << g2.Get() << std::endl;	// 출력 : 2, 6


	std::cout << "\n### 6 ###" << std::endl;

	// 6. 아래와 같이 동작하는 K 클래스 템플릿을 정의하라. (k1은 크기가 5인 int형 벡터(std::vector)로 모두 0으로 초기화, k2는 크기가 10인  char형 벡터(std::vector)로 모두 '*'으로 초기화)
	// 1) 생성자를 overloading하지 않음, 2) 데이터 멤버는 private 접근 권한, 3) 함수, 변수 및 수식의 사용을 최소화

	K<int> k1(5);
	K<char> k2(10, '*');
	k1.Print(); // 출력: 0, 0, 0, 0, 0,
	k2.Print(); // 출력: *, *, *, *, *, *, *, *, *, *,

	std::cout << "\n### 7 ###" << std::endl;

	// 7. 아래와 같이 동작하는 Print와  Fn 함수 템플릿을 정의하라. (Print는 iterator 범위를 출력하고, Fn은 요소가 [0, 100] 범위가 아니면 제거한다.)
	// 1) 함수를 overloading하지 않음, 2) Fn 함수는 람다(lambda) 함수를 이용하여 최대한 간소화하여 작성

	srand((unsigned)time(0));
	std::vector<int> r;
	std::list<int> l;
	for (int i = 0; i < 10; ++i) {

		r.push_back(rand() % 300 - 100);

		l.push_back(rand() % 300 - 100);

	}

	Print(r.begin(), r.end()); // 출력 예: 5, 197, 77, 97, -55, -39, -23, 192, 64, 33,
	Fn(r);
	Print(r.begin(), r.end()); // 출력 예: 5, 77, 97, 64, 33,
	std::cout << std::endl;
	Print(l.begin(), l.end());	// 출력 예: 2, -38, -37, 87, -88, 126, 185, 122, 89, -88,
	Fn(l);
	Print(l.begin(), l.end());	// 출력 예: 2, 87, 89,

}


