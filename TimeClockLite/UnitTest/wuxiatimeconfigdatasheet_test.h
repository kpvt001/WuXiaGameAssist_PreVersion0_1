#ifndef WUXIATIMECONFIGDATASHEET_TEST_H
#define WUXIATIMECONFIGDATASHEET_TEST_H

#include "WuXiaTimeConfigDataSheet.h"

using namespace WXGA::DataSheet::Time;
int VerifyDatasheet();



static int VerifyDatasheet()
{
    for (int i = 0; i < data_length; i++)
    {
        if (i != datas[i].number)
            return 2;
    }

    return 1;
}

#endif // WUXIATIMECONFIGDATASHEET_TEST_H
