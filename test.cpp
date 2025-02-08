#include <iostream>
#include <set>
#include <unordered_set>

int main() {
    std::set<int> s = {3, 1, 4, 1, 5};
    std::unordered_set<int> s2 = {3, 1, 4, 1, 5};
    s.insert(2);
    s2.insert(2);

    for (int x : s) {
        std::cout << x << " ";  // Output: 1 2 3 4 5 (sorted order)
    }
    std::cout << std::endl;
    for (int x : s2) {
        std::cout << x << " ";  // Output: 1 2 3 4 5 (sorted order)
    }
    return 0;
}
