#pragma once
#include "Node.h"
#include "fstream"
template <typename T>
class Matrix {
    Node<T> Matr;//btw тут агрегація
public:
    Matrix() :Matr() {

    }
    Matrix(int w) :Matr(w) {

    }
    Matrix(int w, int h) :Matr(w, h) {

    }
    Matrix(int w, int h, const vector<T>& data) :Matr(w, h, data) {

    }

    //перевантаженні оператори:)
    Matrix operator+(const Matrix& other) const { // +
        if (Matr.getWidth() != other.Matr.getWidth() || Matr.getHeight() != other.Matr.getHeight()) {
            throw ErrorBase();
        }

        Matrix result(Matr.getWidth(), Matr.getHeight());
        for (int i = 0; i < Matr.getHeight(); ++i) {
            for (int j = 0; j < Matr.getWidth(); ++j) {
                if (Matr.getData()[i][j] > INT_MAX - other.Matr.getData()[i][j]) {
                    throw ErrorDerived();
                }
                result.Matr.getDataNoConst()[i][j] = Matr.getData()[i][j] + other.Matr.getData()[i][j];
            }
        }
        return result;
    }

    Matrix& operator+=(const Matrix& other) { // +=
        if (Matr.getWidth() != other.Matr.getWidth() || Matr.getHeight() != other.Matr.getHeight()) {
            throw ErrorBase();
        }

        for (int i = 0; i < Matr.getHeight(); ++i) {
            for (int j = 0; j < Matr.getWidth(); ++j) {
                if (Matr.getData()[i][j] > INT_MAX - other.Matr.getData()[i][j]) {
                    throw ErrorDerived();
                }
                Matr.getDataNoConst()[i][j] += other.Matr.getData()[i][j];
            }
        }
        return *this;
    }

    Matrix operator-(const Matrix& other) const { // -
        if (Matr.getWidth() != other.Matr.getWidth() || Matr.getHeight() != other.Matr.getHeight()) {
            throw ErrorBase();
        }

        Matrix result(Matr.getWidth(), Matr.getHeight());
        for (int i = 0; i < Matr.getHeight(); ++i) {
            for (int j = 0; j < Matr.getWidth(); ++j) {
                if (Matr.getData()[i][j] < INT_MIN + other.Matr.getData()[i][j]) {
                    throw ErrorDerived();
                }
                result.Matr.getDataNoConst()[i][j] = Matr.getData()[i][j] - other.Matr.getData()[i][j];
            }
        }
        return result;
    }

    Matrix& operator-=(const Matrix& other) { // -=
        if (Matr.getWidth() != other.Matr.getWidth() || Matr.getHeight() != other.Matr.getHeight()) {
            throw ErrorBase();
        }

        for (int i = 0; i < Matr.getHeight(); ++i) {
            for (int j = 0; j < Matr.getWidth(); ++j) {
                if (Matr.getData()[i][j] < INT_MIN + other.Matr.getData()[i][j]) {
                    throw ErrorDerived();
                }
                Matr.getDataNoConst()[i][j] = Matr.getData()[i][j] - other.Matr.getData()[i][j];
            }
        }
        return *this;
    }
    Matrix operator*(const Matrix& other) const { // *
        if (Matr.getWidth() != other.Matr.getHeight()) {
            throw ErrorBase();
        }
        Matrix result(Matr.getHeight(), other.Matr.getWidth());
        for (int i = 0; i < Matr.getHeight(); ++i) {
            for (int j = 0; j < other.Matr.getWidth(); ++j) {
                int sum = 0;
                for (int k = 0; k < Matr.getWidth(); ++k) {

                    if (Matr.getData()[i][k] != 0 &&
                        (other.Matr.getData()[k][j] > INT_MAX / Matr.getData()[i][k] ||
                            other.Matr.getData()[k][j] < INT_MIN / Matr.getData()[i][k])) {
                        throw ErrorDerived();
                    }
                    sum += Matr.getData()[i][k] * other.Matr.getData()[k][j];
                    if (sum > INT_MAX || sum < INT_MIN) {
                        throw ErrorDerived();
                    }
                }
                result.Matr.getDataNoConst()[i][j] = sum;
            }
        }

        return result;
    }
    Matrix& operator*=(const Matrix& other) { // *=
        if (Matr.getWidth() != other.Matr.getHeight()) {
            throw ErrorBase();
        }

        Matrix result(Matr.getHeight(), other.Matr.getWidth());
        for (int i = 0; i < Matr.getHeight(); ++i) {
            for (int j = 0; j < other.Matr.getWidth(); ++j) {
                int sum = 0;
                for (int k = 0; k < Matr.getWidth(); ++k) {
                    if (Matr.getData()[i][k] != 0 && (other.Matr.getData()[k][j] > INT_MAX / Matr.getData()[i][k] || other.Matr.getData()[k][j] < INT_MIN / Matr.getData()[i][k])) {
                        throw ErrorDerived();
                    }
                    sum += Matr.getData()[i][k] * other.Matr.getData()[k][j];
                    if (sum > INT_MAX || sum < INT_MIN) {
                        throw ErrorDerived();
                    }
                }
                result.Matr.getDataNoConst()[i][j] = sum;
            }
        }

        Matr = result.Matr;
        return *this;
    }

    Matrix kroneckerProduct(const Matrix& other) const {//добуток кронекера якщо прям дуже просто перший 
        //елемент першої матриці на весь рядок другої і так до кінця першого рядка другої матриці 
        //потім наступний елемент першої матриці і так до кінця рядка пешої матриці 
        //потім на другий рядок першої матриці і так до кінця рядків далі переходимо на другий рядок другої матриці і все поновому
        int rowsA = getHeight(), colsA = getWidth();
        int rowsB = other.getHeight(), colsB = other.getWidth();
        Matrix result(rowsA * rowsB, colsA * colsB);
        for (int i = 0; i < rowsA; ++i) {
            for (int j = 0; j < colsA; ++j) {
                T aVal = Matr.getElement(i, j);
                for (int k = 0; k < rowsB; ++k) {
                    for (int l = 0; l < colsB; ++l) {
                        T bVal = other.Matr.getElement(k, l);
                        result.Matr.setElement(i * rowsB + k, j * colsB + l, aVal * bVal);
                    }
                }
            }
        }

        return result;
    }
    Matrix kroneckerSum(const Matrix& other) const { // сума кронекера = А доб.кронекера І + В доб.кронекера І(І - одиничний екземпляр вке 0 крім головної діагоналі там 1)
        if (getWidth() != getHeight() || other.getWidth() != other.getHeight()) {
            throw ErrorBase();
        }
        int n = getWidth();
        int m = other.getWidth();
        Matrix identityN(n, n);
        Matrix identityM(m, m);
        for (int i = 0; i < n; ++i) {
            identityN.Matr.setElement(i, i, 1);
        }
        for (int i = 0; i < m; ++i) {
            identityM.Matr.setElement(i, i, 1);
        }
        Matrix kronA = this->kroneckerProduct(identityM);
        Matrix kronB = other.kroneckerProduct(identityN);
        return kronA + kronB;
    }
    Matrix<T> LineSum(const Matrix<T>& other) const {
        int width1 = this->getHeight();
        int height1 = this->getWidth();
        int width2 = other.getHeight();
        int height2 = other.getWidth();
        int rWidth = width1 + width2;
        int rHeight = height1 + height2;
        Matrix<T> result(rWidth, rHeight);
        for (int i = 0; i < height1; ++i) {
            for (int j = 0; j < width1; ++j) {
                result.Matr.setElement(i, j, this->Matr.getElement(i, j));
            }
        }
        for (int i = 0; i < height2; ++i) {
            for (int j = 0; j < width2; ++j) {
                result.Matr.setElement(i + height1, j + width1, other.Matr.getElement(i, j));
            }
        }
        return result;
    }



    void saveToFile(const string& filename) {//зберігає ширину висоту і data
        ofstream fileToSave(filename, ios::binary | ios::trunc);//відкриваєм файлік ios::binary щоб був бінарним(так в інеті сказали) ios::trunc треба щоб попередня інфа правилбно удалялась і файл міг зберегти інфу до некст запуску
        if (!fileToSave) {
            throw ErrorO();//дефолтна перевірка на можливість відкриття файлу
        }
        int width = Matr.getWidth();
        int height = Matr.getHeight();
        fileToSave.write((char*)&width, sizeof(width));
        fileToSave.write((char*)&height, sizeof(height));
        const auto& data = Matr.getData();
        for (const auto& row : data) {// записуємо кожне значення окремо
            for (const auto& value : row) {
                fileToSave.write((char*)&value, sizeof(T));
            }
        }
        fileToSave.close();

    }
    void loadFromFile(const string& filename) {
        ifstream fileToLoad(filename, ios::binary);
        if (!fileToLoad) {
            throw ErrorO();
        }
        int width, height;
        fileToLoad.read((char*)&width, sizeof(width));
        fileToLoad.read((char*)&height, sizeof(height));
        vector<vector<T>> data(height, vector<T>(width));
        for (auto& row : data) {
            for (auto& value : row) {
                fileToLoad.read((char*)&value, sizeof(T));
            }
        }
        Matr.setWidth(width);
        Matr.setHeight(height);
        Matr.setData(data);
        fileToLoad.close();
    }


    void show() {
        Matr.show();
    }


    int getWidth() const { return Matr.getWidth(); }
    int getHeight() const { return Matr.getHeight(); }
};