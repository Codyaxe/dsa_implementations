#include <map>
#include <unordered_map>
#include <string>
#include <vector>
#include <variant>
#include <memory>
#include <algorithm>
#include <iostream>

struct Ewan {
    int x;
};

int main(){


    std::map<int, std::string> mapping;
    std::multimap<int, std::string> rawr;
    std::vector<std::variant<int, bool, float, double, __int64, char, long int, Ewan>> lol;
    std::vector<int> vec {5,6,7,2,3,4,5,6,7};
    std::vector<int> vec2 {2,3,4};

    std::unique_ptr<Ewan> test = std::make_unique<Ewan>();
    std::unique_ptr<Ewan> mangananakaw = std::move(test);

    std::find(vec.begin(),vec.end(), 4);
    std::binary_search(vec.begin(),vec.end(), 4);
    std::cout << *std::search(vec.begin(), vec.end(), vec2.begin(),vec2.end());
    

    // mapping[1] = "B";

    // mapping.insert({0, "A"});


    return 0;
};