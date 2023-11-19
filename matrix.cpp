#include <iostream>

template <typename T>
class Matrix {
public:
    Matrix(int row, int col) {
        this->row = row;
        this->col = col;
        this->items = new T[row * col];
    }

    Matrix(const Matrix& other) {
        col = other.col;
        row = other.row;
        items = new T[row * col];
        for (int i=0; i<row * col; ++i){
            items[i] = other.items[i];
        }
    }

    Matrix& operator=(const Matrix& other) {
        col = other.col;
        row = other.row;

        delete items;
        items = new T[row * col];

        for (int i=0; i<row * col; ++i){
            items[i] = other.items[i];
        }

        return *this;
    }

    ~Matrix() {
        delete[] this->items;
    }

    int getRow() const { return row; }
    int getCol() const { return col; }

    T& operator()(int i, int j) const {
        return items[col * i + j];
    }

    Matrix operator+(const Matrix& other) {
        Matrix result(row, col);

        for (int i = 0; i < row * col; ++i) {
            result.items[i] = items[i] + other.items[i];
        }

        return result;
    }

private:
    int row, col;
    T* items;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Matrix<T>& m) {
    for (int i = 0; i < m.getRow(); ++i) {
        for (int j = 0; j < m.getCol(); j++) {
            out << m(i, j) << '\t';
        }
        std::cout << std::endl;
    }
    return out;
}

int main() {
    Matrix<double> m1(3, 5), m2(3, 5);

    for (int i = 0; i < m1.getRow(); ++i) {
        for (int j = 0; j < m1.getCol(); ++j) {
            m1(i, j) = i + j;
            m2(i, j) = i + j + 0.5;
        }
    }

    std::cout << (m1 + m2) << std::endl;
}
