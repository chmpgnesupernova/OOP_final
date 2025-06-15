#include<iostream>
#include<functional>
#include<algorithm>

std::function<double(double, double)> Fn6(std::function<double(double,double)> ff1, std::function<double(double,double)> ff2 ){
    return [ff1, ff2](int x1, int x2){ return ff1(x1, x2) * ff2(x1, x2); };
}



struct Line {

	int Start, End;

	Line(int s = 0, int e = 0) : Start(s), End(e) {}

};

std::ostream& operator << (std::ostream& os, const Line& l) {
    os << '(' << l.Start << ", " << l.End << ')';
	return os;
}

void EraseInvalid (std::vector<Line>& lines) {
    lines.erase(std::remove_if( lines.begin(), lines.end(), []( Line& l ){ return l.Start > l.End; } ), lines.end());
}

int main(){

	std::cout << "\n### 6 ###" << std::endl;

	//6. 아래와 같이 두 함수(f1, f2와 같은 프로토타입(prototype))의 곱셈을 수행하는 함수를 반환하는 Fn6 함수를 정의하라.

	// 1) 함수, 변수 및 수식의 사용을 최소화

	auto f1 = [](double x1, double x2) { return (x1 + x2) / 2.; };

	auto f2 = [](double x1, double x2) { return x1 > x2 ? x1 : x2; };


	auto f = Fn6(f1, f2);	// ((x1 + x2)/2.)*(x1 > x2 ? x1 : x2)를 반환하는 함수

	std::cout << f(2, 5) << std::endl; // 출력: 17.5



	std::cout << "\n### 7 ###" << std::endl;

	// 7. 위에 정의된 struct Line으로 아래와 같이 동작하는 operaotr <<, EraseInvalid(Start<End가 아니면 제거)와  UnionLines(Start는 작은 값, End는 큰 값으로 누적)를 정의하라.

	// 1) EraseInvalid 함수는 최대한 간소화하여 작성(Lambda 함수가 포함된 한 개의 문장), 2) UnionLines 함수는 최대한 간소화하여 작성(크기가 0인 경우를 확인하는 코드와 Lambda 함수가 포함된 한 개의 리턴)

	// 3) EraseInvalid, UnionLines는 조건문, 반복문의 사용을 최소화하여 표준 함수를 사용할 것

	srand((unsigned)time(0));

	std::vector<Line> lines;


	std::cout << Line(3, 5) << std::endl; // 출력: (3, 5)


	for (int i = 0; i < 10; ++i) {

		lines.push_back(Line(rand() % 100, rand() % 100));

	}


	for (auto e : lines) std::cout << e << ", "; // 출력 예: (77, 26), (1, 4), (96, 1), (57, 80), (61, 33), (76, 51), (37, 57), (22, 25), (27, 61), (66, 57),

	std::cout << std::endl;

	EraseInvalid(lines);

	for (auto e : lines) std::cout << e << ", "; // 출력 예: (1, 4), (57, 80), (37, 57), (22, 25), (27, 61),

	std::cout << std::endl;
/*

	Line l = UnionLines(lines);

	std::cout << l << std::endl;	// 출력 예: (1, 80)
*/

}