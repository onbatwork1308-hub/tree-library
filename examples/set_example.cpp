#include <set/Set.h>
#include <iostream>
#include <limits>

void printSet(const Set<int>& s) {
    auto elements = s.to_vector();
    for (const auto& elem : elements) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void takeInput(Set<int>& s) {
    int value;

    std::cout << "Enter values to insert into the set (enter ok to stop): ";

    while (true) {
        if (std::cin >> value) {
            s.insert(value);
        } else {
            break;
        }
    }

    // Clear error state
    std::cin.clear();

    // Discard remaining input
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
void printVector(const std::vector<int>& vec) {
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main() {
    Set<int> s1;
    takeInput(s1);

    Set<int> s2;
    takeInput(s2);

    printSet(s1);
    printSet(s2);

    Set<int> s3 = s1.set_union(s2);
    Set<int> s4 = s1.set_intersection(s2);

    std::cout << "Union: ";
    printSet(s3);

    std::cout << "Intersection: ";
    printSet(s4);

    std::cout << "Difference (s1 - s2): ";
    printSet(s1.set_difference(s2));

    std::cout << "Symmetric Difference: ";
    printSet(s1.symmetric_difference(s2));

    std::cout << std::boolalpha;  // print true/false instead of 1/0

    std::cout << "s1 contains 2: " << s1.contains(2) << std::endl;
    std::cout << "set equality (s1 == s2): " << (s1 == s2) << std::endl;

    s4 = {1,2,3,3,3,3,4};
    std::cout << "s4: ";
    printSet(s4);

    std::cout << "s4.size(): " << s4.size() << std::endl;
    std::cout << "s4.empty(): " << s4.empty() << std::endl;

    s1 = s4;
    std::cout << "s1 after assignment from s4: ";
    printSet(s1);
    std::cout << "s1 == s4: " << (s1 == s4) << std::endl;
    s1.erase(3);
    std::cout << "s1 after erasing 3: ";
    printSet(s1);

    s1.clear();
    std::cout << "s1 after clearing: ";
    printSet(s1);
    std::cout << "s1.empty(): " << s1.empty() << std::endl;

    return 0;
}