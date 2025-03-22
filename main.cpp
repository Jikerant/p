#include "matrix.h"
#include "vector"
#include "Error.h"
#include <iostream>
using namespace std;

int main() {
    int chs = 0;
    int chs1 = 0; int w, h;
    cout << "Menu:\n1. Create Matrix\n2. Create Matrix 2\n3. Show Matrix\n4. Add Matrices\n5. Subtract Matrices\n6. Multiplying Matrices\n7. Add Matrices (+=)\n8. Subtract Matrices (-=)\n9. Multiplying Matrices (*=)\n10. Save\n11. Load\n12. Kroneker Sum\n13. Line Sum\n14. Exit\n";


    Matrix<int> intMatrix1, intMatrix2, intResult;
    Matrix<double> doubleMatrix1, doubleMatrix2, doubleResult;


    while (chs != 14) {
        cout << "\nChoice: ";
        cin >> chs;

        try {
            switch (chs) {
            case 1: {
                cout << "Choose 1 - int, 2 - double: ";
                cin >> chs1;
                cout << "Enter width and height: ";
                cin >> w >> h;

                if (chs1 == 1) {
                    vector<int> data(w * h);
                    cout << "Enter: ";
                    for (int i = 0; i < w * h; ++i) {
                        cin >> data[i];
                    }
                    intMatrix1 = Matrix<int>(w, h, data);
                }
                else if (chs1 == 2) {
                    vector<double> data(w * h);
                    cout << "Enter: ";
                    for (int i = 0; i < w * h; ++i) {
                        cin >> data[i];
                    }
                    doubleMatrix1 = Matrix<double>(w, h, data);
                }
                else {
                    cout << "Invalid choice. Try again.\n";
                }
                cout << "Done";
                break;
            }
            case 2: {
                cout << "Enter width and height: ";
                cin >> w >> h;
                if (chs1 == 1) {

                    vector<int> data(w * h);
                    cout << "Enter: ";
                    for (int i = 0; i < w * h; ++i) {
                        cin >> data[i];
                    }
                    intMatrix2 = Matrix<int> (w, h, data);
                }
                else if (chs1 == 2) {
                    vector<double> data(w * h);
                    cout << "Enter: ";
                    for (int i = 0; i < w * h; ++i) {
                        cin >> data[i];
                    }
                    doubleMatrix2 = Matrix<double>(w, h, data);
                }
                else {
                    throw ErrorInI();
                }
                cout << "Done";
                break;
            }
            case 3: {

                if (chs1 == 1) {
                    if (intMatrix1.getHeight() == 0 | intMatrix2.getHeight() == 0)throw ErrorIn();
                    cout << "Matrix 1:\n";
                    intMatrix1.show();
                    cout << "\n---------------------\n";
                    cout << "Matrix 2:\n";
                    intMatrix2.show();
                }
                else if (chs1 == 2) {
                    if (doubleMatrix1.getHeight() == 0 | doubleMatrix2.getHeight() == 0)throw ErrorIn();
                    cout << "Matrix 1:\n";
                    doubleMatrix1.show();
                    cout << "\n---------------------\n";
                    cout << "Matrix 2:\n";
                    doubleMatrix2.show();
                }
                else
                    throw ErrorInI();
                break;
            }

            case 4: {
                if (chs1 == 1) {
                    if (intMatrix1.getHeight() == 0 | intMatrix2.getHeight() == 0)throw ErrorIn();
                    intResult = intMatrix1 + intMatrix2;
                    intResult.show();
                }
                else if (chs1 == 2) {
                    if (doubleMatrix1.getHeight() == 0 | doubleMatrix2.getHeight() == 0)throw ErrorIn();
                    doubleResult = doubleMatrix1 + doubleMatrix2;
                    doubleResult.show();
                }
                else
                    throw ErrorInI();
                break;
            }
            case 5: {
                if (chs1 == 1) {
                    if (intMatrix1.getHeight() == 0 | intMatrix2.getHeight() == 0)throw ErrorIn();
                    intResult = intMatrix1 - intMatrix2;
                    intResult.show();
                }
                else if (chs1 == 2) {
                    if (doubleMatrix1.getHeight() == 0 | doubleMatrix2.getHeight() == 0)throw ErrorIn();
                    doubleResult = doubleMatrix1 - doubleMatrix2;
                    doubleResult.show();
                }
                else
                    throw ErrorInI();
                break;
            }
            case 6: {
                if (chs1 == 1) {
                    if (intMatrix1.getHeight() == 0 | intMatrix2.getHeight() == 0)throw ErrorIn();
                    intResult = intMatrix1 * intMatrix2;
                    intResult.show();
                }
                else if (chs1 == 2) {
                    if (doubleMatrix1.getHeight() == 0 | doubleMatrix2.getHeight() == 0)throw ErrorIn();
                    doubleResult = doubleMatrix1 * doubleMatrix2;
                    doubleResult.show();
                }
                else
                    throw ErrorInI();
                break;
            }
            case 7: {
                if (chs1 == 1) {
                    if (intMatrix1.getHeight() == 0 | intMatrix2.getHeight() == 0)throw ErrorIn();
                    intMatrix1 += intMatrix2;
                    intResult = intMatrix1 + intMatrix2;
                    intResult.show();
                }
                else if (chs1 == 2) {
                    if (doubleMatrix1.getHeight() == 0 | doubleMatrix2.getHeight() == 0)throw ErrorIn();
                    doubleMatrix1 += doubleMatrix2;
                    doubleResult = doubleMatrix1 + doubleMatrix2;
                    doubleResult.show();
                }
                else
                    throw ErrorInI();
                break;
            }
            case 8: {
                if (chs1 == 1) {
                    if (intMatrix1.getHeight() == 0 | intMatrix2.getHeight() == 0)throw ErrorIn();
                    intMatrix1 -= intMatrix2;
                    intResult = intMatrix1 - intMatrix2;
                    intResult.show();
                }
                else if (chs1 == 2) {
                    if (doubleMatrix1.getHeight() == 0 | doubleMatrix2.getHeight() == 0)throw ErrorIn();
                    doubleMatrix1 -= doubleMatrix2;
                    doubleResult = doubleMatrix1 - doubleMatrix2;
                    doubleResult.show();
                }
                else
                    throw ErrorInI();
                break;
            }
            case 9: {
                if (chs1 == 1) {
                    if (intMatrix1.getHeight() == 0 | intMatrix2.getHeight() == 0)throw ErrorIn();
                    intMatrix1 *= intMatrix2;
                    intResult = intMatrix1 * intMatrix2;
                    intResult.show();
                }
                else if (chs1 == 2) {
                    if (doubleMatrix1.getHeight() == 0 | doubleMatrix2.getHeight() == 0)throw ErrorIn();
                    doubleMatrix1 *= doubleMatrix2;
                    doubleResult = doubleMatrix1 * doubleMatrix2;
                    doubleResult.show();
                }
                else
                    throw ErrorInI();
                break;
            }
            case 10: {

                if (chs1 == 1) {
                    if (intMatrix1.getHeight() == 0 | intMatrix2.getHeight() == 0)throw ErrorIn();
                    intResult.saveToFile("matrix.bin");
                }

                else if (chs1 == 2)
                {
                    if (doubleMatrix1.getHeight() == 0 | doubleMatrix2.getHeight() == 0)throw ErrorIn();
                    doubleResult.saveToFile("matrixDb.bin");
                }
                else
                    throw ErrorInI();
                cout << "Done\n";

                break;
            }
            case 11: {

                if (chs1 == 1)
                {
                    if (intMatrix1.getHeight() == 0 | intMatrix2.getHeight() == 0)throw ErrorIn();
                    intResult.loadFromFile("matrix.bin");
                    intResult.show();
                }
                else if (chs1 == 2)
                {
                    if (doubleMatrix1.getHeight() == 0 | doubleMatrix2.getHeight() == 0)throw ErrorIn();
                    doubleResult.loadFromFile("matrixDb.bin");
                    doubleResult.show();
                }
                else
                    throw ErrorIn();
                cout << "Done\n";

                break;
            }
            case 12: {
                if (chs1 == 1) {
                    if (intMatrix1.getHeight() == 0 | intMatrix2.getHeight() == 0)throw ErrorIn();
                    intResult = intMatrix1.kroneckerSum(intMatrix2);
                    intResult.show();
                }

                else if (chs1 == 2) {
                    if (doubleMatrix1.getHeight() == 0 | doubleMatrix2.getHeight() == 0)throw ErrorIn();
                    doubleResult = doubleMatrix1.kroneckerSum(doubleMatrix2);
                    doubleResult.show();

                }

                else
                    throw ErrorInI();
                break;
            }
            case 13: {
                if (chs1 == 1) {
                    if (intMatrix1.getHeight() == 0 | intMatrix2.getHeight() == 0)throw ErrorIn();
                    intResult = intMatrix1.LineSum(intMatrix2);
                    intResult.show();
                }

                else if (chs1 == 2) {
                    if (doubleMatrix1.getHeight() == 0 | doubleMatrix2.getHeight() == 0)throw ErrorIn();
                    doubleResult = doubleMatrix1.LineSum(doubleMatrix2);
                    doubleResult.show();

                }

                else
                    throw ErrorInI();
                break;
            }
            case 14: {
                cout << "Exiting program.\n";
                break;

            }
            default: {
                cout << "Try again.\n";
                break;
            }

            }
        }

        catch (ErrorBase& e) {
            e.Message();
        }
        catch (ErrorInI& e) {
            e.Message();
        }
        catch (ErrorDerived& e) {
            e.Message();
        }
        catch (ErrorIn& e) {
            e.Message();
        }
        catch (...) {
            cout << "unknown Error ";
        }
    }
}

