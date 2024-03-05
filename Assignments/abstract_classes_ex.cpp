/*
You are a developer at a company that creates software for a construction firm.
Your team has been tasked with creating a program that can calculate the
areas and perimeters of various shapes used in construction,
such as squares, rectangles, and circles.
The program should allow the user to input the dimensions of the shapes and
display the area and perimeter for each shape.

To accomplish this, your team has decided to create an abstract Shape interface
that will define the functions area and perimeter. The Shape interface will be
inherited by three classes: Rectangle, Square, and Circle, which will implement
the area and perimeter functions for their respective shapes.

Your task is to create a class called ShapeCollection that will allow the user
to store multiple shapes of different types (i.e., Rectangle, Square, and
Circle) in a single collection. The ShapeCollection class should have a function
to add shapes to the collection, and functions to display the areas and
perimeters of all the shapes in the collection.

Write a C++ program that implements the Shape, Rectangle, Square, Circle, and
ShapeCollection classes as described above. Test your program by creating a
ShapeCollection object, adding a Square, Rectangle, and Circle to the
collection, and displaying the areas and perimeters of all the shapes in the
collection.

The output of the program should be:
Areas:
25
12
19.625
Perimeters:
20
14
15.7
*/

/*fill in*/

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
