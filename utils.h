#ifndef UTILS_H
#define UTILS_H

#include <cmath>

struct Color {
    int r, g, b;
    Color(int r, int g, int b):r(r), g(g), b(b) {}
    Color() {}
};

struct Point {
    float x,y;
    Point (float x, float y):x(x), y(y) {}
};

struct Matrix3D {
    float data[3][3];
    Matrix3D (float _data[3][3]);
    Matrix3D ();
    void addElement(int row, int col, float value);
    Matrix3D getMatrix();
};

struct IdentityMatrix : public Matrix3D {
    IdentityMatrix();
};

struct TranslationMatrix : public Matrix3D {
    TranslationMatrix(int dx, int dy);
};

struct ScaleMatrix : public Matrix3D {
    ScaleMatrix(float sx, float sy);
};

struct RotateMatrix : public Matrix3D {
    RotateMatrix(float a);
};

struct ShearMatrixX : public Matrix3D {
    ShearMatrixX(float shx);
};

struct ShearMatrixY : public Matrix3D {
    ShearMatrixY(float shy);
};

struct ShearMatrix : public Matrix3D {
    ShearMatrix(float shx, float shy);
};

// Deklaracje funkcji (bez definicji)
Matrix3D multiply(const Matrix3D &m1, const Matrix3D &m2);
Matrix3D invert(const Matrix3D &m);

#endif // UTILS_H
