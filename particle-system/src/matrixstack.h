#ifndef MATRIXSTACK_H
#define MATRIXSTACK_H

#include <vector>

using namespace std;

template<typename T> class MatrixStack {
private:
    vector<T> stack;
public:

    MatrixStack() {}

    size_t size() const {
        return stack.size();
    }

    void push(T mat) {
        T top = stack.back();
        stack.push_back(top * mat);
    }

    bool pop() {
        if(size() > 1) {
            stack.pop_back();
            return true;
        } else {
            return false;
        }
    }
};

#endif // MATRIXSTACK_H
