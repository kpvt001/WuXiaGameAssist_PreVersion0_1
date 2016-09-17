#include "gtest/gtest.h"

#include "WuXiaTimeConfigDataSheet.h"

int VerifyDatasheet();
using namespace WXGA::DataSheet::Time;

TEST(Datasheet, Time)
{
    ASSERT_EQ(1, VerifyDatasheet());
}


int VerifyDatasheet()
{
	for (int i = 0; i < data_length; i++)
	{
		if (i != datas[i].number)
			return 2;
	}

	return 1;
}
