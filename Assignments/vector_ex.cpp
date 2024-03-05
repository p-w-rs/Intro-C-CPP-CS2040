#include <iostream>

class Vector
{
    /*
    Make a generic vector class that can hold any data type:

    It should have the following functionality:
    size() returns the current number of elements in the vector
    capacity() returns the total size of the allocated slots
    push_back() adds an elements to the vector increasing size (and maybe capacity)
    pop_back() removes the last elements and decreases size but not capacity
    resize() sets the capacity to the given value

    output should be:
    v1 size: 0, capacity: 0
    v2 size: 5, capacity: 5
    v2[0] = 0
    v2[1] = 1
    v2[2] = 2
    v2[3] = 3
    v2[4] = 4
    v3 size: 5, capacity: 5
    v3[0] = 0
    v3[1] = 1
    v3[2] = 2
    v3[3] = 3
    v3[4] = 4
    v4 size: 5, capacity: 5
    v4[0] = 0
    v4[1] = 1
    v4[2] = 2
    v4[3] = 3
    v4[4] = 4
    v5 size: 10, capacity: 16
    v5[0] = 0
    v5[1] = 1
    v5[2] = 2
    v5[3] = 3
    v5[4] = 4
    v5[5] = 5
    v5[6] = 6
    v5[7] = 7
    v5[8] = 8
    v5[9] = 9
    v5 size after pop_back: 9
    v5[0] = 0
    v5[1] = 1
    v5[2] = 2
    v5[3] = 3
    v5[4] = 4
    v5[5] = 5
    v5[6] = 6
    v5[7] = 7
    v5[8] = 8
    v5 size after resize(15): 15, capacity: 16
    v5[0] = 0
    v5[1] = 1
    v5[2] = 2
    v5[3] = 3
    v5[4] = 4
    v5[5] = 5
    v5[6] = 6
    v5[7] = 7
    v5[8] = 8
    v5[9] = 0
    v5[10] = 0
    v5[11] = 0
    v5[12] = 0
    v5[13] = 0
    v5[14] = 0
    */
};

int main()
{
    // Test default constructor
    Vector<int> v1;
    std::cout << "v1 size: " << v1.size() << ", capacity: " << v1.capacity() << std::endl;

    // Test constructor with initial size
    Vector<int> v2(5);
    std::cout << "v2 size: " << v2.size() << ", capacity: " << v2.capacity() << std::endl;
    for (int i = 0; i < v2.size(); ++i)
    {
        v2[i] = i;
    }
    for (int i = 0; i < v2.size(); ++i)
    {
        std::cout << "v2[" << i << "] = " << v2[i] << std::endl;
    }

    // Test copy constructor
    Vector<int> v3(v2);
    std::cout << "v3 size: " << v3.size() << ", capacity: " << v3.capacity() << std::endl;
    for (int i = 0; i < v3.size(); ++i)
    {
        std::cout << "v3[" << i << "] = " << v3[i] << std::endl;
    }

    // Test copy assignment operator
    Vector<int> v4;
    v4 = v2;
    std::cout << "v4 size: " << v4.size() << ", capacity: " << v4.capacity() << std::endl;
    for (int i = 0; i < v4.size(); ++i)
    {
        std::cout << "v4[" << i << "] = " << v4[i] << std::endl;
    }

    // Test push_back
    Vector<int> v5;
    for (int i = 0; i < 10; ++i)
    {
        v5.push_back(i);
    }
    std::cout << "v5 size: " << v5.size() << ", capacity: " << v5.capacity() << std::endl;
    for (int i = 0; i < v5.size(); ++i)
    {
        std::cout << "v5[" << i << "] = " << v5[i] << std::endl;
    }

    // Test pop_back
    v5.pop_back();
    std::cout << "v5 size after pop_back: " << v5.size() << std::endl;
    for (int i = 0; i < v5.size(); ++i)
    {
        std::cout << "v5[" << i << "] = " << v5[i] << std::endl;
    }

    // Test resize
    v5.resize(15);
    std::cout << "v5 size after resize(15): " << v5.size() << ", capacity: " << v5.capacity() << std::endl;
    for (int i = 0; i < v5.size(); ++i)
    {
        std::cout << "v5[" << i << "] = " << v5[i] << std::endl;
    }

    return 0;
}
