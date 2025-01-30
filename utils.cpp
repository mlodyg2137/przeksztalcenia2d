#include "utils.h"

// Definicje metod Matrix3D
Matrix3D::Matrix3D (float _data[3][3]) {
    for (int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            data[i][j] = _data[i][j];
}
Matrix3D::Matrix3D () {}

void Matrix3D::addElement(int row, int col, float value) {
    if (abs(row)>3 or abs(col)>3) return;
    data[row][col] = value;
}

Matrix3D Matrix3D::getMatrix() {
    return *this;
}

// Definicje konstruktorów macierzy transformacji
IdentityMatrix::IdentityMatrix() {
    data[0][0]=1; data[0][1]=0; data[0][2]=0;
    data[1][0]=0; data[1][1]=1; data[1][2]=0;
    data[2][0]=0; data[2][1]=0; data[2][2]=1;
}

TranslationMatrix::TranslationMatrix(int dx, int dy) {
    data[0][0]=1; data[0][1]=0; data[0][2]=dx;
    data[1][0]=0; data[1][1]=1; data[1][2]=dy;
    data[2][0]=0; data[2][1]=0; data[2][2]=1;
}

ScaleMatrix::ScaleMatrix(float sx, float sy) {
    data[0][0]=sx; data[0][1]=0; data[0][2]=0;
    data[1][0]=0; data[1][1]=sy; data[1][2]=0;
    data[2][0]=0; data[2][1]=0; data[2][2]=1;
}

RotateMatrix::RotateMatrix(float a) {
    data[0][0]=cos(a); data[0][1]=-sin(a); data[0][2]=0;
    data[1][0]=sin(a); data[1][1]=cos(a); data[1][2]=0;
    data[2][0]=0; data[2][1]=0; data[2][2]=1;
}

ShearMatrixX::ShearMatrixX(float shx) {
    data[0][0]=1; data[0][1]=shx; data[0][2]=0;
    data[1][0]=0; data[1][1]=1; data[1][2]=0;
    data[2][0]=0; data[2][1]=0; data[2][2]=1;
}

ShearMatrixY::ShearMatrixY(float shy) {
    data[0][0]=1; data[0][1]=0; data[0][2]=0;
    data[1][0]=shy; data[1][1]=1; data[1][2]=0;
    data[2][0]=0; data[2][1]=0; data[2][2]=1;
}

ShearMatrix::ShearMatrix(float shx, float shy) {
    data[0][0]=1; data[0][1]=shx; data[0][2]=0;
    data[1][0]=shy; data[1][1]=1; data[1][2]=0;
    data[2][0]=0; data[2][1]=0; data[2][2]=1;
}

// Definicja funkcji multiply
Matrix3D multiply(const Matrix3D &m1, const Matrix3D &m2) {
    Matrix3D result;
    for (int row=0; row<3; row++) {
        for (int col=0; col<3; col++) {
            result.data[row][col] = 0;
            for (int i=0; i<3; i++) {
                result.data[row][col] += m1.data[row][i] * m2.data[i][col];
            }
        }
    }
    return result;
}

// Definicja funkcji invert
Matrix3D invert(const Matrix3D &m) {
    float det = m.data[0][0] * m.data[1][1] * m.data[2][2] +
                m.data[0][1] * m.data[1][2] * m.data[2][0] +
                m.data[0][2] * m.data[1][0] * m.data[2][1] -
                m.data[0][2] * m.data[1][1] * m.data[2][0] -
                m.data[0][1] * m.data[1][0] * m.data[2][2] -
                m.data[0][0] * m.data[1][2] * m.data[2][1];

    if (fabs(det) < 1e-12) {
        return IdentityMatrix();
    }

    Matrix3D R;
    R.data[0][0] = (m.data[1][1] * m.data[2][2] - m.data[1][2] * m.data[2][1]) / det;
    R.data[0][1] = (m.data[0][2] * m.data[2][1] - m.data[0][1] * m.data[2][2]) / det;
    R.data[0][2] = (m.data[0][1] * m.data[1][2] - m.data[0][2] * m.data[1][1]) / det;
    R.data[1][0] = (m.data[1][2] * m.data[2][0] - m.data[1][0] * m.data[2][2]) / det;
    R.data[1][1] = (m.data[0][0] * m.data[2][2] - m.data[0][2] * m.data[2][0]) / det;
    R.data[1][2] = (m.data[0][2] * m.data[1][0] - m.data[0][0] * m.data[1][2]) / det;
    R.data[2][0] = (m.data[1][0] * m.data[2][1] - m.data[1][1] * m.data[2][0]) / det;
    R.data[2][1] = (m.data[0][1] * m.data[2][0] - m.data[0][0] * m.data[2][1]) / det;
    R.data[2][2] = (m.data[0][0] * m.data[1][1] - m.data[0][1] * m.data[1][0]) / det;
    return R;
}
