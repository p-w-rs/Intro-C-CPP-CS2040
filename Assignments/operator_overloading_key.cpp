#include <iostream>
#include <vector>

class Shape {
 public:
  virtual float area() const = 0;
  virtual float perimeter() const = 0;

  bool operator>(const Shape& other) { return area() > other.area(); }
  bool operator<(const Shape& other) { return area() < other.area(); }
  bool operator==(const Shape& other) { return area() == other.area(); }
};

class Rectangle : public Shape {
 private:
  float width;
  float height;

 public:
  Rectangle(float w, float h) : width(w), height(h) {}

  float area() const override { return width * height; }

  float perimeter() const override { return 2 * (width + height); }

  Rectangle operator+(const Rectangle& other) {
    return Rectangle(width + other.width, height + other.height);
  }

  Rectangle operator-(const Rectangle& other) {
    return Rectangle(width - other.width, height - other.height);
  }
};

class Square : public Shape {
 private:
  float side;

 public:
  Square(float s) : side(s) {}

  float area() const override { return side * side; }

  float perimeter() const override { return 4 * side; }

  Square operator+(const Square& other) { return Square(side + other.side); }

  Square operator-(const Square& other) { return Square(side - other.side); }
};

class Circle : public Shape {
 private:
  float radius;

 public:
  Circle(float r) : radius(r) {}

  float area() const override { return 3.14 * radius * radius; }

  float perimeter() const override { return 2 * 3.14 * radius; }

  Circle operator+(const Circle& other) {
    return Circle(radius + other.radius);
  }

  Circle operator-(const Circle& other) {
    return Circle(radius - other.radius);
  }
};

class ShapeCollection {
 private:
  std::vector<Shape*> shapes;

 public:
  ShapeCollection() {}

  void addShape(Shape* s) { shapes.push_back(s); }

  void printAreas() {
    std::cout << "Areas:" << std::endl;
    for (Shape* s : shapes) {
      std::cout << s->area() << std::endl;
    }
  }

  void printPerimeters() {
    std::cout << "Perimeters:" << std::endl;
    for (Shape* s : shapes) {
      std::cout << s->perimeter() << std::endl;
    }
  }

  void sort() {
    std::sort(shapes.begin(), shapes.end(),
              [](Shape* s1, Shape* s2) { return *s1 < *s2; });
  }
};

int main() {
  ShapeCollection collection;
  auto c1 = Circle(10) + Circle(10) - Circle(10);
  auto r1 = Rectangle(31.4, 10) + Rectangle(31.4, 10) - Rectangle(31.4, 10);
  collection.addShape(&c1);
  collection.addShape(new Square(5));
  collection.addShape(&r1);
  collection.addShape(new Rectangle(3, 4));
  collection.addShape(new Rectangle(5, 5));
  collection.addShape(new Circle(2.5));

  collection.sort();  // sort the shapes
  collection.printAreas();
  collection.printPerimeters();

  return 0;
}
