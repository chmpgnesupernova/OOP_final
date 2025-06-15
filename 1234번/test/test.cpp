#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void Fn1 (std::vector<int>& v) {
    auto p = std::partition (v.begin(), v.end(), [](int x){ return x >= 10; });
    std::sort(v.begin(), p, std::less<int>());
    std::sort(p, v.end(), std::less<int>());
}

template<typename T>
std::function<void(T)> Fn2(std::vector<std::pair<char, int>>& v){
    return [&v](T target){ 
        v.erase(std::remove_if(v.begin(), v.end(), [target](auto p){ return (p.first == target)||(p.second == target); }), v.end()); 
    };
}

int main(){
    std::cout << "예상문제 1번" << std::endl;

    std::vector<int> v1 ={5, 11, 3, 2, 13, 1, 10, 17, 4, 19, 9};
    Fn1(v1);
    for (const auto& e : v1) std::cout << e << ", ";    //10, 11, 13, 17, 19, 1, 2, 3, 4, 5, 9, 

    std::cout << std::endl;


    std::cout << "예상문제 2번" << std::endl;

    std::vector<std::pair<char, int>> v2 = {{'A', 9}, {'B', 5}, {'C', 1}, {'D', 2}, {'E', 7}, {'F', 3}};

    auto f1 = Fn2<char>(v2);
    f1('A');
    for (const auto& e : v2) std::cout << '(' << e.first << ", " << e.second << ") ";
    //(B, 5) (C, 1) (D, 2) (E, 7) (F, 3)
    std::cout << std::endl;

    auto f2 = Fn2<int>(v2);
    f2(5);
    for (const auto& e : v2) std::cout << '(' << e.first << ", " << e.second << ") ";
    //(C, 1) (D, 2) (E, 7) (F, 3)
}