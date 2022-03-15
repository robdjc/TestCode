#include <iostream>
#include <cstring>

// just for testing. not a good example of a string class.
class MyString
{
public:
    MyString() = default;

    MyString(const char * str) {
        std::cout << "MyString - ctor" << std::endl;
        m_size = strlen(str);
        m_data = new char[m_size + 1];
        m_data[m_size] = 0;
        memcpy(m_data, str, m_size);
    }

    MyString(const MyString& rhs) {
        std::cout << "MyString - copy ctor" << std::endl;
        m_size = rhs.m_size;

        // allocates new memory on the heap during a copy
        // deep copy
        m_data = new char[m_size + 1];
        m_data[m_size] = 0;
        memcpy(m_data, rhs.m_data, m_size);
    }

    // move constructor with an rvalue reference
    MyString( MyString&& rhs) noexcept {
        std::cout << "MyString - move ctor" << std::endl;
        m_size = rhs.m_size;

        // reassign, don't need to reallocate new memory
        // shallow copy
        m_data = rhs.m_data;

        // set the old one to empty/hollow object
        // a delete of nullptr is safe
        rhs.m_data = nullptr;
        rhs.m_size = 0;
    }


    ~MyString() {
        std::cout << "MyString - dtor" << std::endl;
        delete m_data;
    }

    const char * GetData() {
        return m_data;
    }

private:
    char* m_data;
    uint32_t m_size;
};

class Entity {
public:
    Entity(const MyString& name) 
        : m_name(name) // this does a copy
    {
        std::cout << "Entity - ctor" << std::endl;
    }

    Entity(MyString&& name) noexcept 
        : m_name(std::move(name)) 
        // m_name(name) would cause a copy
        // std::move is a static cast to MyString&& rvalue
        // causes move instead of copy, with one allocation instead of two
    {
        std::cout << "Entity - ctor" << std::endl;
    }

    ~Entity() {
        std::cout << "Entity - dtor" << std::endl;
    }

    void PrintName() {
        std::cout << "Entity name: " << m_name.GetData() << std::endl;
    }

private:
    MyString m_name;
};

int main()
{
    Entity e("Robert"); // implicit MyString("Robert")
    // "Robert" is a temporary rvalue
    // MyString("Robert") string first created in the scope of the main function

    e.PrintName();

    return 0;
}
