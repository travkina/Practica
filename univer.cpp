#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <regex>
#include <map>

using namespace std;
 
void readFile(const char *name);  
void print_list(string line); 
//bool checkMail(string line);

int main()
{
	setlocale (LC_ALL, "RUS");
	const char *name = "company list.txt"; 
	readFile(name);
	return 0;
}
 
void readFile(const char *name)
{
	string line, foun, replacement;
	std::tr1::regex rx;
	map <string,string> changeMap;
	changeMap.insert (std::pair<string, string>("Acad.", "Academy"));
	changeMap.insert (std::pair<string, string>("Inst.", "Institute"));
	changeMap.insert (std::pair<string, string>("Sci.", "Sciences"));
	changeMap.insert (std::pair<string, string>("U.S.S.R.", "Russia "));
	changeMap.insert (std::pair<string, string>("USSR", "Russia "));
	changeMap.insert (std::pair<string, string>("Novosibirsk.", "Novosibirsk "));
	changeMap.insert (std::pair<string, string>("Russia.", "Russia "));
	changeMap.insert (std::pair<string, string>("Semicond.", "Semiconductor"));
	changeMap.insert (std::pair<string, string>("Phys.", "Physics"));
	changeMap.insert (std::pair<string, string>("RAMS", "Russian Academy Medical Scienses"));
	changeMap.insert (std::pair<string, string>("RAS", "Russian Academy Sciences"));
	changeMap.insert (std::pair<string, string>("Med.","Medical"));
	changeMap.insert (std::pair<string, string>("Clin.","Clinical"));
	changeMap.insert (std::pair<string, string>(" and", " "));
	changeMap.insert (std::pair<string, string>(" of", " "));
	changeMap.insert (std::pair<string, string>(" the", " "));
	changeMap.insert (std::pair<string, string>(" all", " "));
	changeMap.insert (std::pair<string, string>(" for", " "));
	changeMap.insert (std::pair<string, string>(" at", " "));
	changeMap.insert (std::pair<string, string>(" in", " "));
	changeMap.insert (std::pair<string, string>("sch", "sh"));
	changeMap.insert (std::pair<string, string>("tch", "ch"));
	changeMap.insert (std::pair<string, string>("ja", "ia"));
	changeMap.insert (std::pair<string, string>("ya", "ia"));
	changeMap.insert (std::pair<string, string>("yi", "ui"));
	changeMap.insert (std::pair<string, string>("iy", "iu"));
	changeMap.insert (std::pair<string, string>("ee", "i"));
	changeMap.insert (std::pair<string, string>("ie", "i"));
	changeMap.insert (std::pair<string, string>("ii", "i"));
	changeMap.insert (std::pair<string, string>("ij", "i"));
	changeMap.insert (std::pair<string, string>("y", "i"));
	changeMap.insert (std::pair<string, string>("ei", "ai"));
	changeMap.insert (std::pair<string, string>("aja", "aia"));
	changeMap.insert (std::pair<string, string>("aya", "aia"));
	changeMap.insert (std::pair<string, string>("ae", "au"));
	changeMap.insert (std::pair<string, string>("ph", "f"));
	changeMap.insert (std::pair<string, string>("z", "s"));
	changeMap.insert (std::pair<string, string>("ou", "u"));
	changeMap.insert (std::pair<string, string>("ck", "k"));
	changeMap.insert (std::pair<string, string>("ou", "u"));
	changeMap.insert (std::pair<string, string>("Dept. ", "Department"));
	changeMap.insert (std::pair<string, string>("Dpt ", "Department"));
	changeMap.insert (std::pair<string, string>("cs ", "c "));
	changeMap.insert (std::pair<string, string>("ns ", "n "));
	changeMap.insert (std::pair<string, string>("ms ", "m "));
	changeMap.insert (std::pair<string, string>(" m", " M"));
	changeMap.insert (std::pair<string, string>(" n", " N"));
	changeMap.insert (std::pair<string, string>(" s", " S"));
	changeMap.insert (std::pair<string, string>(" p", " P"));
	changeMap.insert (std::pair<string, string>(" i", " I"));
	changeMap.insert (std::pair<string, string>(" v", " V"));

	string::iterator it;
	map<string, string>::iterator iter;
	std::size_t found;
	int i,j;
	ifstream in(name); 
	if(!in) 
    {
		cout << "The file \"" << name << "\" cannot be opened.\n";
	}
    while(in)
	{
		while(getline(in,line))
		{
		    for (it = line.begin(); it != line.end(); it++)
			{
			  if ((*it) == '#') it = line.erase (it);
			  if ((*it) == ':') it = line.erase (it);
			  if ((*it) == '&') it = line.erase (it);
			  if ((*it) == '-') it = line.erase (it);
			  if ((*it) == '(') it = line.erase (it);
			  if ((*it) == ')') it = line.erase (it);
			  if ((*it) == ',') it = line.erase (it);
			}
			
			for (iter = changeMap.begin(); iter != changeMap.end(); ++iter)
			{
				while(line.find(iter->first) != std::string::npos)
				{ 
					line.replace(line.find(iter->first),iter->first.length(), iter->second);	
				}
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
