#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "test/tc_dlinkedlist.h"
#include "test/tc_xarraylist.h"
#include "test/tc_inventory.h"

using namespace std;

// void (*func_ptr[15])() = {
//     dlistDemo1,
//     dlistDemo2,
//     dlistDemo3,
//     dlistDemo4,
//     dlistDemo5,
//     dlistDemo6,
//     xlistDemo1,
//     xlistDemo2,
//     xlistDemo3,
//     xlistDemo4,
//     tc_inventory1001,
//     tc_inventory1002,
//     tc_inventory1003,
//     tc_inventory1004,
//     tc_inventory1005
// };

// xList
// void (*func_ptr[4])() = {
//     xlistDemo1,
//     xlistDemo2,
//     xlistDemo3,
//     xlistDemo4
// };

// dList
// void (*func_ptr[6])() = {
//     dlistDemo1,
//     dlistDemo2,
//     dlistDemo3,
//     dlistDemo4,
//     dlistDemo5,
//     dlistDemo6
// };

// inventoryManager
void (*func_ptr[6])() = {
    tc_inventory1001,
    tc_inventory1002,
    tc_inventory1003,
    // simplified_test,
    tc_inventory1004,
    tc_inventory1005,
    tc_inventory1006
};

// void (*func_ptr[1])() = {
    // simplified_test,
    // test_split,
//     // lms_tc_inventory1003,
//     // lms_tc_inventory1004,
//     // lms_tc_inventory1006
// };

void run(int func_idx)
{
    func_ptr[func_idx]();
}

int main(int argc, char **argv)
{
    // cout << "Assignment-1" << endl;
    if (argc == 1) {
        // tc_inventory1001();
        for (int i = 0; i < 6; i++) {
            cout << "==========Running test case=======: " << i + 1 << endl;
            run(i);
        }
    }
    
    return 0;
}