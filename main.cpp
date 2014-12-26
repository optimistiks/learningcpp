#include <iostream>
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

int main() {
    Point points[3] = {Point(1, 2), Point(3, 4), Point(5, 6)};
    PointArray arr = PointArray(points, 3);

/*    for (int i = 0; i != 3; ++i) {
        std::cout << arr.get(i)->getX() << std::endl;
    }*/

    Point p(7, 2);

    arr.insert(2, p);

/*    for (int i = 0; i != 4; ++i) {
        std::cout << arr.get(i)->getX() << std::endl;
        std::cout << arr.getSize() << std::endl;
    }*/

    Polygon poly(arr);
    const PointArray *parr = poly.getPoints();

    return 0;
}