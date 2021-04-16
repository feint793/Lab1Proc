#ifndef __nature__
#define __nature__
#include <iostream>
namespace nature {
	// ���������
	struct shrubs {
		enum Month { Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };
		Month flowering;
	};

	// ������
	struct trees {
		long int m_Age; // age
		
	};
	struct shape {
		// �������� ������ ��� ������ �� �����
		enum key { TREES, SHRUBS };
		key k; // ����
		char m_Name[50];
		enum place { Forest, Garden, Steppe, Tundra};
		place area;
		union {
			shrubs s;
			trees t;
		};
	};
	struct container
	{
		enum { max_len = 100 }; // ������������ �����
		int len; // ������� �����
		shape* cont[max_len];
	};

}
#endif
