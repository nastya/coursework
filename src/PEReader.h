#ifndef PEREADER_H
#define PEREADER_H

#include <string>
#include "reader.h"

using namespace std;

/**
@brief
Class working with PE-header.
*/

class PEReader : public Reader
{
	/**
	  Struct held in a tableof sections.
	*/
	struct entry
	{
		char name[8];///<name of section
		int virt_addr;///<virtual address of section
		int virt_size;///<virtual size of section
		int raw_offset;///<raw offset of section
	};
public:
	PEReader();
	PEReader(const Reader *reader);
	~PEReader();
	void load(string name);
	int entrance();
	int map(int addr);
	bool is_within_one_block(int a, int b);
	static bool is_of_type(const Reader *reader);
private:
	/**
	 Gets necessary information from header.
	*/
	void parse();
	/**
	  Sorts table of sections by raw_offset
	*/
	void sort();
	/**
	  Prints table of sections
	*/
	void print_table();
	
	/**
	@return Return integer formed of @ref size bytes from the position pos.
	*/
	int get(int pos, int size=4);

	
	int number_of_sections;///<Number of sections in input file
	int base;///< Base of addresses in memory
	int entry_point;///< Entry point of input file
	entry* table;///< Table of sections
};
#endif