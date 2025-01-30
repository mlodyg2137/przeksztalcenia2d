#include "screen.h"
#include <QPainter>
#include <cmath>
#include "utils.h"


Screen::Screen(QWidget *parent)
    : QWidget{parent}
{
    canvas = QImage(width, height, QImage::Format_RGB32);
    canvas.fill(Qt::white);

    image = QImage(":/img/pudzian.png");

    if (!image.isNull()) {
        QPainter painter(&canvas);
        painter.drawImage((canvas.width() - image.width()) / 2,  // Wyśrodkowanie na osi X
                          (canvas.height() - image.height()) / 2, // Wyśrodkowanie na osi Y
                          image);
    }
}


void Screen::paintEvent(QPaintEvent *event) {
    QPainter p(this);
    p.drawImage(0, 0, canvas);
}


void Screen::drawPixel(QImage& im, int x, int y, int r, int g, int b, int a) {
    if(x < 0 || y < 0 || x >= im.width() || y >= im.height()) return;
    uchar *line = im.scanLine(y);
    line[4 * x + 0] = b;
    line[4 * x + 1] = g;
    line[4 * x + 2] = r;
    line[4 * x + 3] = a;
}


Color Screen::getPixel(int x, int y) {
    unsigned char *ptr = image.bits();
    int index = (y * image.width() + x) * 4;

    Color color;
    color.b = ptr[index + 0];
    color.g = ptr[index + 1];
    color.r = ptr[index + 2];

    return color;
}


Color Screen::bilinearInterpolation(float fx, float fy)
{

    int x1 = (int)std::floor(fx);
    int y1 = (int)std::floor(fy);
    int x2 = x1 + 1;
    int y2 = y1 + 1;

    float alpha = fx - x1;
    float beta = fy - y1;

    Color c11 = getPixel(x1, y1);
    Color c21 = getPixel(x2, y1);
    Color c12 = getPixel(x1, y2);
    Color c22 = getPixel(x2, y2);

    float r = (1 - alpha)*(1 - beta)*c11.r +
              alpha*(1 - beta)*c21.r +
              (1 - alpha)*beta*c12.r +
              alpha*beta*c22.r;

    float g = (1 - alpha)*(1 - beta)*c11.g +
              alpha*(1 - beta)*c21.g +
              (1 - alpha)*beta*c12.g +
              alpha*beta*c22.g;

    float b = (1 - alpha)*(1 - beta)*c11.b +
              alpha*(1 - beta)*c21.b +
              (1 - alpha)*beta*c12.b +
              alpha*beta*c22.b;

    Color out;
    out.r = (unsigned char)std::round(r);
    out.g = (unsigned char)std::round(g);
    out.b = (unsigned char)std::round(b);

    return out;
}


// setters
void Screen::setTranslationX(int value) {   translation_x = 0.5f*(width-image_width)*(value/100.0f);    }
void Screen::setTranslationY(int value) {   translation_y = 0.5f*(height-image_width)*(value/100.0f);   }
void Screen::setRotation(int value)     {   rotation = (value/100.0f)*2*M_PI;               }
void Screen::setScalingX(int value)     {   scaling_x = (value+100)/100.0f;                 }
void Screen::setScalingY(int value)     {   scaling_y = (value+100)/100.0f;                 }
void Screen::setShearingX(int value)    {   shearing_x = -(value)/100.0f;                 }
void Screen::setShearingY(int value)    {   shearing_y = -(value)/100.0f;                 }


void Screen::updateImage() {

    if (image.isNull()) return;

    float cx = image.width()/2.0f; // center of screen on x
    float cy = image.height()/2.0f; // center of screen on y

    qDebug() << "translation: x=" << translation_x << " y=" << translation_y;
    qDebug() << "rotation: alpha=" << rotation;
    qDebug() << "scaling: x=" << scaling_x << " y=" << scaling_y;
    qDebug() << "shearing: x=" << shearing_x << " y=" << shearing_y;
    qDebug() << "Center: x=" << cx << " y=" << cy;
    qDebug() << "--------------";

    canvas.fill(Qt::white);

    Matrix3D translation_center = TranslationMatrix(cx, cy);
    Matrix3D translation_corner = TranslationMatrix(-cx, -cy);
    Matrix3D translation_matrix = TranslationMatrix(translation_x, translation_y);
    Matrix3D rotate_matrix = RotateMatrix(rotation);
    Matrix3D scale_matrix = ScaleMatrix(scaling_x, scaling_y);
    Matrix3D shear_matrix = ShearMatrix(shearing_x, shearing_y);


    // Kolejnosc:
    // Przesuniecie do lewego gornego rogu -> Rozciagniecie -> Przeskalowanie ->
    // Obrót -> Przesuniecie do centrum -> Translacja
    Matrix3D matrix = IdentityMatrix();
    matrix = multiply(matrix, translation_matrix);
    matrix = multiply(matrix, translation_center);
    matrix = multiply(matrix, rotate_matrix);
    matrix = multiply(matrix, scale_matrix);
    matrix = multiply(matrix, shear_matrix);
    matrix = multiply(matrix, translation_corner);

    Matrix3D inverted_matrix = invert(matrix);

    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {

            Point p { static_cast<float>(x), static_cast<float>(y) };

            float xx = inverted_matrix.data[0][0]*p.x + inverted_matrix.data[0][1]*p.y + inverted_matrix.data[0][2];
            float yy = inverted_matrix.data[1][0]*p.x + inverted_matrix.data[1][1]*p.y + inverted_matrix.data[1][2];

            float srcX = xx;
            float srcY = yy;

            if(srcX >= 0 && srcX < image.width() - 1 &&
                srcY >= 0 && srcY < image.height() - 1)
            {
                Color color = bilinearInterpolation(srcX, srcY);

                drawPixel(canvas, x, y, color.r, color.g, color.b);
            }
            else
            {
                drawPixel(canvas, x, y, 255, 255, 255);
            }
        }
    }

    update();
}
