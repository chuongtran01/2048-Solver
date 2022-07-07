#include "stack.h"

//////////////////////////// STACK ///////////////////
stack::stack() {
    top = nullptr;
    size = 0;
}

bool const stack::empty() {
    if (top == nullptr) {
        return true;
    }
    return false;
}

void stack::push(int val) {
    node *temp = new node(val);
    if (empty()) {
        top = temp;
        size++;
        return;
    }
    temp->next = top;
    top = temp;
    size++;
}

void stack::pop() {
    if (empty()) {
        return;
    }
    node *temp = top;
    top = top->next;
    delete temp;
    size--;
}

int const stack::peek() {
    if (!empty()) {
        return top->val;
    }
    return 0;
}

void stack::merge(int outsideVal) {
    if (!top->status) {
        top->val = 2 * outsideVal;
        top->status = true;
    }
    else{
        push(outsideVal);
    }
}

int stack::getSize() {
    return size;
}

void stack::display() {
    node *cu = top;
    while (cu != nullptr) {
        cout << cu->val << " ";
        cu = cu->next;
    }
}



//////////////////////// QUEUE ///////////////////////////////
queue::queue() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

bool queue::isEmpty() {
    if (head == nullptr && tail == nullptr) {
        return true;
    }
    return false;
}

bool queue::checkNum(vector<vector<int>>board) {
    int count = 0;
    size = board.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == 0 || board[i][j] == 2048) {
                count++;
            }
        }
    }
    if (count == (size*size - 1)) {
        return true;
    }
    return false;
}

bool queue::checkPowerOfTwo(vector<vector<int>>board) {
    int sum = 0;
    size = board.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] != 2048 && board[i][j] != 0) {
                sum += board[i][j];
            }
        }
    }
    if (sum == 2048)
    {
        return false;
    }
    while (sum > 2048)
    {
        sum = sum -2048;
    }
    if(ceil(log2(sum)) == floor(log2(sum))) {
        
        return true;
    }
    return false;
}

void queue::Dequeue() {
    if (isEmpty()) {
        return;
    }
    vec *temp = head;
    head = head->next;
    delete temp;
}

void queue::Enqueue(vector<vector<int>>board, string num) {
    vec *temp = new vec(board, num);
    if (isEmpty()) {
        head = tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}

vector<vector<int>> queue::goUp(vector<vector<int>>board) {
    int size = board.size();
    for (int j = 0; j < size; j++) {
        stack store;
        for (int i = 0; i < size; i++) {
            if (board[i][j] > 0 && board[i][j] < 2048) {
                if (store.peek() == board[i][j]) {
                    store.merge(board[i][j]);
                    if (i == size - 1) {
                        int num = store.getSize();
                        for (int k = 0; k < size - num; k++) {
                            store.push(0);
                        }
                    }
                }
                else {
                    store.push(board[i][j]);
                    if (i == size - 1) {
                        int num = store.getSize();
                        for (int k = 0; k < size - num; k++) {
                            store.push(0);
                        }
                    }
                }
            }
            else if (board[i][j] == 2048) {
                int num = store.getSize();
                for (int k = 0; k < i - num; k++) {
                    store.push(0);
                }
                store.push(2048);
            }
            else if (i == size - 1) {
                int num = store.getSize();
                for (int m = 0; m < size - num; m++) {
                    store.push(0);
                }
            }
        }
        for (int m = size - 1; m >= 0; m--) {
            board[m][j] = store.peek();
            store.pop();
        }
    }

    return board;
}

vector<vector<int>> queue::goDown(vector<vector<int>>board) {
    int size = board.size();
    for (int j = 0; j < size; j++) {
        stack store;
        for (int i = size - 1; i >= 0; i--) {
            if (board[i][j] > 0 && board[i][j] < 2048) {
                if (store.peek() == board[i][j]) {
                    store.merge(board[i][j]);
                    if (i == 0) {
                        int num = store.getSize();
                        for (int k = 0; k < size - num; k++) {
                            store.push(0);
                        }
                    }
                }
                else {
                    store.push(board[i][j]);
                    if (i == 0) {
                        int num = store.getSize();
                        for (int k = 0; k < size - num; k++) {
                            store.push(0);
                        }
                    }
                }
            }
            else if (board[i][j] == 2048) {
                int num = store.getSize();
                for (int k = 0; k < size - 1 - num - i; k++) {
                    store.push(0);
                }
                store.push(2048);
            }
            else if (i == 0) {
                int num = store.getSize();
                for (int m = 0; m < size - num; m++) {
                    store.push(0);
                }
            }
        }
        for (int m = 0; m < size; m++) {
            board[m][j] = store.peek();
            store.pop();
        }
    }
    return board;
}

vector<vector<int>> queue::goRight(vector<vector<int>>board) {
    int size = board.size();
    for (int i = 0; i < size; i++) {
        stack store;
        for (int j = size - 1; j >= 0; j--) {
            if (board[i][j] > 0 && board[i][j] < 2048) {
                if (store.peek() == board[i][j]) {
                    store.merge(board[i][j]);
                    if (j == 0) {
                        int num = store.getSize();
                        for (int k = 0; k < size - num; k++) {
                            store.push(0);
                        }
                    }
                }
                else {
                    store.push(board[i][j]);
                    if (j == 0) {
                        int num = store.getSize();
                        for (int k = 0; k < size - num; k++) {
                            store.push(0);
                        }
                    }
                }
            }
            else if (board[i][j] == 2048) {
                int num = store.getSize();
                for (int k = 0; k < size - 1 - num - j; k++) {
                    store.push(0);
                }
                store.push(2048);
            }
            else if (j == 0) {
                int num = store.getSize();
                for (int m = 0; m < size - num; m++) {
                    store.push(0);
                }
            }
        }
        for (int m = 0; m < size; m++) {
            board[i][m] = store.peek();
            store.pop();
        }
    }

    return board;
}

vector<vector<int>> queue::goLeft(vector<vector<int>>board) {
    int size = board.size();
    for (int i = 0; i < size; i++) {
        stack store;
        for (int j = 0; j < size; j++) {
            if (board[i][j] > 0 && board[i][j] < 2048) {
                if (store.peek() == board[i][j]) {
                    store.merge(board[i][j]);
                    if (j == size - 1) {
                        int num = store.getSize();
                        for (int k = 0; k < size - num; k++) {
                            store.push(0);
                        }
                    }
                }
                else {
                    store.push(board[i][j]);
                    if (j == size - 1) {
                        int num = store.getSize();
                        for (int k = 0; k < size - num; k++) {
                            store.push(0);
                        }
                    }
                }
            }
            else if (board[i][j] == 2048) {
                int num = store.getSize();
                for (int k = 0; k < j - num; k++) {
                    store.push(0);
                }
                store.push(2048);
            }
            else if (j == size - 1) {
                int num = store.getSize();
                for (int m = 0; m < size - num; m++) {
                    store.push(0);
                }
            }
        }
        for (int m = size - 1; m >= 0; m--) {
            board[i][m] = store.peek();
            store.pop();
        }
    }
    return board;
}

string queue::fastMove() {

    if (!checkPowerOfTwo(head->myBoard)) {
     
        return "Impossible";
    }
    if (checkNum(head->myBoard)) {
        return "0";
    }

    while (!checkNum(head->myBoard) || getHead()->move.length() <= 12) {
      
        vector<vector<int>>origMatrix = head->myBoard;
        // vec *temp = head;
        
        vector<vector<int>>vectorUp = goUp(head->myBoard);
        if (origMatrix != vectorUp) {
            Enqueue(vectorUp, head->move + "1");
        }
        if (checkNum(vectorUp)) {
            return tail->move;
        }

        vector<vector<int>>vectorRight = goRight(head->myBoard);
        if (origMatrix != vectorRight) {
            Enqueue(vectorRight, head->move + "2");
        }
        if (checkNum(vectorRight)) {
            return tail->move;
        }

        vector<vector<int>>vectorDown = goDown(head->myBoard);
        if (origMatrix != vectorDown) {
            Enqueue(vectorDown, head->move + "3");
        }
        if (checkNum(vectorDown)) {
            return tail->move;
        }

        vector<vector<int>>vectorLeft = goLeft(head->myBoard);
        if (origMatrix != vectorLeft) {
            Enqueue(vectorLeft, head->move + "4");
        }
        if (checkNum(vectorLeft)) {
            return tail->move;
        }
        Dequeue();
        if (head == nullptr || getHead()->move.length() > 12) {
            return "Impossible";
        }
    }
    return "Impossible";
}


