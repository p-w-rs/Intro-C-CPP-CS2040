/*
Modify the code from your abstract_classes exercise or start from the
provided solution.

You need to add the following functionality:
1. overlaod the <,>,== operators, they should compare Shapes based on area
2. overload +,- operators they should add or subtract the individual compements
of a Shape

Make sure you think about if an operator should be overloaded in the base or
derived class of a Shape.

The output of the program should be:
Areas:
12
19.625
25
25
314
314
Perimeters:
14
15.7
20
20
62.8
82.8
*/

#include <iostream>
#include <vector>

class Shape {
  /*fill in*/
};

class Rectangle : public Shape {
  /*fill in*/
};

class Square : public Shape {
  /*fill in*/
};

class Circle : public Shape {
  /*fill in*/
};

class ShapeCollection {
 private:
  std::vector</*fill in*/> shapes;

 public:
  ShapeCollection() {}

  void addShape(/*fill in*/) { /*fill in*/
  }

  void printAreas() { /*fill in*/
  }

  void printPerimeters() { /*fill in*/
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
