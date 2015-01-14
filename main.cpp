#include <iostream>
#include <cmath>
#include <string>
#include "geometry.h"

PointArray::PointArray() {
    this->size = 0;
    this->points = new Point[this->size];
}

PointArray::PointArray(const Point points[], const int size) {
    this->size = size;
    this->points = new Point[this->size];

    for (int i = 0; i != this->size; ++i) {
        this->points[i] = points[i];
    }
}

PointArray::PointArray(const PointArray &pa) {
    this->size = pa.size;
    this->points = new Point[this->size];

    for (int i = 0; i != this->size; ++i) {
        this->points[i] = pa.points[i];
    }
}

void PointArray::push_back(const Point &p) {
    int newSize = this->size + 1;
    this->resize(newSize);
    this->points[newSize] = p;
}

void PointArray::insert(const int position, const Point &p) {
    int newSize = this->size + 1;
    this->resize(newSize);
    for (int i = this->size - 2; i >= position; --i) {
        this->points[i + 1] = this->points[i];
    }
    this->points[position] = p;
}

void PointArray::remove(const int pos) {
    if (pos >= 0 && pos < size) {
        int newSize = this->size - 1;
        for (int i = pos; i != this->size - 1; ++i) {
            this->points[i] = this->points[i + 1];
        }
        this->resize(newSize);
    }
}

void PointArray::clear() {
    this->resize(0);
}

int Polygon::count = 0;

int Polygon::getNumPolygons() const {
    return this->count;
};

int Polygon::getNumSides() const {
    return this->points.getSize();
};

const PointArray *const Polygon::getPoints() const {
    return &(this->points);
};

double Rectangle::area() const {
    int width = this->getPoints()->get(0)->getX() - this->getPoints()->get(1)->getX();
    int height = this->getPoints()->get(0)->getY() - this->getPoints()->get(3)->getY();
    return double(std::abs(width * height));
}

double Triangle::area() const {
    double a = double(std::sqrt(std::pow(this->getPoints()->get(1)->getX() - this->getPoints()->get(0)->getX(), 2) + std::pow(this->getPoints()->get(1)->getY() - this->getPoints()->get(0)->getY(), 2)));
    double b = double(std::sqrt(std::pow(this->getPoints()->get(2)->getX() - this->getPoints()->get(1)->getX(), 2) + std::pow(this->getPoints()->get(2)->getY() - this->getPoints()->get(1)->getY(), 2)));
    double c = double(std::sqrt(std::pow(this->getPoints()->get(2)->getX() - this->getPoints()->get(0)->getX(), 2) + std::pow(this->getPoints()->get(2)->getY() - this->getPoints()->get(0)->getY(), 2)));
    double s = (a + b + c) / 2;
    double k = std::sqrt(s * (s - a) * (s - b) * (s - c));
    return k;
}

void printAttributes(Polygon * poly) {
    std::cout << "Area of the polygon = " << (*poly).area() << std::endl;
    Point const *p;
    std::cout << "Points: ";
    for (int i = 0; i != poly->getPoints()->getSize(); ++i) {
        p = poly->getPoints()->get(i);
        std::cout << p->getX() << ',' << p->getY() << ' ';
    }
    std::cout << std::endl;
}

const std::string vowels = "eyuioa";
const std::string ay = "ay";

std::string pigLatinify(std::string const str) {
    std::string result;
    if (vowels.find(str[0]) == std::string::npos) {
        result = str.substr(1);
        result += (std::string("-") + str[0] + (str[0] != 'q' ? "" : "u")) + ay;
    } else {
        result = str + "-w" + ay;
    }
    return result;
}

int main() {
    std::string input;
    std::cin >> input;
    std::cout << pigLatinify(input);
    return 0;
}