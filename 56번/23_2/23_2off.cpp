int main(){
    	std::cout << "\n### 5 ###" << std::endl;

	//5. 아래와 같이 동작하는 X5 클래스 템플릿을 정의하라. (t1은 크기가 5인 int형 벡터(std::vector)로 모두 0으로 초기화, t2는 크기가 10인  char형 벡터(std::vector)로 모두 '*'으로 초기화)

	// 1) 생성자를 overloading하지 않음, 2) 데이터 멤버는 private 접근 권한, 3) 함수, 변수 및 수식의 사용을 최소화

	X5<int, 5> t1;

	X5<char, 10> t2('*');

	t1.Print(); // 출력: 0, 0, 0, 0, 0,

	t2.Print(); // 출력: *, *, *, *, *, *, *, *, *, *,

	try {

		t1.Set(10, 2);	// 2번 index를 10으로 수정

		t2.Set('?', 9);	// 9번 index를 '?'로 수정
		t2.Set('+', 10);// 10번 index의 요소는 없으므로, catch로 "index exception" 출력, at 메소드 사용불가

	}

	catch (std::exception& e) {

		std::cout << e.what() << std::endl; // "index exception" 출력

	}

//	t1.Print(); // 출력: 0, 0, 10, 0, 0,

//	t2.Print(); // 출력: *, *, *, *, *, *, *, *, *, ?,





}