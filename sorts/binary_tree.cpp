#include <iostream>
#include <stdexcept>

template<typename T>
struct Node
{
    public:
        Node(T value)
        : m_value(value) {}

        Node *parentNode;
        Node *childNodes[2] = {nullptr};

        bool isAnyChildren()
        {
            return ((nullptr != childNodes[0])) || (nullptr != childNodes[1]);
        }

        void appendChild(Node child)
        {
            if (child.getValue() >= this->getValue() &&
                !this->isGreaterChildExists())
            {
                delete childNodes[1];
                childNodes = nullptr;

                childNodes[1] = &child;
            }
            else if (child.getValue() < this->getValue() &&
                     !this->isLowerChildExists())
            {
                delete childNodes[0];
                childNodes = nullptr;

                childNodes[0] = &child;
            }
            else
            {
                throw std::exception();
            }
        }

        bool isGreaterChildExist()
        {
            return nullptr != childNodes[1];
        }

        bool isLowerChildExist()
        {
            return nullptr != childNodes[0];
        }

        T getValue()
        {
            return m_value;
        }
    
    private:
        T m_value;
};


class BinaryTree
{
    public:

};

int main()
{
    Node<int> node(3);
    std::cout << node.isAnyChildren() << std::endl;
    std::cout << node.isGreaterChildExist() << std::endl;
    std::cout << node.isLowerChildExist() << std::endl;
    std::cout << node.getValue() << std::endl;
    node.appendChild(Node<int>(2));
    std::cout << node.isGreaterChildExist() << std::endl;
    std::cout << node.isLowerChildExist() << std::endl;

    return 0;
}