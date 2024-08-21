// You have a set which contains all positive integers [1, 2, 3, 4, 5, ..].
// Implement the SmallestInfiniteSet class:
// SmallestInfiniteSet() Initializes the SmallestInfiniteSet object to contain all positive integers.
// int popSmallest() Removes and returns the smallest integer contained in the infinite set.
// void addBack(int num) Adds a positive integer num back into the infinite set, if it is not already in the infinite set.

#include <iostream>
#include <set>
using namespace std;

class SmallestInfiniteSet {
private:
    set<int> removed;
    int min;

public:
    SmallestInfiniteSet() : min(1) {}
    
    int popSmallest() {
        while (removed.find(min) != removed.end()) {
            min++;
        }
        removed.insert(min);
        return min++;
    }   
    
    void addBack(int num) {
        if(num < min) min = num;
        removed.erase(num);
    }
};

int main() {
    SmallestInfiniteSet sis;

    // Test popSmallest
    cout << "First popSmallest: " << sis.popSmallest() << endl; // Should print 1
    cout << "Second popSmallest: " << sis.popSmallest() << endl; // Should print 2
    cout << "Third popSmallest: " << sis.popSmallest() << endl; // Should print 3

    // Test addBack
    sis.addBack(2);
    cout << "After addBack(2), popSmallest: " << sis.popSmallest() << endl; // Should print 2

    cout << "Next popSmallest: " << sis.popSmallest() << endl; // Should print 4
    cout << "Next popSmallest: " << sis.popSmallest() << endl; // Should print 5

    return 0;
}
