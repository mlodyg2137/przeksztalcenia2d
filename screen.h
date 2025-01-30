#ifndef SCREEN_H
#define SCREEN_H

#include <QWidget>
#include "utils.h"

class Screen : public QWidget
{
    Q_OBJECT
public:
    explicit Screen(QWidget *parent = nullptr);
    QImage canvas, image;
    int width = 900;
    int height = 600;
    int image_width = 400;
    int image_height = 300;

    float translation_x=0;
    float translation_y=0;
    float rotation=0;
    float scaling_x=1.0f;
    float scaling_y=1.0f;
    float shearing_x=0;
    float shearing_y=0;

    void drawPixel(QImage& im, int x, int y, int r, int g, int b, int a = 255);
    void updateImage();
    void setTranslationX(int value);
    void setTranslationY(int value);
    void setRotation(int value);
    void setScalingX(int value);
    void setScalingY(int value);
    void setShearingX(int value);
    void setShearingY(int value);
    Color getPixel(int x, int y);
    Color bilinearInterpolation(float fx, float fy);


protected:
    void paintEvent(QPaintEvent *event);
signals:
};

#endif // SCREEN_H
