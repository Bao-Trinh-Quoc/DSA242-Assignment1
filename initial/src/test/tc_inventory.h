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

void simplified_test() {
    InventoryAttribute attrA1("weight", 10);
    InventoryAttribute attrA2("height", 156);
    InventoryAttribute arrA[] = { attrA1, attrA2 };
    int numAttrA = sizeof(arrA) / sizeof(arrA[0]);
    List1D<InventoryAttribute> listAttrA(arrA, numAttrA);
 
    InventoryAttribute attrA3("height", 100);
    InventoryAttribute arrA1[] = { attrA1, attrA3 };
    int numAttrA1 = sizeof(arrA1) / sizeof(arrA1[0]);
    List1D<InventoryAttribute> listAttrB(arrA1, numAttrA1);
 
    InventoryAttribute attrA4("height", 100);
    InventoryAttribute arrA4[] = { attrA1, attrA4 };
    int numAttrA4 = sizeof(arrA4) / sizeof(arrA4[0]);
    List1D<InventoryAttribute> listAttrc(arrA4, numAttrA4);
 
 
 
    List1D<InventoryAttribute> list[] = {listAttrA,listAttrB,listAttrc,listAttrA,listAttrA};
    List2D<InventoryAttribute> emptyMatrix(list,5); // Ma trận thuộc tính rỗng
    string name1[] = {"A", "B","C", "D", "E"};
    List1D<string> names1(name1,5);
    int quan[] = {150, 20, 30, 40, 50};
    List1D<int> quantities1(quan,5);
    InventoryManager inv1(emptyMatrix, names1, quantities1);
    string name2[] = {"F", "G", "I", "H", "J"};
    List1D<string> names2(name2,5);
    int quan1[] = {1100, 70, 80, 90, 100};
    List1D<int> quantities2(quan1,5);
    InventoryManager inv2(emptyMatrix, names2, quantities2);
 
    InventoryManager merged = InventoryManager::merge(inv1, inv2);

    
    
    double maxvalue = 200;
    double minvalue =5;

    cout << merged.toString() << endl;

    cout << "Output: \n";
    cout << merged.query("height",minvalue,maxvalue,10,true).toString()<<endl;
    cout <<merged.query("height",minvalue,maxvalue,10,false).toString()<<endl;

    cout << "Expected output: \n";
    cout << "[B, C, G, I, D, E, H, J, A, F]\n\
[F, A, J, H, E, D, I, G, C, B]\n";
}

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

// this testcase is about some format problem => need to clear
void lms_tc_inventory1003() {
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
    cout << "Done" << endl;
}

void lms_tc_inventory1004(){
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
    cout << "Here" << endl;
    cout << "\nAfter adding Product D:" << endl;
    cout << inventory.toString() << endl;
}

void lms_tc_inventory1006(){
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
    cout << "Removing duplicates..." << endl;
    inventory.removeDuplicates();
    cout << "\nAfter removing duplicates:" << endl;
    cout << inventory.size() << endl;
    cout << inventory.toString() << endl;
}

void test_split() {
    InventoryAttribute attr1("weight", 10);
    InventoryAttribute attr2("height", 150);
    InventoryAttribute attr3("height", 160);
    InventoryAttribute attr4("height", 170);
    InventoryAttribute attr5("height", 180);
    
    InventoryAttribute arrA[] = {attr1, attr2};
    InventoryAttribute arrB[] = {attr1, attr3};
    InventoryAttribute arrC[] = {attr1, attr4};
    InventoryAttribute arrD[] = {attr1, attr5};
    
    List1D<InventoryAttribute> listA(arrA, 2);
    List1D<InventoryAttribute> listB(arrB, 2);
    List1D<InventoryAttribute> listC(arrC, 2);
    List1D<InventoryAttribute> listD(arrD, 2);
    
    List1D<InventoryAttribute> lists[] = {listA, listB, listC, listD,
                                          listA, listB, listC, listD,
                                          listA, listB, listC, listD,
                                          listA, listB, listC, listD,
                                          listA, listB, listC, listD};
    
    List2D<InventoryAttribute> attributesMatrix(lists, 20);
    
    string productNamesArr[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", 
                                "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T"};
    List1D<string> productNames(productNamesArr, 20);
    
    int quantitiesArr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100,
                           110, 120, 130, 140, 150, 160, 170, 180, 190, 200};
    List1D<int> quantities(quantitiesArr, 20);
    
    InventoryManager inv(attributesMatrix, productNames, quantities);

    cout << "Expected output: \n";
    cout << "[]\n\
[A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T]\n\
[A, B]\n\
[C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T]\n\
[A, B, C, D]\n\
[E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T]\n\
[A, B, C, D, E, F]\n\
[G, H, I, J, K, L, M, N, O, P, Q, R, S, T]\n\
[A, B, C, D, E, F, G, H]\n\
[I, J, K, L, M, N, O, P, Q, R, S, T]\n\
[A, B, C, D, E, F, G, H, I, J]\n\
[K, L, M, N, O, P, Q, R, S, T]\n\
[A, B, C, D, E, F, G, H, I, J, K, L]\n\
[M, N, O, P, Q, R, S, T]\n\
[A, B, C, D, E, F, G, H, I, J, K, L, M, N]\n\
[O, P, Q, R, S, T]\n\
[A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P]\n\
[Q, R, S, T]\n\
[A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R]\n\
[S, T]\n\
[A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T]\n\
[]\n";
    cout << "Output: \n";
    InventoryManager s1;
    InventoryManager s2;

    cout << "Invetory size: " << inv.size() << endl;
    for(double i = 0.0; i <= 1.0; i += 0.1) {
        cout << i << endl;
        inv.split(s1,s2,i);
        cout<<s1.getProductNames()<<endl;
        cout<<s2.getProductNames()<<endl;
    }
}