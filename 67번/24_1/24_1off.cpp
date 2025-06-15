#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<functional>

template<typename T>
void Function6(T& v, int t){
    v.erase( std::remove(v.begin(), v.end(), t), v.end() );
}

std::function<std::vector<int>::iterator(std::vector<int>&)> Function7( int t ) {
    return [t]( std::vector<int>& v ){ return std::find(v.begin(), v.end(), t); };
}

/*	// 7. 아래의 코드에서 std::vector<int>에서 지정된 값의 요소를 찾는 Function7 함수를 정의하라.
	// Function7로 반환된 함수는 return type이 std::vector<int>::iterator이고 parameter type은 std::vector<int>& 이다.
	// Fn1은 argument로 전달된 v2에서 2의 값을 가지는 최초의 iterator를 반환하는 함수이고,
	// Fn2은 argument로 전달된 v2에서 5의 값을 가지는 최초의 iterator를 반환하는 함수이고,
	// Fn3은 argument로 전달된 v2에서 7의 값을 가지는 최초의 iterator를 반환하는 함수이다(찾는 값의 요소가 없으면 end iterator를 반환한다).
	// auto 타입을 사용할 수 없으며, container의 메소드와 std::find 함수만 사용한다.
	// 반환은 lamba function으로 작성하고, 함수의 body는 return 문장으로만 작성한다.
	// std::find를 사용하지 않고 비효율적으로 작성하면 0점 처리

	std::vector<int> v2{ 1, 2, 4, 5, 9 };

	std::vector<int>::iterator it;

	std::function<std::vector<int>::iterator(std::vector<int>&)> Fn1 = Function7(2);

	it = Fn1(v2);

	if (it != v2.end()) std::cout << std::distance(v2.begin(), it) << ", " << v2[std::distance(v2.begin(), it)] << ", " << *it << std::endl;

	else std::cout << std::distance(v2.begin(), it) << std::endl;

	// Print: 1, 2, 2


	std::function<std::vector<int>::iterator(std::vector<int>&)> Fn2 = Function7(5);

	it = Fn2(v2);

	if (it != v2.end()) std::cout << std::distance(v2.begin(), it) << ", " << v2[std::distance(v2.begin(), it)] << ", " << *it << std::endl;

	else std::cout << std::distance(v2.begin(), it) << std::endl;

	// Print: 3, 5, 5


	std::function<std::vector<int>::iterator(std::vector<int>&)> Fn3 = Function7(7);

	it = Fn3(v2);

	if (it != v2.end()) std::cout << std::distance(v2.begin(), it) << ", " << v2[std::distance(v2.begin(), it)] << ", " << *it << std::endl;

	else std::cout << std::distance(v2.begin(), it) << " = " << v2.size() << std::endl;

	// Print: 5 = 5
*/

int main(){

	// 6. 아래 코드에서 첫 번째 매개변수인 sequence container에서 두 번째 매개변수와 동일한 요소를 제거하는 Function6 템플릿 함수를 정의하라.
	// 함수의 body는 한 개의 문장으로 작성하며, container의 메소드와 std::remove 함수만 사용한다.
	// std::remove를 사용하지 않고 비효율적으로 작성하면 0점 처리

	std::cout << "\n### 6 ###" << std::endl;

	// 답안이 작성되면 아래의 /*****와 *****/를 제거하라.(제거하지 않으면 채점하지 않음)



	std::vector<int> v1{ 1, 9, 4, 7, 4, 6 };

	Function6(v1, 4);

	for (const int& x : v1) std::cout << x << ", ";	// Print: 1, 9, 7, 6, 

	std::cout << std::endl;


	std::list<int> l1{ 8, 3, 4, 3, 3, 2 };

	Function6(l1, 3);

	for (const int& x : l1) std::cout << x << ", ";	// Print: 8, 4, 2,

	std::cout << std::endl;



	// 7. 아래의 코드에서 std::vector<int>에서 지정된 값의 요소를 찾는 Function7 함수를 정의하라.
	// Function7로 반환된 함수는 return type이 std::vector<int>::iterator이고 parameter type은 std::vector<int>& 이다.
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


	std::function<std::vector<int>::iterator(std::vector<int>&)> Fn1 = Function7(2);

	it = Fn1(v2);

	if (it != v2.end()) std::cout << std::distance(v2.begin(), it) << ", " << v2[std::distance(v2.begin(), it)] << ", " << *it << std::endl;

	else std::cout << std::distance(v2.begin(), it) << std::endl;

	// Print: 1, 2, 2


	std::function<std::vector<int>::iterator(std::vector<int>&)> Fn2 = Function7(5);

	it = Fn2(v2);

	if (it != v2.end()) std::cout << std::distance(v2.begin(), it) << ", " << v2[std::distance(v2.begin(), it)] << ", " << *it << std::endl;

	else std::cout << std::distance(v2.begin(), it) << std::endl;

	// Print: 3, 5, 5


	std::function<std::vector<int>::iterator(std::vector<int>&)> Fn3 = Function7(7);

	it = Fn3(v2);

	if (it != v2.end()) std::cout << std::distance(v2.begin(), it) << ", " << v2[std::distance(v2.begin(), it)] << ", " << *it << std::endl;

	else std::cout << std::distance(v2.begin(), it) << " = " << v2.size() << std::endl;

	// Print: 5 = 5




}