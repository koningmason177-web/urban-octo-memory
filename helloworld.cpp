#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Cell {
    int x;
    int y;
    string symbol;
};

int main() {

    ifstream file("input.txt");

    if (!file) {
        cout << "Error opening file." << endl;
        return 1;
    }

    vector<Cell> data;

    int x, y;
    string symbol;
    int maxX = 0, maxY = 0;

    // Read input
    while (file >> x >> symbol >> y) {
        data.push_back({x, y, symbol});

        if (x > maxX) maxX = x;
        if (y > maxY) maxY = y;
    }

    file.close();

    // Create grid
    vector<vector<string>> grid(maxY + 1, vector<string>(maxX + 1, " "));

    // Fill grid
    for (const auto& cell : data) {
        grid[cell.y][cell.x] = cell.symbol;
    }

    // Print grid
    for (int row = 0; row <= maxY; row++) {
        for (int col = 0; col <= maxX; col++) {
            cout << grid[row][col];
        }
        cout << endl;
    }

    return 0;
}