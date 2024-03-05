#include <iostream>
#include <vector>

class Shape {
 public:
  virtual float area() = 0;
  virtual float perimeter() = 0;
};

class Rectangle : public Shape {
 private:
  float width;
  float height;

 public:
  Rectangle(float w, float h) : width(w), height(h) {}

  float area() override { return width * height; }

  float perimeter() override { return 2 * (width + height); }
};

class Square : public Shape {
 private:
  float side;

 public:
  Square(float s) : side(s) {}

  float area() override { return side * side; }

  float perimeter() override { return 4 * side; }
};

class Circle : public Shape {
 private:
  float radius;

 public:
  Circle(float r) : radius(r) {}

  float area() override { return 3.14 * radius * radius; }

  float perimeter() override { return 2 * 3.14 * radius; }
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
};

int main() {
  ShapeCollection collection;
  collection.addShape(new Square(5));
  collection.addShape(new Rectangle(3, 4));
  collection.addShape(new Circle(2.5));

  collection.printAreas();
  collection.printPerimeters();

  return 0;
}
