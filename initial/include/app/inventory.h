#ifndef INVENTORY_MANAGER_H
#define INVENTORY_MANAGER_H

#include "list/XArrayList.h"
#include "list/DLinkedList.h"
#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

// -------------------- List1D --------------------
template <typename T>
class List1D
{
private:
    IList<T> *pList;

public:
    List1D();
    List1D(int num_elements);
    List1D(const T *array, int num_elements);
    List1D(const List1D<T> &other);
    virtual ~List1D();

    int size() const;
    T get(int index) const;
    void set(int index, T value);
    void add(const T &value);
    string toString() const;
    // define in the class to avoid warning
    friend ostream &operator<<(ostream &os, const List1D<T> &list) {
        return os << list.toString();
    }
};

// -------------------- List2D --------------------
template <typename T>
class List2D
{
private:
    IList<IList<T> *> *pMatrix;

public:
    List2D();
    List2D(List1D<T> *array, int num_rows);
    List2D(const List2D<T> &other);
    virtual ~List2D();

    int rows() const;
    void setRow(int rowIndex, const List1D<T> &row);
    T get(int rowIndex, int colIndex) const;
    List1D<T> getRow(int rowIndex) const;
    string toString() const;
    // define in the class to avoid warning
    friend ostream &operator<<(ostream &os, const List2D<T> &matrix) {
        return os << matrix.toString();
    }
};

struct InventoryAttribute
{
    string name;
    double value;
    InventoryAttribute(const string &name, double value) : name(name), value(value) {}
    string toString() const { return name + ": " + to_string(value); }
};

// -------------------- InventoryManager --------------------
class InventoryManager
{
private:
    List2D<InventoryAttribute> attributesMatrix;
    List1D<string> productNames;
    List1D<int> quantities;

public:
    InventoryManager();
    InventoryManager(const List2D<InventoryAttribute> &matrix,
                     const List1D<string> &names,
                     const List1D<int> &quantities);
    InventoryManager(const InventoryManager &other);

    int size() const;
    List1D<InventoryAttribute> getProductAttributes(int index) const;
    string getProductName(int index) const;
    int getProductQuantity(int index) const;
    void updateQuantity(int index, int newQuantity);
    void addProduct(const List1D<InventoryAttribute> &attributes, const string &name, int quantity);
    void removeProduct(int index);

    List1D<string> query(int attributeName, const double &minValue,
                         const double &maxValue, int minQuantity, bool ascending) const;

    void removeDuplicates();

    static InventoryManager merge(const InventoryManager &inv1,
                                  const InventoryManager &inv2);

    void split(InventoryManager &section1,
               InventoryManager &section2,
               double ratio) const;

    List2D<InventoryAttribute> getAttributesMatrix() const;
    List1D<string> getProductNames() const;
    List1D<int> getQuantities() const;
    string toString() const;
};

// -------------------- List1D Method Definitions --------------------
template <typename T>
List1D<T>::List1D()
{
    // TODO
    this->pList = new XArrayList<T>();
}

template <typename T>
List1D<T>::List1D(int num_elements)
{
    // TODO
    this->pList = new XArrayList<T>(nullptr, nullptr, num_elements);
}

template <typename T>
List1D<T>::List1D(const T *array, int num_elements)
{
    // TODO
    this->pList = new XArrayList<T>(nullptr, nullptr, num_elements);
    for (int i = 0; i < num_elements; i++) {
        this->pList->add(array[i]);
    }
}

template <typename T>
List1D<T>::List1D(const List1D<T> &other)
{
    // TODO
    this->pList = new XArrayList<T>();
    for (int i = 0; i < other.pList->size(); i++) {
        this->pList->add(other.pList->get(i));
    }
}

template <typename T>
List1D<T>::~List1D()
{
    // TODO
    if (this->pList != nullptr) {
        delete this->pList;
    }
}

template <typename T>
int List1D<T>::size() const
{
    // TODO
    return this->pList->size();
}

template <typename T>
T List1D<T>::get(int index) const
{
    // TODO
    // check Index already implemented in get itself
    return this->pList->get(index);
}

template <typename T>
void List1D<T>::set(int index, T value)
{
    // TODO
    if (index < 0 || index >= this->pList->size()) {
        throw out_of_range("Index is out of range!");
    }
    
    // get() returns a reference so I can directly set the value
    this->pList->get(index) = value;
}

template <typename T>
void List1D<T>::add(const T &value)
{
    // TODO
    this->pList->add(value);
}

template <typename T>
string List1D<T>::toString() const
{
    // TODO
    return this->pList->toString();
}

// template <typename T>
// ostream &operator<<(ostream &os, const List1D<T> &list)
// {
//     // TODO
//     return os << list.toString();
// }

// -------------------- List2D Method Definitions --------------------
template <typename T>
List2D<T>::List2D()
{
    // TODO
    this->pMatrix = new DLinkedList<IList<T> *>();
}

template <typename T>
List2D<T>::List2D(List1D<T> *array, int num_rows)
{
    // TODO
    this->pMatrix = new DLinkedList<IList<T> *>();

    // Copy each row into the matrix
    for (int i = 0; i < num_rows; i++) {
        // create a copy of each row to ensure I have my own data
        IList<T> *rowCopy = new XArrayList<T>();
        for (int j = 0; j < array[i].size(); j++) {
            rowCopy->add(array[i].get(j));
        }

        this->pMatrix->add(rowCopy);
    }
}

template <typename T>
List2D<T>::List2D(const List2D<T> &other)
{
    // TODO
    // deep copy
    this->pMatrix = new DLinkedList<IList<T> *>();

    // Copy each row into the matrix
    for (int i = 0; i < other.rows(); i++) {
        IList<T> *rowCopy = new XArrayList<T>();

        List1D<T> originalRow = other.getRow(i);
        for (int j = 0; j < originalRow.size(); j++) {
            rowCopy->add(originalRow.get(j));
        }

        this->pMatrix->add(rowCopy);
    }
}

template <typename T>
List2D<T>::~List2D()
{
    // TODO
    // clean all the reos and then delete the matrix
    if (this->pMatrix != nullptr) {
        for (int i = 0; i < this->pMatrix->size(); i++) {
            delete this->pMatrix->get(i);
        }
        delete this->pMatrix;
    }
}

template <typename T>
int List2D<T>::rows() const
{
    // TODO
    return this->pMatrix->size();
}

template <typename T>
void List2D<T>::setRow(int rowIndex, const List1D<T> &row)
{
    // TODO
    if (rowIndex < 0 || rowIndex >= this->rows()) {
        throw out_of_range("Row Index is out of range!");
    }

    // delete the old row
    delete this->pMatrix->get(rowIndex);

    // create a new row and copy the data
    IList<T> *newRow = new XArrayList<T>();
    for (int i = 0; i < row.size(); i++) {
        newRow->add(row.get(i));
    }

    // because set returns a reference, I can directly set the new row
    this->pMatrix->set(rowIndex) = newRow;
}

template <typename T>
T List2D<T>::get(int rowIndex, int colIndex) const
{
    // TODO
    if (rowIndex < 0 || rowIndex >= this->rows()) {
        throw out_of_range("Row Index is out of range!");
    }
    if (colIndex < 0 || colIndex >= this->pMatrix->get(rowIndex)->size()) {
        throw out_of_range("Column Index is out of range!");
    }

    return this->pMatrix->get(rowIndex)->get(colIndex);
}

template <typename T>
List1D<T> List2D<T>::getRow(int rowIndex) const
{
    // TODO
    if (rowIndex < 0 || rowIndex >= this->rows()) {
        throw out_of_range("Row Index is out of range!");
    }

    IList<T> *row = this->pMatrix->get(rowIndex);

    List1D<T> rowList;
    for (int i = 0; i < row->size(); i++) {
        rowList.add(row->get(i));
    }

    return rowList;
}

template <typename T>
string List2D<T>::toString() const
{
    // TODO
    stringstream ss;
    ss << "[";

    // for each row in the matrix
    for (int i = 0; i < this->rows(); i++) {
        // add separator between rows
        if (i > 0) {
            ss << ", ";
        }

        IList<T> *row = this->pMatrix->get(i);

        // format the row
        ss << "[";
        for (int j = 0; j < row->size(); j++) {
            // add separator between elements
            if (j > 0) {
                ss << ", ";
            }

            ss << row->get(j);
        }
        ss << "]";
    }

    ss << "]";
    return ss.str();
}

// template <typename T>
// ostream &operator<<(ostream &os, const List2D<T> &matrix)
// {
//     // TODO
//     return os << matrix.toString();
// }

// -------------------- InventoryManager Method Definitions --------------------
InventoryManager::InventoryManager()
{
    // TODO
}

InventoryManager::InventoryManager(const List2D<InventoryAttribute> &matrix,
                                   const List1D<string> &names,
                                   const List1D<int> &quantities)
{
    // TODO
}

InventoryManager::InventoryManager(const InventoryManager &other)
{
    // TODO
}

int InventoryManager::size() const
{
    // TODO
    return 0;
}

List1D<InventoryAttribute> InventoryManager::getProductAttributes(int index) const
{
    // TODO
}

string InventoryManager::getProductName(int index) const
{
    // TODO
    return "";
}

int InventoryManager::getProductQuantity(int index) const
{
    // TODO
    return 0;
}

void InventoryManager::updateQuantity(int index, int newQuantity)
{
    // TODO
}

void InventoryManager::addProduct(const List1D<InventoryAttribute> &attributes, const string &name, int quantity)
{
    // TODO
}

void InventoryManager::removeProduct(int index)
{
    // TODO
}

List1D<string> InventoryManager::query(int attributeName, const double &minValue,
                                       const double &maxValue, int minQuantity, bool ascending) const
{
    // TODO
    // placeholder
    return List1D<string>();
}

void InventoryManager::removeDuplicates()
{
    // TODO
}

InventoryManager InventoryManager::merge(const InventoryManager &inv1,
                                         const InventoryManager &inv2)
{
    // TODO
}

void InventoryManager::split(InventoryManager &section1,
                             InventoryManager &section2,
                             double ratio) const
{
    // TODO
}

List2D<InventoryAttribute> InventoryManager::getAttributesMatrix() const
{
    // TODO
    return List2D<InventoryAttribute>();
}

List1D<string> InventoryManager::getProductNames() const
{
    // TODO
    return List1D<string>();
}

List1D<int> InventoryManager::getQuantities() const
{
    // TODO
    return List1D<int>();
}

string InventoryManager::toString() const
{
    // TODO
    return "";
}

#endif /* INVENTORY_MANAGER_H */
