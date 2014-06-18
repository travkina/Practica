#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <regex>

using namespace std;
 
void readFile(const char *name);  
void print_list(string line); 
//bool checkMail(string line);

int main()
{
	setlocale (LC_ALL, "RUS");
	string institute;
	const char *name = "company list.txt"; 
	readFile(name);
	return 0;
}
 
void readFile(const char *name)
{
	string line, replacement;
	std::tr1::regex rx;
	string rep[10]={"Academy", "Institute", "Sciences", "USSR", "Semiconductor", "Physics", "Russian Academy Medical Scienses", "Medical", "Novosibirsk ", "Russia "};
	string reg[10]={"Acad.", "Inst.", "Sci.", "U.S.S.R.", "Semicond.", "Phys.", "RAMS", "Med.","Novosibirsk.", "Russia."};
	string::iterator it;
	int i;

	ifstream in(name); 
	if(!in) 
        {
		cout << "The file \"" << name << "\" cannot be opened.\n";
	}
    while(in)
	{
		while(getline(in,line))
		{
			for(i=0; i<10; i++)
			{
				rx = reg[i];
				replacement = rep[i];
                                line = regex_replace(line, rx, replacement);
			}
			for (it = line.begin(); it != line.end(); it++)
			{
			  if ((*it) == '-') it = line.erase (it);
			  if ((*it) == '(') it = line.erase (it);
			  if ((*it) == ')') it = line.erase (it);
			  if ((*it) == ',') it = line.erase (it);
			}
			print_list(line);
		}
	}
	in.close();
}

void print_list(string line)
{
	ofstream f("C:\\Users\\Tatiana\\Documents\\Visual Studio 2012\\Projects\\Univer\\Univer\\new company list.txt", ios::app);
	f << line << "\n";
	f.close();
}
