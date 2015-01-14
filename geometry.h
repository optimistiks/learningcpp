#include <algorithm>

class Point {
private:
    int x;
    int y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {
    }

    int getX() const {
        return x;
    };

    int getY() const {
        return y;
    };

    void setX(const int x) {
        this->x = x;
    }

    void setY(const int Y) {
        this->y = y;
    }
};

class PointArray {
private:
    int size;
    Point *points;

protected:
    void resize(const int n) {
        Point *newPoints = new Point[n];
        int minSize = std::min(this->size, n);
        for (int i = 0; i != minSize; ++i) {
            newPoints[i] = this->points[i];
        }

        delete[] this->points;

        this->points = newPoints;
        this->size = n;
    };

public:
    PointArray();

    PointArray(const Point points[], const int size);

    PointArray(const PointArray &pa);

    ~PointArray() {
        delete[] points;
    }

    const Point *get(const int position) const {
        if (position >= 0 && position < this->size) {
            return points + position;
        } else {
            return nullptr;
        }
    };

    Point *get(const int position) {
        if (position >= 0 && position <= this->size) {
            return points + position;
        } else {
            return nullptr;
        }
    };

    const int getSize() const {
        return size;
    };

    void push_back(const Point &p);

    void insert(const int position, const Point &p);

    void remove(const int pos);

    void clear();
};

class Polygon {
/*protected:
    static int count;
    PointArray points;*/
public:
    static int count;
    PointArray points;

    Polygon(const Point points[], const int size) : points(PointArray(points, size)) {
        ++this->count;
    }

    Polygon(const PointArray &points) : points(points) {
        ++this->count;
    }

    ~Polygon() {
        --this->count;
    }

    virtual double area() const = 0;

    int getNumPolygons() const;

    int getNumSides() const;

    const PointArray *const getPoints() const;
};

Point constructorPoints[4];

Point *updateConstructorPoints(const Point &p1, const Point &p2, const Point &p3, const Point &p4 = Point(0, 0)) {
    constructorPoints[0] = p1;
    constructorPoints[1] = p2;
    constructorPoints[2] = p3;
    constructorPoints[3] = p4;
    return constructorPoints;
}

class Rectangle : public Polygon {
public:
    Rectangle(const Point lowerLeft, const Point upperRight)
            : Polygon(updateConstructorPoints(lowerLeft, Point(upperRight.getX(), lowerLeft.getY()), upperRight, Point(lowerLeft.getX(), upperRight.getY())), 4) {
    }

    Rectangle(const int x, const int y, const int a, const int b)
            : Polygon(updateConstructorPoints(Point(x, y), Point(a, y), Point(a, b), Point(x, b)), 4) {
    }

    double area() const;
};

class Triangle : public Polygon {
public:
    Triangle(const Point first, const Point second, const Point third) : Polygon(updateConstructorPoints(first, second, third), 3) {}
    double area() const;
};