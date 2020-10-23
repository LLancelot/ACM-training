/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: lyndon91
TASK: gift1
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
#define MAXPEOPLE 10

int npeople;
string names[MAXPEOPLE];
int totals[MAXPEOPLE];

int lookup(string name) {
	for (int i = 0; i < npeople; i++) {
		if (name == names[i]) {
			return i;
		}
	}
}

int main() {
	int giver, receiver;
	ofstream fout("gift1.out");
	ifstream fin("gift1.in");
	int np;
	fin >> np;
	for (int i = 0; i<np; i++) {
		fin >> names[npeople++];
	}
	for (int i = 0; i < np; i++) {
		int amt, ng;
		string name;
		fin >> name >> amt >> ng;
		giver = lookup(name);
		for (int j = 0; j < ng; j++) {
			fin >> name;
			receiver = lookup(name);
			totals[giver] -= amt / ng;
			totals[receiver] += amt / ng;
		}
	}
	for (int i = 0; i < np; i++) {
		fout << names[i] << " " << totals[i] << endl;
	}
	exit(0);
}

