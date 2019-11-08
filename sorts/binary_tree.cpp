#include <iostream>
#include <stdexcept>
#include <vector>

template<typename ValueType>
struct Node
{
    public:
        Node(ValueType value)
        : m_value(value) {}

        bool isAnyChildren()
        {
            return ((nullptr != childNodes[0])) || (nullptr != childNodes[1]);
        }

        void appendChild(Node &child)
        {
            if (child.getValue() >= this->getValue() &&
                !this->isGreaterChildExist())
            {
                assignChild(child, 1);
            }
            else if (child.getValue() < this->getValue() &&
                     !this->isLowerChildExist())
            {
                assignChild(child, 0);
            }
            else
            {
                throw std::exception();
            }
        }

        void assignChild(Node &child, size_t pos)
        {
            delete childNodes[pos];
            childNodes[pos] = nullptr;

            childNodes[pos] = &child;
        }

        bool isGreaterChildExist()
        {
            return nullptr != childNodes[1];
        }

        bool isLowerChildExist()
        {
            return nullptr != childNodes[0];
        }

        ValueType getValue()
        {
            return m_value;
        }

        void setParent(Node parent)
        {
            parentNode = parent;
        }

        Node* lowerChildAdress()
        {
            return &childNodes[0];
        }

        Node* greaterChildAdress()
        {
            return &childNodes[1];
        }

    private:
        ValueType m_value;

        Node *childNodes[2] = {nullptr};
        Node *parentNode;
};

template<typename DataType>
class BinaryTree
{
    public:
        BinaryTree(Node root)
        : m_root(root) {}

    private:
        Node m_root;
        Node *currentNode;

        std::vector<Node> nodes;
};

int main()
{
    Node<int> node(3);
    std::cout << node.isAnyChildren() << std::endl;
    std::cout << node.isGreaterChildExist() << std::endl;
    std::cout << node.isLowerChildExist() << std::endl;
    std::cout << node.getValue() << std::endl;
    Node<int> lowerChild(2);
    node.appendChild(lowerChild);
    std::cout << node.isGreaterChildExist() << std::endl;
    std::cout << node.isLowerChildExist() << std::endl;

    return 0;
}
