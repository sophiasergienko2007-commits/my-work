#include <iostream>
#include <limits>
#include <algorithm>
// тип елеметів
using TypeOfElement_t = int;

// структура бінарного дерева
struct Tree_t
{
    TypeOfElement_t data;
    Tree_t *left;
    Tree_t *right;

    // конструктор
    Tree_t(TypeOfElement_t val, Tree_t *l = nullptr, Tree_t *r = nullptr)
        : data(val), left(l), right(r) {}
};

// рекурсивна функція
TypeOfElement_t find_min_element_recursive(Tree_t *root)
{
    if (root == nullptr)
    {
        return std::numeric_limits<TypeOfElement_t>::max(); // повернення максимально можливого значення для int
    }
    // знаходження мінімального елемента в лівому та правому піддереві
    TypeOfElement_t min_left = find_min_element_recursive(root->left);
    TypeOfElement_t min_right = find_min_element_recursive(root->right);

    return std::min({root->data, min_left, min_right});
}

int main()
{
    // створення бінарного дерева
    //  2 рівень
    Tree_t *node3 = new Tree_t(3);
    Tree_t *node9_b = new Tree_t(9);
    Tree_t *node5 = new Tree_t(5);
    Tree_t *node7 = new Tree_t(7);
    // 1 рівень
    Tree_t *node8 = new Tree_t(8, node3, node9_b);
    Tree_t *node9_a = new Tree_t(9, node5, node7);
    // корінь
    Tree_t *root = new Tree_t(11, node8, node9_a);

    TypeOfElement_t min_val = find_min_element_recursive(root);

    std::cout << "Найменший елемент у дереві: " << min_val << std::endl;

    return 0;
}