#include <iostream>

template <typename T> class Vector
{
  private:
    size_t m_size;
    size_t m_capacity;
    T *m_data;

  public:
    // Default constructor
    Vector() : m_size(0), m_capacity(0), m_data(nullptr)
    {
    }

    // Constructor with initial size
    explicit Vector(size_t size) : m_size(size), m_capacity(size), m_data(new T[size])
    {
    }

    // Copy constructor
    Vector(const Vector &other) : m_size(other.m_size), m_capacity(other.m_capacity), m_data(new T[other.m_capacity])
    {
        for (size_t i = 0; i < m_size; ++i)
        {
            m_data[i] = other.m_data[i];
        }
    }

    // Copy assignment operator
    Vector &operator=(const Vector &other)
    {
        if (this != &other)
        {
            Vector tmp(other);
            std::swap(m_size, tmp.m_size);
            std::swap(m_capacity, tmp.m_capacity);
            std::swap(m_data, tmp.m_data);
        }
        return *this;
    }

    // Destructor
    ~Vector()
    {
        delete[] m_data;
    }

    // Get the size of the vector
    size_t size() const
    {
        return m_size;
    }

    // Get the capacity of the vector
    size_t capacity() const
    {
        return m_capacity;
    }

    // Add an element to the back of the vector
    void push_back(const T &value)
    {
        if (m_size == m_capacity)
        {
            reserve(m_capacity == 0 ? 1 : m_capacity * 2);
        }
        m_data[m_size++] = value;
    }

    // Remove the last element from the vector
    void pop_back()
    {
        if (m_size > 0)
        {
            --m_size;
        }
    }

    // Get the element at the given index
    T &operator[](size_t index)
    {
        return m_data[index];
    }

    // Get the element at the given index (const version)
    const T &operator[](size_t index) const
    {
        return m_data[index];
    }

    // Reserve memory for at least the given capacity
    void reserve(size_t capacity)
    {
        if (capacity > m_capacity)
        {
            T *newData = new T[capacity];
            for (size_t i = 0; i < m_size; ++i)
            {
                newData[i] = m_data[i];
            }
            delete[] m_data;
            m_data = newData;
            m_capacity = capacity;
        }
    }

    // Resize the vector to the given size
    void resize(size_t size)
    {
        reserve(size);
        for (size_t i = m_size; i < size; ++i)
        {
            m_data[i] = T();
        }
        m_size = size;
    }
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
