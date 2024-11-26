#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cmath>

using namespace std;

typedef vector<vector<float>> Matrix;

// Funktion zum Einlesen einer Matrix im Binärformat
Matrix readBinaryMatrix(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "Fehler: Datei " << filename << " konnte nicht geöffnet werden." << endl;
        exit(EXIT_FAILURE);
    }

    // Lesen der Dimensionen (Zeilen und Spalten)
    int rows, cols;
    file.read(reinterpret_cast<char*>(&rows), sizeof(int));
    file.read(reinterpret_cast<char*>(&cols), sizeof(int));

    // Matrix einlesen
    Matrix matrix(rows, vector<float>(cols));
    for (int i = 0; i < rows; ++i) {
        file.read(reinterpret_cast<char*>(&matrix[i][0]), cols * sizeof(float));
    }

    file.close();

    return matrix;
}

// Funktion zum Schreiben einer Matrix im Binärformat
void writeBinaryMatrix(const string& filename, const Matrix& matrix) {
    ofstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "Fehler: Datei " << filename << " konnte nicht geöffnet werden." << endl;
        exit(EXIT_FAILURE);
    }

    int rows = matrix.size();
    int cols = matrix[0].size();
    file.write(reinterpret_cast<const char*>(&rows), sizeof(int));
    file.write(reinterpret_cast<const char*>(&cols), sizeof(int));

    for (const auto& row : matrix) {
        file.write(reinterpret_cast<const char*>(&row[0]), cols * sizeof(float));
    }

    file.close();
}

// Funktion zur Berechnung der Determinante einer Matrix (nur für quadratische Matrizen)
float determinant(const Matrix& matrix) {
    int n = matrix.size();
    if (n != matrix[0].size()) {
        throw invalid_argument("Die Matrix muss quadratisch sein, um die Determinante zu berechnen.");
    }

    Matrix temp = matrix;

    // Gauss-Elimination zur Berechnung der Determinante
    for (int i = 0; i < n; ++i) {
        // Pivotisierung: Finden des maximalen Elements in der Spalte
        float maxElem = fabs(temp[i][i]);
        int maxRow = i;
        for (int j = i + 1; j < n; ++j) {
            if (fabs(temp[j][i]) > maxElem) {
                maxElem = fabs(temp[j][i]);
                maxRow = j;
            }
        }

        // Zeilen tauschen, wenn nötig
        if (maxRow != i) {
            swap(temp[i], temp[maxRow]);
        }

        // Wenn das Pivot-Element null ist, ist die Determinante 0
        if (temp[i][i] == 0) {
            return 0.0f;
        }

        // Elimination
        for (int j = i + 1; j < n; ++j) {
            float factor = temp[j][i] / temp[i][i];
            for (int k = i; k < n; ++k) {
                temp[j][k] -= factor * temp[i][k];
            }
        }
    }

    // Determinante ist das Produkt der Diagonalenelemente
    float det = 1.0f;
    for (int i = 0; i < n; ++i) {
        det *= temp[i][i];
    }

    return det;
}

// Funktion zur Überprüfung der Dimensionen und Durchführung der Matrizenmultiplikation
Matrix multiplyMatrices(const Matrix& A, const Matrix& B) {
    if (A[0].size() != B.size()) {
        cerr << "Fehler: Die Matrizen sind inkompatibel für die Multiplikation." << endl;
        exit(EXIT_FAILURE);
    }

    size_t rowsA = A.size();
    size_t colsA = A[0].size();
    size_t colsB = B[0].size();

    Matrix C(rowsA, vector<float>(colsB, 0.0));

    for (size_t i = 0; i < rowsA; ++i) {
        for (size_t j = 0; j < colsB; ++j) {
            for (size_t k = 0; k < colsA; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

// Funktion zum Ausgeben der Matrix auf der Konsole
void printMatrix(const Matrix& matrix) {
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main() {
    // Matrizen im Binärformat einlesen
    Matrix A = readBinaryMatrix("matrix_A.bin");
    Matrix B = readBinaryMatrix("matrix_B.bin");


    cout << "Matrix A:" << endl;
    printMatrix(A);
    cout << endl;

    cout << "Matrix B:" << endl;
    printMatrix(B);
    cout << endl;


    Matrix C = multiplyMatrices(A, B);


    writeBinaryMatrix("matrix_C.bin", C);


    cout << "Matrix C (A * B):" << endl;
    printMatrix(C);
    cout << endl;

    // Determinante der Ergebnismatrix berechnen
    try {
        float detC = determinant(C);
        cout << "Die Determinante der Matrix C ist: " << detC << endl;
    } catch (const exception& e) {
        cerr << "Fehler: " << e.what() << endl;
    }

    cout << "Die Multiplikation wurde erfolgreich durchgeführt. Ergebnis in matrix_C.bin gespeichert." << endl;

    return 0;
}
