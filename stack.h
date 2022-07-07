#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
using namespace std;

///////////////////////// STACK //////////////////////
struct node {
    int val;
    node *next;
    bool status;
    node (int val) {
        this->val = val;
        this->next = nullptr;
        this->status = false;
    }
};

class stack { 
    private:
        node *top;
        int size;

    public:
        stack();
        bool const empty();
        void push(int val);
        void pop();
        int const peek();
        void display();
        void merge(int outsideVal);
        int getSize();
        
};

/////////////////////// QUEUE //////////////////////////////
struct vec {
    vector<vector<int>>myBoard;
    string move;
    vec *next;

    vec(vector<vector<int>>board, string num) {
        myBoard = board;
        next = nullptr;
        move = num;
    }
};

class queue {
    private:
        vec *head;
        vec *tail;
        int size;

    public:
        queue();
        vec *getTail() {return tail;};
        vec *getHead() {return head;};

        bool isEmpty();
        bool checkNum(vector<vector<int>>board);
        bool checkPowerOfTwo(vector<vector<int>>board);

        void Dequeue();
        void Enqueue(vector<vector<int>>board, string num);

        vector<vector<int>> goUp(vector<vector<int>>board);
        vector<vector<int>> goDown(vector<vector<int>>board);
        vector<vector<int>> goLeft(vector<vector<int>>board);
        vector<vector<int>> goRight(vector<vector<int>>board);
        // 
        string fastMove();
};