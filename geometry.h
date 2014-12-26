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
    const PointArray * const getPoints() const;
};
