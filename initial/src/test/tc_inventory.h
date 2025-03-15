#include <iostream>
#include "app/inventory.h" 

using namespace std;

void tc_inventory1001() {
    int arr[] = {1, 2, 3, 4, 5};
    List1D<int> list1D(arr, 5);
    
    cout << list1D.toString() << endl;
}

// ######################### 1.0 version ===> old
// void tc_inventory1002() {
//     int row0[] = {1, 2, 3};
//     int row1[] = {4, 5, 6};
//     int row2[] = {7, 8, 9};
//     const int* arr2D[] = { row0, row1, row2 };
    
//     List2D<int> matrix(arr2D, 3, 3);
    
//     cout << matrix.toString() << endl;
// }

// void tc_inventory1003() {
//     int attrRow0[] = {10, 20};
//     int attrRow1[] = {30, 40};
//     const int* attrArr[] = { attrRow0, attrRow1 };
//     List2D<int> attributesMatrix(attrArr, 2, 2);
    
//     string namesArr[] = {"ProductA", "ProductB"};
//     List1D<string> productNames(namesArr, 2);
    
//     int qtyArr[] = {5, 10};
//     List1D<int> quantities(qtyArr, 2);
    
//     InventoryManager<int> inv(attributesMatrix, productNames, quantities);
    
//     cout << inv.toString() << endl;
// }

// void tc_inventory1004() {
//     int attrRow0[] = {1, 2};
//     int attrRow1[] = {3, 4};
//     const int* attrArr[] = { attrRow0, attrRow1 };
//     List2D<int> matrix(attrArr, 2, 2);
    
//     string namesArr[] = {"ProdX", "ProdY"};
//     List1D<string> names(namesArr, 2);
    
//     int qtyArr[] = {8, 12};
//     List1D<int> quantities(qtyArr, 2);
    
//     InventoryManager<int> inv1(matrix, names, quantities);
    
//     InventoryManager<int> invCopy(inv1);
//     invCopy.updateQuantity(0, 20);
    
//     cout << inv1.getProductQuantity(0) << endl;
//     cout << invCopy.getProductQuantity(0) << endl;
// }

// void tc_inventory1005() {
//     int attrRow0[] = {5, 100};  
//     int attrRow1[] = {10, 150};
//     int attrRow2[] = {15, 200}; 
//     const int* attrArr[] = { attrRow0, attrRow1, attrRow2 };
//     List2D<int> matrix(attrArr, 3, 2);
    
//     string namesArr[] = {"A", "B", "C"};
//     List1D<string> names(namesArr, 3);
    
//     int qtyArr[] = {3, 6, 9};
//     List1D<int> quantities(qtyArr, 3);
    
//     InventoryManager<int> inv(matrix, names, quantities);
    
//     List1D<string> result = inv.query(0, 7, 16, 5, true);
    
//     cout << result.toString() << endl;
// }

// ############# 1.1 version
void tc_inventory1002() {
    int row0[] = {1, 2, 3};
    int row1[] = {4, 5, 6};
    int row2[] = {7, 8, 9};
    
    List1D<int> arr2D[] = { List1D<int>(row0, 3), List1D<int>(row1, 3), List1D<int>(row2, 3) };
    
    List2D<int> matrix(arr2D, 3);
    
    cout << matrix.toString() << endl;
}

void tc_inventory1003() {
    InventoryAttribute attrA1("weight", 10);
    InventoryAttribute attrA2("height", 156);
    InventoryAttribute arrA[] = { attrA1, attrA2 };
    int numAttrA = sizeof(arrA) / sizeof(arrA[0]);
    List1D<InventoryAttribute> listAttrA(arrA, numAttrA);

    InventoryAttribute attrB1("weight", 20);
    InventoryAttribute attrB2("depth", 24);
    InventoryAttribute attrB3("height", 100);
    InventoryAttribute arrB[] = { attrB1, attrB2, attrB3 };
    int numAttrB = sizeof(arrB) / sizeof(arrB[0]);
    List1D<InventoryAttribute> listAttrB(arrB, numAttrB);

    InventoryAttribute attrC1("color", 2);
    InventoryAttribute arrC[] = { attrC1 };
    int numAttrC = sizeof(arrC) / sizeof(arrC[0]);
    List1D<InventoryAttribute> listAttrC(arrC, numAttrC);

    List1D<InventoryAttribute> attributesArray[3] = { listAttrA, listAttrB, listAttrC };
    List2D<InventoryAttribute> attributesMatrix(attributesArray, 3);

    string namesArray[] = { "Product A", "Product B", "Product C" };
    List1D<string> productNames(namesArray, 3);
    
    int quantitiesArray[] = { 50, 30, 20 };
    List1D<int> quantities(quantitiesArray, 3);

    InventoryManager inventory(attributesMatrix, productNames, quantities);
    
    cout << inventory.toString() << endl;
}

// void simplified_test() {
//     // Create a small inventory
//     InventoryAttribute attr("test", 1.0);
//     InventoryAttribute arr[] = { attr };
//     List1D<InventoryAttribute> list(arr, 1);
    
//     List1D<InventoryAttribute> attributesArray[1] = { list };
//     List2D<InventoryAttribute> attributesMatrix(attributesArray, 1);
    
//     string names[] = { "Test" };
//     List1D<string> productNames(names, 1);
    
//     int qty[] = { 10 };
//     List1D<int> quantities(qty, 1);
    
//     // Create inventory and let it go out of scope
//     {
//         InventoryManager inventory(attributesMatrix, productNames, quantities);
//         cout << "Inventory created successfully" << endl;
//     } // Destructor called here
    
//     cout << "Test completed successfully" << endl;
// }

void tc_inventory1004(){
    InventoryAttribute attrA1("weight", 10);
    InventoryAttribute attrA2("height", 156);
    InventoryAttribute arrA[] = { attrA1, attrA2 };
    int numAttrA = sizeof(arrA) / sizeof(arrA[0]);
    List1D<InventoryAttribute> listAttrA(arrA, numAttrA);

    InventoryAttribute attrB1("weight", 20);
    InventoryAttribute attrB2("depth", 24);
    InventoryAttribute attrB3("height", 100);
    InventoryAttribute arrB[] = { attrB1, attrB2, attrB3 };
    int numAttrB = sizeof(arrB) / sizeof(arrB[0]);
    List1D<InventoryAttribute> listAttrB(arrB, numAttrB);

    InventoryAttribute attrC1("color", 2);
    InventoryAttribute arrC[] = { attrC1 };
    int numAttrC = sizeof(arrC) / sizeof(arrC[0]);
    List1D<InventoryAttribute> listAttrC(arrC, numAttrC);

    List1D<InventoryAttribute> attributesArray[3] = { listAttrA, listAttrB, listAttrC };
    List2D<InventoryAttribute> attributesMatrix(attributesArray, 3);

    string namesArray[] = { "Product A", "Product B", "Product C" };
    List1D<string> productNames(namesArray, 3);
    
    int quantitiesArray[] = { 50, 30, 20 };
    List1D<int> quantities(quantitiesArray, 3);

    InventoryManager inventory(attributesMatrix, productNames, quantities);
    
    InventoryAttribute attrD1("weight", 15);
    InventoryAttribute attrD2("height", 140);
    InventoryAttribute arrD[] = { attrD1, attrD2 };
    int numAttrD = sizeof(arrD) / sizeof(arrD[0]);
    List1D<InventoryAttribute> listAttrD(arrD, numAttrD);
    inventory.addProduct(listAttrD, "Product D", 40);
    cout << "\nAfter adding Product D:" << endl;
    cout << inventory.toString() << endl;
}

void tc_inventory1005(){
    InventoryAttribute attrA1("weight", 10);
    InventoryAttribute attrA2("height", 156);
    InventoryAttribute arrA[] = { attrA1, attrA2 };
    int numAttrA = sizeof(arrA) / sizeof(arrA[0]);
    List1D<InventoryAttribute> listAttrA(arrA, numAttrA);

    InventoryAttribute attrB1("weight", 20);
    InventoryAttribute attrB2("depth", 24);
    InventoryAttribute attrB3("height", 100);
    InventoryAttribute arrB[] = { attrB1, attrB2, attrB3 };
    int numAttrB = sizeof(arrB) / sizeof(arrB[0]);
    List1D<InventoryAttribute> listAttrB(arrB, numAttrB);

    InventoryAttribute attrC1("color", 2);
    InventoryAttribute arrC[] = { attrC1 };
    int numAttrC = sizeof(arrC) / sizeof(arrC[0]);
    List1D<InventoryAttribute> listAttrC(arrC, numAttrC);

    List1D<InventoryAttribute> attributesArray[3] = { listAttrA, listAttrB, listAttrC };
    List2D<InventoryAttribute> attributesMatrix(attributesArray, 3);

    string namesArray[] = { "Product A", "Product B", "Product C" };
    List1D<string> productNames(namesArray, 3);
    
    int quantitiesArray[] = { 50, 30, 20 };
    List1D<int> quantities(quantitiesArray, 3);

    InventoryManager inventory(attributesMatrix, productNames, quantities);

    // my version
    List1D<string> queryResult = inventory.query("weight", 10, 20, 30, true);
    // List1D<string> queryResult = inventory.query(1, 10, 20, 30, true);
    cout << "\nQuery result (weight between 10 and 20, quantity >= 30):" << endl;
    cout << queryResult << endl;
}

void tc_inventory1006(){
    InventoryAttribute attrA1("weight", 10);
    InventoryAttribute attrA2("height", 156);
    InventoryAttribute arrA[] = { attrA1, attrA2 };
    int numAttrA = sizeof(arrA) / sizeof(arrA[0]);
    List1D<InventoryAttribute> listAttrA(arrA, numAttrA);

    InventoryAttribute attrB1("weight", 20);
    InventoryAttribute attrB2("depth", 24);
    InventoryAttribute attrB3("height", 100);
    InventoryAttribute arrB[] = { attrB1, attrB2, attrB3 };
    int numAttrB = sizeof(arrB) / sizeof(arrB[0]);
    List1D<InventoryAttribute> listAttrB(arrB, numAttrB);

    InventoryAttribute attrC1("color", 2);
    InventoryAttribute arrC[] = { attrC1 };
    int numAttrC = sizeof(arrC) / sizeof(arrC[0]);
    List1D<InventoryAttribute> listAttrC(arrC, numAttrC);

    List1D<InventoryAttribute> attributesArray[3] = { listAttrA, listAttrB, listAttrC };
    List2D<InventoryAttribute> attributesMatrix(attributesArray, 3);

    string namesArray[] = { "Product A", "Product B", "Product C" };
    List1D<string> productNames(namesArray, 3);
    
    int quantitiesArray[] = { 50, 30, 20 };
    List1D<int> quantities(quantitiesArray, 3);

    InventoryManager inventory(attributesMatrix, productNames, quantities);

    inventory.addProduct(listAttrA, "Product A", 20);
    cout << "\nAfter adding duplicate of Product A:" << endl;
    cout << inventory.toString() << endl;
    inventory.removeDuplicates();
    cout << "\nAfter removing duplicates:" << endl;
    cout << inventory.toString() << endl;
}