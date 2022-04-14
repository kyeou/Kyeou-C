#include <OpenXLSX.hpp>
#include <iostream>
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

using namespace OpenXLSX;

int main() {

    XLDocument doc;
    doc.create("Spreadsheet.xlsx");
    auto wks = doc.workbook().worksheet("Sheet1");

    wks.cell("A1").value() = "Hello, OpenXLSX!";
   wks.cell("B1").value() = 2;
   wks.cell("C1").value() =3;
     wks.cell("D1").value() = (wks.cell("e1").value() == NULL);
   // std::cout << "Does A1 have a value? (1) -->> " << !(wks.cell("A1")).value() == NULL << "\n";
     // std::cout << "Is B1 Null? (1) -->> " <<  (wks.cell("B1")).value() == NULL << "\n";
    //printf("Does A1 have a value? (1) -->> %d\n", !(wks.cell("A1")).value() == NULL);
    //printf("Is B1 Null? (1) -->> %d\n", (wks.cell("B1")).value() == NULL);

    doc.save();

    return 0;
}