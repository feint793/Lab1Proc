#ifndef __nature__
#define __nature__
#include <iostream>
namespace nature {
	// кустарник
	struct shrubs {
		enum Month { Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };
		Month flowering;
	};

	// дерево
	struct trees {
		long int m_Age; // age
		// // name
	};
	struct shape {
		// значени€ ключей дл€ каждой из фигур
		enum key { TREES, SHRUBS };
		key k; // ключ
		char m_Name[50];
		int rate;
		union {
			shrubs s;
			trees t;
		};
	};
	struct container
	{
		enum { max_len = 100 }; // максимальна€ длина
		int len; // текуща€ длина
		shape* cont[max_len];
	};

}
#endif
