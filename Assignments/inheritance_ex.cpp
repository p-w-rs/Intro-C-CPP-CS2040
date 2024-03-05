/*
Write a program that creates four animals: a generic animal, a dog, a cat, and a
bird. The program should use inheritance to implement the specific types of
animals, and each animal should have a name and a sound that it makes. Use a
loop to print out the name and sound of each animal.

Note that you will have to may saysWhat a virtual function, which we will
discuss next time.

The output of the program should print:
???? says ????
Fido says Woof!
Felix says Meow!
Tweety says Chirp!
*/

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
