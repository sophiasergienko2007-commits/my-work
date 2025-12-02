#include <iostream>
#include <limits>
#include <algorithm>
#include <stack>
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
//16. Оголосіть функцію, яка знаходить величину найменшого елемента непорожнього дерева Т.
// рекурсивна функція для цього завдання
TypeOfElement_t find_min_element_recursive(Tree_t *root)
{
    if (root == nullptr)
    {
        return INT_MAX; // повернення максимально можливого значення для int
    }
    // знаходження мінімального елемента в лівому та правому піддереві
    TypeOfElement_t min_left = find_min_element_recursive(root->left);
    TypeOfElement_t min_right = find_min_element_recursive(root->right);

    return std::min({root->data, min_left, min_right});
}
//35. Оголосіть функцію, яка записує в потік виведення всі ключі дерева пошуку в спадному порядку.
// ітеративна функція для цього завдання
void print_descending_iterative(Tree_t *root)
{
    if (root == nullptr)
    {
        return;
    }
    std::stack<Tree_t *> subtrees;
    Tree_t *current = root;

    while (current != nullptr || !subtrees.empty())
    {
        // рух до найбільшого елемента
        while (current != nullptr)
        {
            subtrees.push(current);
            current = current->right;
        }
        // обробка кореня
        current = subtrees.top();
        subtrees.pop();
        std::cout << current->data << " ";
        // рух до лівого піддерева
        current = current->left;
    }
}

int main()
{
    // створення бінарного дерева
    //  2 рівень
    Tree_t *node3 = new Tree_t(5);
    Tree_t *node9_b = new Tree_t(10);
    Tree_t *node5 = new Tree_t(20);
    Tree_t *node7 = new Tree_t(35);
    // 1 рівень
    Tree_t *node8 = new Tree_t(7, node3, node9_b);
    Tree_t *node9_a = new Tree_t(22, node5, node7);
    // корінь
    Tree_t *root = new Tree_t(15, node8, node9_a);

    TypeOfElement_t min_val = find_min_element_recursive(root);
    std::cout << "1.Найменший елемент у дереві: " << min_val << std::endl;

    std::cout << "2.Ключі в спадному порядку: ";
    print_descending_iterative(root);
    std::cout << std::endl;
    

    return 0;
}