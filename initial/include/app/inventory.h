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
    // = operator (just for testing so i define in here)
    List1D<T>& operator=(const List1D<T>& other) {
        if (this != &other) {
            // Free existing data
            if (pList != nullptr) {
                delete pList;
            }
            // Re-create and copy elements
            pList = new XArrayList<T>();
            for (int i = 0; i < other.size(); i++) {
                pList->add(other.get(i));
            }
        }
        return *this;
    }
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
    // Add this inside class List2D<T>:
    List2D<T>& operator=(const List2D<T>& other) {
        if (this != &other) {
            // Free existing data
            if (pMatrix != nullptr) {
                for (int i = 0; i < pMatrix->size(); i++) {
                    delete pMatrix->get(i);
                }
                delete pMatrix;
            }
            // Re-create and copy elements
            pMatrix = new DLinkedList<IList<T>*>();
            for (int i = 0; i < other.rows(); i++) {
                IList<T>* newRow = new XArrayList<T>();
                List1D<T> row = other.getRow(i);
                for (int j = 0; j < row.size(); j++) {
                    newRow->add(row.get(j));
                }
                pMatrix->add(newRow);
            }
        }
        return *this;
    }
    // define in the class to avoid warning
    friend ostream &operator<<(ostream &os, const List2D<T> &matrix) {
        return os << matrix.toString();
    }
};

// original version
// struct InventoryAttribute
// {
//     string name;
//     double value;
//     InventoryAttribute(const string &name, double value) : name(name), value(value) {}
//     string toString() const { return name + ": " + to_string(value); }
// };

// My version
struct InventoryAttribute
{
    string name;
    double value;

    // Add default constructor
    InventoryAttribute() : name(""), value(0.0) {}
    
    // Existing constructor
    InventoryAttribute(const string &name, double value) : name(name), value(value) {}
    
    // Add toString method
    string toString() const { return name + ": " + to_string(value); }
    
    // Define the equality operator
    bool operator==(const InventoryAttribute& other) const {
        return name == other.name && value == other.value;
    }

    // Define the output operator
    friend std::ostream& operator<<(std::ostream& os, const InventoryAttribute& attr) {
        os << attr.name << ": " << attr.value;
        return os;
    }
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

    List1D<string> query(string attributeName, const double &minValue,
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
    // clean all the rows and then delete the matrix
    if (this->pMatrix != nullptr) {
        for (int i = 0; i < this->pMatrix->size(); i++) {
            if (this->pMatrix->get(i) != nullptr) {
                delete this->pMatrix->get(i);
            }
        }
        delete this->pMatrix;
        this->pMatrix = nullptr; // to prevent use after-free
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
    if (rowIndex < 0 || rowIndex > this->rows()) {
        throw out_of_range("Index is out of range!");
    }

    IList<T> *newRow = new XArrayList<T>();
    for (int i = 0; i < row.size(); i++) {
        newRow->add(row.get(i));
    }

    // if a row already exists at the index, replace it
    if (rowIndex < this->rows()) {
        // to avoid memory leak
        delete this->pMatrix->get(rowIndex);
        this->pMatrix->get(rowIndex) = newRow;
    } // case setRow(0, row) when rows() == 0
    else {
        this->pMatrix->add(newRow);
    }
}

template <typename T>
T List2D<T>::get(int rowIndex, int colIndex) const
{
    // TODO
    if (rowIndex < 0 || rowIndex >= this->rows()) {
        throw out_of_range("Index is out of range!");
    }

    IList<T> *row = this->pMatrix->get(rowIndex);

    if (colIndex < 0 || colIndex >= this->pMatrix->get(rowIndex)->size()) {
        throw out_of_range("Index is out of range!");
    }

    return row->get(colIndex);
}

template <typename T>
List1D<T> List2D<T>::getRow(int rowIndex) const
{
    // TODO
    if (rowIndex < 0 || rowIndex >= this->rows()) {
        throw out_of_range("Index is out of range!");
    }
    
    List1D<T> result;
    IList<T> *row = this->pMatrix->get(rowIndex);
    
    for (int i = 0; i < row->size(); i++) {
        result.add(row->get(i));
    }
    
    return result;
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
    // The default constructors of List2D and List1D will be called here
}

InventoryManager::InventoryManager(const List2D<InventoryAttribute> &matrix,
                                   const List1D<string> &names,
                                   const List1D<int> &quantities)
{
    // TODO
    // Do I need to validate the input ?
    
    // Deep copy (because List2D and List1D assignment operators)
    this->attributesMatrix = matrix;
    this->productNames = names;
    this->quantities = quantities;
}

InventoryManager::InventoryManager(const InventoryManager &other)
{
    // TODO
    // Deep copy (because List2D and List1D assignment operators)
    this->attributesMatrix = other.attributesMatrix;
    this->productNames = other.productNames;
    this->quantities = other.quantities;
}

int InventoryManager::size() const
{
    // TODO
    return this->productNames.size();
}

List1D<InventoryAttribute> InventoryManager::getProductAttributes(int index) const
{
    // TODO
    if (index < 0 || index >= this->size()) {
        throw out_of_range("Index is invalid!");
    }
    return this->attributesMatrix.getRow(index);

}

string InventoryManager::getProductName(int index) const
{
    // TODO
    if (index < 0 || index >= this->size()) {
        throw out_of_range("Index is invalid!");
    }
    return this->productNames.get(index);
}

int InventoryManager::getProductQuantity(int index) const
{
    // TODO
    if (index < 0 || index >= this->size()) {
        throw out_of_range("Index is invalid!");
    }

    return this->quantities.get(index);
}

void InventoryManager::updateQuantity(int index, int newQuantity)
{
    // TODO
    if (index < 0 || index >= this->size()) {
        throw out_of_range("Index is invalid!");
    }

    this->quantities.set(index, newQuantity);
}

void InventoryManager::addProduct(const List1D<InventoryAttribute> &attributes, const string &name, int quantity)
{
    // TODO

    // Add the product attributes
    this->attributesMatrix.setRow(this->size(), attributes);
    // Add the product name
    this->productNames.add(name);
    // Add the product quantity
    this->quantities.add(quantity);
}

void InventoryManager::removeProduct(int index)
{
    // TODO
    if (index < 0 || index >= this->size()) {
        throw out_of_range("Index is invalid!");
    }

    // rebuild the matrix without the row at index
    List2D<InventoryAttribute> newMatrix;

    for (int i = 0; i < this->size(); i++) {
        // skip the row at index
        if (i == index) {
            continue;
        }

        // Add current row to the new matrix
        List1D<InventoryAttribute> row = this->attributesMatrix.getRow(i);
        int newRow = (i < index) ? i : i - 1;
        newMatrix.setRow(newRow, row);
    }

    // Create new lists for names and quantities
    List1D<string> newNames;
    List1D<int> newQuantities;

    for (int i = 0; i < this->size(); i++) {
        if (i != index) {
            newNames.add(this->productNames.get(i));
            newQuantities.add(this->quantities.get(i));
        }
    }

    // Update the current object
    this->attributesMatrix = newMatrix;
    this->productNames = newNames;
    this->quantities = newQuantities;
}

List1D<string> InventoryManager::query(string attributeName, const double &minValue,
                                       const double &maxValue, int minQuantity, bool ascending) const
{
    // TODO
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
    return this->attributesMatrix;
}

List1D<string> InventoryManager::getProductNames() const
{
    // TODO
    return this->productNames;
}

List1D<int> InventoryManager::getQuantities() const
{
    // TODO
    return this->quantities;
}

string InventoryManager::toString() const
{
    // TODO
    stringstream ss;
    
    // Start with a header
    ss << "InventoryManager[\n";
    
    // Add the attributes matrix
    ss << "  AttributesMatrix: " << this->attributesMatrix.toString() << ",\n";
    
    // Add product names
    ss << "  ProductNames: [";
    for (int i = 0; i < this->productNames.size(); i++) {
        if (i > 0) {
            ss << ", ";
        }
        ss << "\"" << this->productNames.get(i) << "\"";
    }
    ss << "],\n";
    
    // Add quantities
    ss << "  Quantities: [";
    for (int i = 0; i < this->quantities.size(); i++) {
        if (i > 0) {
            ss << ", ";
        }
        ss << this->quantities.get(i);
    }
    ss << "]\n";
    
    // Close the representation
    ss << "]";
    
    return ss.str();
}

#endif /* INVENTORY_MANAGER_H */
