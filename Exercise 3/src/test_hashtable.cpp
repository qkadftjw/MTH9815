#include "Hashtable.hpp"
#include "GeneralEquality.hpp"
#include "GeneralHasher.hpp"
#include <memory>

int main(){
    auto hasher = std::make_shared<GeneralHasher<string>>();
    auto int_equal = std::make_shared<GeneralEquality<string>>();
    Hashtable<std::string, int> hash_table(100, std::move(hasher), std::move(int_equal));

    hash_table.insert("Alice", 30);
    hash_table.insert("Bob", 25);
    hash_table.insert("Charlie", 35);

    int value;
    if (hash_table.find("Bob", value)) {
        std::cout << "Found key 'Bob' with value: " << value << std::endl;
    } else {
        std::cout << "Key 'Bob' not found" << std::endl;
    }

    if (hash_table.erase("Alice")) {
        std::cout << "Key 'Alice' deleted successfully" << std::endl;
    } else {
        std::cout << "Key 'Alice' not found" << std::endl;
    }

    if (hash_table.find("Alice", value)) {
        std::cout << "Found key 'Alice' with value: " << value << std::endl;
    } else {
        std::cout << "Key 'Alice' not found" << std::endl;
    }

    return 0;
}
