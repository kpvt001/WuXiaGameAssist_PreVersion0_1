#ifndef WUXIATIMECONFIGDATASHEET_H
#define WUXIATIMECONFIGDATASHEET_H

namespace WXGA {
	namespace DataSheet {
		namespace Time {

			static const int kWei = 0;
			static const int kShen = 1;
			static const int kYou = 2;
			static const int kXu = 3;
			static const int kHai = 4;
			static const int kZi = 5;
			static const int kChou = 6;
			static const int kYin = 7;
			static const int kMao = 8;
			static const int kChen = 9;
			static const int kSi = 10;
			static const int kWu = 11;

			static const int kHoursOneGameDay = 4;

			struct Data
			{
				int number;
				int hour;
				int min;
				const char* name;
			};

			const int data_length = kWu + 1;

			static Data datas[data_length] = {
				//  number  hour    min     name
				{kWei,  0,      0,      "未时"},
				{kShen, 0,      20,     "申时"},
				{kYou,  1,      0,      "酉时"},
				{kXu,   1,      35,     "戌时"},
				{kHai,  1,      55,     "亥时"},
				{kZi,   2,      5,      "子时"},
				{kChou, 2,      10,     "丑时"},
				{kYin,  2,      15,     "寅时"},
				{kMao,  2,      25,     "卯时"},
				{kChen, 2,      50,     "辰时"},
				{kSi,   3,      30,     "巳时"},
				{kWu,   3,      55,     "午时"}
			};
		}
	}
}

#endif // WUXIATIMECONFIGDATASHEET_H
