#include "Mandelbrot.h"
#include <iostream>

sf::Image Mandelbrot::getImage(int maxIteration, unsigned int width, unsigned int height)
{
    sf::Image image;
    image.create(width, height);
    double maxPixelCount = width * height;
    double pixelCount = 0;

    double imageXCenter = image.getSize().x / 2;
    double imageYCenter = image.getSize().y / 2;

    for (unsigned int x = 0; x < image.getSize().x; x++) {
        for (unsigned int y = 0; y < image.getSize().y; y++) {
            double x0 = 2 * (x - imageXCenter) / imageXCenter;
            double y0 = 2 * (y - imageYCenter) / imageYCenter;
            
            std::complex<double> z0(x0, y0);
            std::complex<double> zn(0, 0);
            double xn = x0;
            double yn = y0;
            double iteration = 0;
            
            while (iteration < maxIteration && zn.real() * zn.real() + zn.imag() * zn.imag() < 4) {
                zn = zn * zn + z0;
                iteration++;
            }

            double ratio = 1 - iteration / maxIteration;
            sf::Color pixelColor(ratio * 255, ratio * 255, ratio * 255);
            image.setPixel(x, y, pixelColor);

            std::cout << ++pixelCount << "/" << maxPixelCount << std::endl;
        }
    }
    return image;
}
