#include<iostream>
#include <vector>
#include <functional>

template <typename T, int N>
class Data {
std::vector<T> v;
public:
	Data() : v(N) {}
	int Size() { return N; }
	void Set( int index, T input ) { v[index] = input; }
	void Print() { 
		for (int i = 0; i < N; i++) { std::cout << v[i] << ' '; }
	}
};

std::function<int(int)> Fn1 (std::function<int(int)> f, int t) {
	return [f, t] (int x) { return ( f(x) >= t ) ? f(x) : -f(x); };
}


int main(){
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

		
}