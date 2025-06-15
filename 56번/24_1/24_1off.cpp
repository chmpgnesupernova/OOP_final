#include<iostream>
#include<memory>

template<typename T = int>
class Data{
std::shared_ptr<T> p;

public:
    Data(T init_x = 0 ) { p = std::make_shared<T>(init_x); }
    T Get() const { return *p; }
    void Set(T input) { *p = input; }
};

int main(){

	// 5. 아래 코드에서 주석과 같이 출력되도록 Data 클래스 템플릿을 정의하라.
	// 데이터 멤버는 template type의 자료를 저장하는 shared pointer를 사용한다(private 접근 권한이며 추가적인 데이터 멤버 없음)
	// 생성자에 초기값이 없는 경우에는 0을 저장한다.
	// Get과 Set은 각각 포인터가 가리키는 대상의 값을 반환하고 수정한다.
	std::cout << "\n### 5 ###" << std::endl;
	// 답안이 작성되면 아래의 /*****와 *****/를 제거하라.(제거하지 않으면 채점하지 않음)

	Data<int> data1(2), data2;

	Data<double> data3(10.5), data4;


	std::cout << data1.Get() << ", " << data2.Get() << std::endl;	// Print: 2, 0

	std::cout << data3.Get() << ", " << data4.Get() << std::endl;	// Print: 10.5, 0

	data2 = data1;

	data2.Set(3);

	data3 = data4;

	data4.Set(1.2);

	std::cout << data1.Get() << ", " << data2.Get() << std::endl;	// Print: 3, 3

	std::cout << data3.Get() << ", " << data4.Get() << std::endl;	// Print: 1.2, 1.2


}