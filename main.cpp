#include <iostream>
#include <cmath>
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

int main() {
    Rectangle rec(Point(1, 2), Point(3, 4));
    std::cout << rec.area() << std::endl;
    return 0;
}