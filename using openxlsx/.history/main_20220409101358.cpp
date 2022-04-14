#include "OpenXLSX/OpenXLSX.hpp"

OpenXLSX::XLDocument doc;
doc.create("UserBook.xlsx");

auto wks = doc.workbook().worksheet("Sheet1");