#include <fstream>
#include <iostream>
#include <string>
#include "container.h"

using namespace std;

namespace nature {

	shape* InShape(ifstream& ifst);
	void OutShape(shape& sh, ofstream& ofst);
	void InTrees(trees& t, ifstream& ifst);
	void InShrubs(shrubs& s, ifstream& ifst);
	void OutTrees(trees& t, ofstream& ofst);
	void OutShrubs(shrubs& s, ofstream& ofst);
	void InFlowers(flowers& f, ifstream& ifst);
	void OutFlowers(flowers& f, ofstream& ofst);

	void Init(container& c)
	{
		c.len = 0;
	}

	void Clear(container& c) {
		for (int i = 0; i < c.len; i++) {
			delete c.cont[i];
		}
		c.len = 0;
	};

	void InContainer(container& c, ifstream& ifst) {
		while (!ifst.eof()) {
			if ((c.cont[c.len] = InShape(ifst)) != 0) { c.len++; }
		}
	}

	void OutContainer(container& c, ofstream& ofst) {
		ofst << "Container contains " << c.len << " elements." << endl;
		for (int i = 0; i < c.len; i++) {
			ofst << i << ": ";
			OutShape(*(c.cont[i]), ofst);
		}
	}

	shape* InShape(ifstream& ifst)
	{
		shape* sp;
		string Type;
		getline(ifst, Type);
		int k = stoi(Type);
		//ifst >> k;
		switch (k) {
		case 1:
			sp = new shape;
			sp->k = shape::key::TREES;
			ifst.getline(sp->m_Name, 50);
			InTrees(sp->t, ifst);
			//ifst >> sp->rate;
			return sp;
		case 2:
			sp = new shape;
			sp->k = shape::key::SHRUBS;
			ifst.getline(sp->m_Name, 50);
			InShrubs(sp->s, ifst);
			//ifst >> sp->rate;
			return sp;
		case 3:
			sp = new shape;
			sp->k = shape::key::FLOWERS;
			ifst.getline(sp->m_Name, 50);
			InFlowers(sp->f, ifst);
			//ifst >> sp->rate;
			return sp;
		default:
			return 0;
		}
	}

	void OutShape(shape& sh, ofstream& ofst) {
		switch (sh.k) {
		case shape::key::TREES:
			ofst << "It's a tree: " << sh.m_Name << "\n";
			OutTrees(sh.t, ofst);
			break;
		case shape::key::SHRUBS:
			ofst << "It's a shrub: " << sh.m_Name << "\n";
			OutShrubs(sh.s, ofst);
			break;
		case shape::key::FLOWERS:
			ofst << "It's a flower: " << sh.m_Name << "\n";
			OutFlowers(sh.f, ofst);
			break;
		default:
			ofst << "Incorrect object!" << endl;
		}
		//ofst << ". Area of growth: " << sh.rate << endl;
	}

	void InShrubs(shrubs& s, ifstream& ifst)
	{
		string Num;
		getline(ifst, Num);
		int Pass = stoi(Num);
		switch (Pass) {
		case 1:
			s.flowering = shrubs::Month::Jan;
			break;
		case 2:
			s.flowering = shrubs::Month::Feb;
			break;
		case 3:
			s.flowering = shrubs::Month::Mar;
			break;
		case 4:
			s.flowering = shrubs::Month::Apr;
			break;
		case 5:
			s.flowering = shrubs::Month::May;
			break;
		case 6:
			s.flowering = shrubs::Month::Jun;
			break;
		case 7:
			s.flowering = shrubs::Month::Jul;
			break;
		case 8:
			s.flowering = shrubs::Month::Aug;
			break;
		case 9:
			s.flowering = shrubs::Month::Sep;
			break;
		case 10:
			s.flowering = shrubs::Month::Oct;
			break;
		case 11:
			s.flowering = shrubs::Month::Nov;
			break;
		case 12:
			s.flowering = shrubs::Month::Dec;
			break;
		default:
			cout << "Error in InShrubs func!\n";
		}
		//ifst.getline(s., 50);
		//ifst.getline(s.b, 50);
		
	}

	void OutShrubs(shrubs& s, ofstream& ofst)
	{
		switch (s.flowering) {
		case shrubs::Month::Jan:
			ofst << "Month: January\n";
			break;
		case shrubs::Month::Feb:
			ofst << "Month: February\n";
			break;
		case shrubs::Month::Mar:
			ofst << "Month: March\n";
			break;
		case shrubs::Month::Apr:
			ofst << "Month: April\n";
			break;
		case shrubs::Month::May:
			ofst << "Month: May\n";
			break;
		case shrubs::Month::Jun:
			ofst << "Month: June\n";
			break;
		case shrubs::Month::Jul:
			ofst << "Month: July\n";
			break;
		case shrubs::Month::Aug:
			ofst << "Month: August\n";
			break;
		case shrubs::Month::Sep:
			ofst << "Month: September\n";
			break;
		case shrubs::Month::Oct:
			ofst << "Month: October\n";
			break;
		case shrubs::Month::Nov:
			ofst << "Month: November\n";
			break;
		case shrubs::Month::Dec:
			ofst << "Month: December\n";
			break;
		default:
			cout << "Error in OutShrubs func!\n";
		}
		
	}

	void InTrees(trees& t, ifstream& ifst) {
		string Age;
		getline(ifst, Age);
		t.m_Age = stol(Age);
		//ifst.getline(t.y, 100);
		
	}


	void OutTrees(trees& t, ofstream& ofst) {
		ofst << "Age: " << t.m_Age << "\n";
	}

	void InFlowers(flowers& f, ifstream& ifst) {
		string Num;
		getline(ifst, Num);
		int Pass = stoi(Num);
		switch (Pass) {
		case 1:
			f.kind = flowers::Type::Wild;
			break;
		case 2:
			f.kind = flowers::Type::Home;
			break;
		default:
			cout << "Error !\n";
		}
	};
	void OutFlowers(flowers& f, ofstream& ofst) {
		switch (f.kind) {
		case flowers::Type::Wild:
			ofst << "Type: Wild\n";
			break;
		case flowers::Type::Home:
			ofst << "Type: Home\n";
			break;
		default:
			cout << "Error !\n";
		}
	}
};
