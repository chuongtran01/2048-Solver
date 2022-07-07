#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

#include "stack.h"
#include "ArgumentManager.h"

using namespace std;

int main(int argc, char* argv[]) {
    ArgumentManager am(argc , argv);
    ifstream input(am.get("input"));
    ofstream output(am.get("output"));

    int size;
    int sum;

    input >> size;
    
    vector<vector<int>>board; 
    for (int i = 0; i < size; i++) {
        vector<int>myVector;
        for (int j = 0; j < size; j++) {
            int tempVal;
            input >> tempVal;
            myVector.push_back(tempVal);
        }
        board.push_back(myVector);
    }


    queue myQueue;
    myQueue.Enqueue(board, "");
    output << myQueue.fastMove();

    return 0;
}