#include "stdio.h"
#include "stdlib.h"
#include "limits.h"
#include "stdbool.h"

#define while_bl       \
    ttp = &PHY_MEM[0]; \
    while (ttp != NULL)

int pm_size; bool fir