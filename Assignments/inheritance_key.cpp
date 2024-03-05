#include <iostream>
#include <string>

using namespace std;

const string UNKNOWN = "????";

class Animal {
  string name;

 public:
  Animal(string name) : name(name) {}
  Animal() : name(UNKNOWN) {}
  string getName() const { return name; }
  virtual string saysWhat() const { return UNKNOWN; }
};

class Dog : public Animal {
 public:
  Dog(string name) : Animal(name) {}
  string saysWhat() const { return "Woof!"; }
};

class Cat : public Animal {
 public:
  Cat(string name) : Animal(name) {}
  string saysWhat() const { return "Meow!"; }
};

class Bird : public Animal {
 public:
  Bird(string name) : Animal(name) {}
  string saysWhat() const { return "Chirp!"; }
};

int main() {
  Animal *animals[4];
  animals[0] = new Animal();
  animals[1] = new Dog("Fido");
  animals[2] = new Cat("Felix");
  animals[3] = new Bird("Tweety");

  for (int i = 0; i < 4; i++) {
    cout << animals[i]->getName() << " says " << animals[i]->saysWhat() << endl;
  }

  return 0;
}
