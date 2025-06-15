#include<iostream>
#include<functional>
#include<ctime>
#include<iterator>
#include<algorithm>
#include<utility>

std::function<double(double)> Function7 (std::function<double(double)> f1, std::function<double(double)> f2) {

    return [f1, f2] (double x) { return (f1(x) + f2(x)) / 2; }; 

}

std::function<double(double, double)> Fn6 
(std::function<double(double, double)> ff1, std::function<double(double, double)> ff2)
{
	return [ff1, ff2] (double x, double y) { return ff1(x, y) * ff2(x, y); };
}

std::function<std::vector<int>::iterator(std::vector<int>&)> Function8 (int init_x) {

	return [init_x] (std::vector<int>& v) {return (std::find(v.begin(), v.end(), init_x)); };
}


void Fn2 (std::vector<std::pair<char, int>>& v, int t) {
	v.erase(std::remove_if(v.begin(), v.end(), [t](auto& e){return e.second>=t;}), v.end());
}
/*
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

}
*/

int main(){

		//6. 아래와 같이 두 함수(f1, f2와 같은 프로토타입(prototype))의 곱셈을 수행하는 함수를 반환하는 Fn6 함수를 정의하라.

	// 1) 함수, 변수 및 수식의 사용을 최소화

	auto f1 = [](double x1, double x2) { return (x1 + x2) / 2.; };

	auto f2 = [](double x1, double x2) { return x1 > x2 ? x1 : x2; };


	auto f = Fn6(f1, f2);	// ((x1 + x2)/2.)*(x1 > x2 ? x1 : x2)를 반환하는 함수

	std::cout << f(2, 5) << std::endl; // 출력: 17.5



	// 7. 아래의 코드에서 주석과 간이 출력되도록, 

	// 매개변수가 한 개의 double이고 반환 타입이 double인 두 개의 함수를 파라메터로 가지며,
	// 두 함수 결과의 평균을 반환하는 함수를 생성하는 Function7 함수를 정의하라.
	// Function7은 생성된 함수를 반환하며, 
	// 반환은 lamba function으로 작성하고, 함수의 body는 return 문장으로만 작성한다. 

	std::cout << "\n### 7 ###" << std::endl;

	// 답안이 작성되면 아래의 /*****와 *****/를 제거하라.(제거하지 않으면 채점하지 않음)

	std::function<double(double)> F1 = [](double x) {

		return 2. * x * x + 3. * x + 2.;

	};

	std::function<double(double)> F2 = [](double x) {

		return 5. * x + 1.;

	};


	std::function<double(double)> F3 = Function7(F1, F2);

	double x = -0.86;

	std::cout << x << ", " << F3(x) << ", " << (F1(x) + F2(x)) / 2. << std::endl;

	// Print: -0.86, -1.2004, -1.2004

	x = 10.5;

	std::cout << x << ", " << F3(x) << ", " << (F1(x) + F2(x)) / 2. << std::endl;

	// Print: 10.5, 153.75, 153.75




	// 7. 아래의 코드에서 std::vector<int>에서 지정된 값의 요소를 찾는 Function8 함수를 정의하라.

	// Function8로 반환된 함수는 return type이 std::vector<int>::iterator이고 parameter type은 std::vector<int>& 이다.

	// Fn1은 argument로 전달된 v2에서 2의 값을 가지는 최초의 iterator를 반환하는 함수이고,

	// Fn2은 argument로 전달된 v2에서 5의 값을 가지는 최초의 iterator를 반환하는 함수이고,

	// Fn2은 argument로 전달된 v2에서 7의 값을 가지는 최초의 iterator를 반환하는 함수이다(찾는 값의 요소가 없으면 end iterator를 반환한다).

	// auto 타입을 사용할 수 없으며, container의 메소드와 std::find 함수만 사용한다.

	// 반환은 lamba function으로 작성하고, 함수의 body는 return 문장으로만 작성한다.

	// std::find를 사용하지 않고 비효율적으로 작성하면 0점 처리

	std::cout << "\n### 7 ###" << std::endl;

	// 답안이 작성되면 아래의 /*****와 *****/를 제거하라.(제거하지 않으면 채점하지 않음)



	std::vector<int> v2{ 1, 2, 4, 5, 9 };

	std::vector<int>::iterator it;


	std::function<std::vector<int>::iterator(std::vector<int>&)> Fn1 = Function8(2);

	it = Fn1(v2);

	if (it != v2.end()) std::cout << std::distance(v2.begin(), it) << ", " << v2[std::distance(v2.begin(), it)] << ", " << *it << std::endl;

	else std::cout << std::distance(v2.begin(), it) << std::endl;

	// Print: 1, 2, 2


	std::function<std::vector<int>::iterator(std::vector<int>&)> Fn2 = Function8(5);

	it = Fn2(v2);

	if (it != v2.end()) std::cout << std::distance(v2.begin(), it) << ", " << v2[std::distance(v2.begin(), it)] << ", " << *it << std::endl;

	else std::cout << std::distance(v2.begin(), it) << std::endl;

	// Print: 3, 5, 5


	std::function<std::vector<int>::iterator(std::vector<int>&)> Fn3 = Function8(7);

	it = Fn3(v2);

	if (it != v2.end()) std::cout << std::distance(v2.begin(), it) << ", " << v2[std::distance(v2.begin(), it)] << ", " << *it << std::endl;

	else std::cout << std::distance(v2.begin(), it) << " = " << v2.size() << std::endl;

	// Print: 5 = 5


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


}

