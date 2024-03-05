#include <iostream>
#include <string>

template <typename T> class Vec
{
  private:
    T *data;   // pointer to the underlying data array
    int _size; // size of the data array

  public:
    Vec(int n) : data(new T[n]), _size(n) // constructor that initializes the data array with a given size
    {
    }
    ~Vec() // destructor that deallocates the data array when the object is destroyed
    {
        delete[] data;
    };

    int size() const // function that returns the size of the data array
    {
        return _size;
    }

    T &operator[](int n) // overload the [] operator to allow for indexing of the data array
    {
        return data[n];
    }

    Vec operator+(
        const Vec &other) const // overload the + operator to allow for element-wise addition of two Vec objects
    {
        Vec result(_size);              // create a new Vec object with the same size as this object
        for (int i = 0; i < _size; i++) // iterate through each element of the data array
        {
            result.data[i] = data[i] + other.data[i]; // add the corresponding elements of this and the other Vec
                                                      // objects and store the result in the new Vec object
        }
        return result; // return the new Vec object
    }

    bool operator==(const Vec &other) const // overload the == operator to check if two Vec objects are equal
    {
        if (_size != other._size) // if the two objects have different sizes, they are not equal
        {
            return false;
        }

        for (int i = 0; i < _size; i++) // iterate through each element of the data array
        {
            if (data[i] != other.data[i]) // if the corresponding elements of this and the other Vec objects are not
                                          // equal, they are not equal
            {
                return false;
            }
        }

        return true; // if all elements are equal, the objects are equal
    }

    Vec(const Vec &v)
        : data(new T[v._size]), _size(v._size) // copy constructor that creates a new Vec object with the same size
                                               // and data array as the given Vec object
    {
        std::copy(v.data, v.data + _size,
                  data); // copy the data from the given Vec object to the new Vec object
    }
    Vec &operator=(const Vec &v) // overload the = operator to allow for assignment of one Vec object to another
    {
        T *newdata = new T[v._size]; // allocate a new data array with the same size as the given IntVec object
        std::copy(v.data, v.data + v._size,
                  newdata); // copy the data from the given IntVec object to the new data array
        delete[] data;      // deallocate the old data array
        data = newdata;     // assign the new data array to the data member of this object
        _size = v._size;    // update the size member of this object
        return *this;       // return a reference to this object          // return a reference to this object
    }
};

int main()
{
    Vec<double> v1(5); // create an IntVec with size 5

    // initialize v1 with some values
    for (int i = 0; i < v1.size(); i++)
    {
        v1[i] = i;
    }

    Vec<double> v2(v1); // create a copy of v1 using the copy constructor

    // modify v2
    for (int i = 0; i < v2.size(); i++)
    {
        v2[i] *= 2;
    }

    for (int i = 0; i < v1.size(); i++)
    {
        std::cout << "v1[" << i << "] = " << v1[i] << ", v2[" << i << "] = " << v2[i] << std::endl;
    }

    v1 = v2; // use the assignment operator to copy v2 back into v1
    // print out v1 and v2 to verify that they have the same values
    for (int i = 0; i < v1.size(); i++)
    {
        std::cout << "v1[" << i << "] = " << v1[i] << ", v2[" << i << "] = " << v2[i] << std::endl;
    }

    if (v1 == v2)
    {
        std::cout << "V1 is equal to V2" << std::endl;
    }

    Vec<double> v3 = v1 + v2;
    for (int i = 0; i < v1.size(); i++)
    {
        std::cout << "v1[" << i << "] = " << v1[i] << ", v2[" << i << "] = " << v2[i] << ", v3[" << i << "] = " << v3[i]
                  << std::endl;
    }

    Vec<std::string> v4(2);
    v4[0] = "Hello, ";
    v4[1] = "World!";

    std::cout << v4[0] << v4[1] << std::endl;

    return 0;
}
