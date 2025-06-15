#include<iostream>
#include<vector>
#include<list>
#include<algorithm>

template<typename T>
void Fn1(T iter1, T iter2) {
    for (; iter1 != iter2; ++iter1) {
        std::cout << *iter1 << ' ';
    }
    std::cout << '\n';
}

void Fn2 (std::vector<int>& v) {
    v.erase( std::remove_if( std::begin(v), std::end(v), [](int x){ return x < 0; } ), std::end(v) );
}

int main(){ // 다시보기!!!!! 아이디어 참신신

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


}