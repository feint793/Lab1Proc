#ifndef __nature__
#define __nature__
#include <iostream>

namespace nature {
	
	struct shrubs {
		enum Month { Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };
		Month flowering;
	};

	struct trees {
		long int m_Age; // age
		
	};

	struct flowers
	{
		enum Type { Wild, Home };
		Type kind;
	};

	struct shape {
		// значения ключей для каждой из фигур
		enum key { TREES, SHRUBS, FLOWERS };
		key k; // ключ
		char m_Name[50];
		enum place { Forest, Garden, Steppe, Tundra };
		place area;
		union {
			shrubs s;
			trees t;
			flowers f;
		};
	};

	struct container
	{
		enum { max_len = 100 }; // максимальная длина
		int len; // текущая длина
		shape* cont[max_len];
	};
}
#endif
