// There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. 
// However, you cannot enter a locked room without having its key.
// When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, 
// denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.
// Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, 
// return true if you can visit all the rooms, or false otherwise.

#include <iostream>
#include <vector>

void checkroom(std::vector<std::vector<int>>& rooms, std::vector<int>& visited, int i) {
    if (visited[i]) return;
    visited[i] = 1;
    for (int j = 0; j < rooms[i].size(); j++) {
        int key = rooms[i][j];
        if (visited[key] == 0) checkroom(rooms, visited, key);
    }
}

bool canVisitAllRooms(std::vector<std::vector<int>>& rooms) {
    int n = rooms.size();
    std::vector<int> visited(n, 0); // vec size n, visited[i]==0 means room i wasn't visited
    checkroom(rooms, visited, 0);
    for (int i = 0; i < n; i++) if (visited[i] == 0) return false;
    return true;
}

int main() {
    // Example rooms setup
    std::vector<std::vector<int>> rooms = {{1}, {2}, {3}, {}};

    if (canVisitAllRooms(rooms)) {
        std::cout << "All rooms can be visited." << std::endl;
    } else {
        std::cout << "Not all rooms can be visited." << std::endl;
    }

    return 0;
}
