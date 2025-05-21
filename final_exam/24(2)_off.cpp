#include<iostream>
#include <string>
#include <vector>

class A {
    double x;
public:
    A(double x = 0) : x(x){}
    double GetX() const {return x;}
};

class B{
double x;
public:
    B(double x = 0) : x(x){}
    double GetX() const {return x;}
    void SetX(double y) {x = y;}
};

std::ostream& operator << (std::ostream& os, B b){
    os << b.GetX();
    return os;
}

class C {
std::string name;
std::vector<double> score;
double mean;
public:
	C (std::string n = "Anonymous", double x1 = 0, double x2 = 0) : name (n) { 
		score.push_back(x1); score.push_back(x2); 
		mean = (x1 + x2)/2;
	}
	friend std::ostream& operator << (std::ostream& os, C& c);
};

std::ostream& operator << (std::ostream& os, C& c){
    os << c.name << ' ' << c.score[0] << ' ' << c.score[1] << ' ' << c.mean;
    return os;
}

class Base {
	int x;
public:
Base ( int xx = 0 ) : x(xx) {}
virtual int Get() const { return x; }
};

class Derived : public Base {
	int y;
public:
Derived (int xx = 0, int yy = 0) : Base(xx), y(yy) {}
int Get() const override { return Base::Get() + y; }
};

std::ostream& operator << (std::ostream& os, const Base& b) {
	os << b.Get();
    return os;
}

template <typename T, unsigned int N>
class Data {
private:
    std::vector<T> v;

public:
    Data() : v(N) {}

    void Set(unsigned int index, T value) {
		if (index<N) v[index] = value;
    }

    unsigned int Size() const {
        return N; 
	}

    void Print() const {
        for (const T& elem : v)
            std::cout << elem << ' ';
    }
};


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

 

    	std::cout << "\n### 5 ###" << std::endl;

    	// 5. 아래의 조건을 만족하는 Data 클래스 템플릿을 정의하라.

    	// Data 클래스 템플릿은 1개의 std::vector 타입의 데이터 멤버(private 접근 권한의 v)를 가진다.

    	// Data 클래스는 1개의 생성자와 3개의 멤버 함수(Print, Size, Set)를 가진다.

    	// Data 타입의 인스턴스 생성에서 2개의 인수(argument)가 필요하다.

    	// - 첫번쨰 argument는 v의 element type이고 두번째 argument는 v의 size이다.

    	// Print 함수는 v의 각 요소를 출력한다.

    	// Size 함수는 v의 size를 반환한다.

    	// Set 함수는 v의 index의 요소의 값을 수정한다.

    	// 설명되지 않은 멤버는 추가할 수 없다.

    	Data<int, 3> d1;

    	Data<double, 5> d2;

    	

    	for (int i = 0; i < d1.Size(); ++i)

           	d1.Set(i, i);

    	for (int i = 0; i < d2.Size(); ++i)

           	d2.Set(i, i/2.);

 

    	d1.Print();	// 출력: 0 1 2

    	std::cout << '\n';

    	d2.Print();	// 출력: 0 0.5 1 1.5 2

    	std::cout << '\n';

 

     	std::cout << "\n### 6 ###" << std::endl;

    	// 6. 아래의 조건을 만족하는 Fn1 함수를 정의하라.

    	// Fn1 함수는 2개의 parameter(f와 t)를 가진다.

    	// 반환되는 함수는 f의 결과가 t보다 크거나 같으면 f이며, t보다 작으면 -f인 함수이다.

    	// 최대한 간략하게, 함수의 body는 1줄의 return으로 작성한다.

    	auto f1 = [](double x) { return 2 * x; };

    	auto f2 = [](double x) { return 3 * x * x + 3 * x - 15; };

    	auto F1 = Fn1(f1, 0);

    	auto F2 = Fn1(f2, 0);

 

    	for (int x = -3; x <= 3; ++x)

           	std::cout << F1(x) << ':' << f1(x) << ' ';

    	// 출력: 6:-6 4:-4 2:-2 0:0 2:2 4:4 6:6

    	std::cout << '\n';

    	for (int x = -3; x <= 3; ++x)

           	std::cout << F2(x) << ':' << f2(x) << ' ';

    	// 출력: 3:3 9:-9 15:-15 15:-15 9:-9 3:3 21:21

    	std::cout << '\n';

 

    	std::cout << "\n### 7 ###" << std::endl;

    	// 7. 아래의 조건을 만족하는 Fn2 함수를 정의하라.

    	// Fn2 함수는 2개의 parameter(v와 t)를 가진다.

    	// v의 second가 t보다 크거나 같은 요소를 제거한다.

    	// Fn2 함수는 std::vector<...>.erase, std::remove_if와 1개의 lambda 함수만 사용한다.

    	// 최대한 간략하게, 함수의 body는 1줄로 작성한다.

    	std::vector<std::pair<char, int>> v(10);

    	srand((unsigned)time(nullptr));

    	for (auto& e : v) {

           	e.first = rand() % ('Z' - 'A' + 1) + 'A';

           	e.second = rand() % 10;

    	}

    	for (const auto& e : v)

           	std::cout << e.first << ':' << e.second << ' ';

    	// 가능한 출력 // L:5 O:3 D:4 V:3 U:0 I:0 Q:8 J:4 R:0 Z:5

    	std::cout << '\n';

    	Fn2(v, 4);

    	for (const auto& e : v)

           	std::cout << e.first << ':' << e.second << ' ';

    	// 위의 가능한 출력에 대한 출력	// O:3 V:3 U:0 I:0 R:0
*/
}