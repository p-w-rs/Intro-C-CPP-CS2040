#include <iostream>

class IntVec
{
  private:
    int *data; // pointer to the underlying data array
    int _size; // size of the data array

  public:
    IntVec(int n) : data(new int[n]), _size(n) // constructor that initializes the data array with a given size
    {
    }
    ~IntVec() // destructor that deallocates the data array when the object is destroyed
    {
        delete[] data;
    };

    int size() const // function that returns the size of the data array
    {
        return _size;
    }

    int &operator[](int n) // overload the [] operator to allow for indexing of the data array
    {
        return data[n];
    }

    IntVec operator+(
        const IntVec &other) const // overload the + operator to allow for element-wise addition of two IntVec objects
    {
        IntVec result(_size);           // create a new IntVec object with the same size as this object
        for (int i = 0; i < _size; i++) // iterate through each element of the data array
        {
            result.data[i] = data[i] + other.data[i]; // add the corresponding elements of this and the other IntVec
                                                      // objects and store the result in the new IntVec object
        }
        return result; // return the new IntVec object
    }

    bool operator==(const IntVec &other) const // overload the == operator to check if two IntVec objects are equal
    {
        if (_size != other._size) // if the two objects have different sizes, they are not equal
        {
            return false;
        }

        for (int i = 0; i < _size; i++) // iterate through each element of the data array
        {
            if (data[i] != other.data[i]) // if the corresponding elements of this and the other IntVec objects are not
                                          // equal, they are not equal
            {
                return false;
            }
        }

        return true; // if all elements are equal, the objects are equal
    }

    IntVec(const IntVec &v)
        : data(new int[v._size]), _size(v._size) // copy constructor that creates a new IntVec object with the same size
                                                 // and data array as the given IntVec object
    {
        std::copy(v.data, v.data + _size, data); // copy the data from the given IntVec object to the new IntVec object
    }
    IntVec &operator=(
        const IntVec &v) // overload the = operator to allow for assignment of one IntVec object to another
    {
        int *newdata = new int[v._size]; // allocate a new data array with the same size as the given IntVec object
        std::copy(v.data, v.data + v._size,
                  newdata); // copy the data from the given IntVec object to the new data array
        delete[] data;      // deallocate the old data array
        data = newdata;     // assign the new data array to the data member of this object
        _size = v._size;    // update the size member of this object
        return *this;       // return a reference to this object
    }
};

int main()
{
    IntVec v1(5); // create an IntVec with size 5

    // initialize v1 with some values
    for (int i = 0; i < v1.size(); i++)
    {
        v1[i] = i;
    }

    IntVec v2(v1); // create a copy of v1 using the copy constructor

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

    IntVec v3 = v1 + v2;
    for (int i = 0; i < v1.size(); i++)
    {
        std::cout << "v1[" << i << "] = " << v1[i] << ", v2[" << i << "] = " << v2[i] << ", v3[" << i << "] = " << v3[i]
                  << std::endl;
    }

    return 0;
}
