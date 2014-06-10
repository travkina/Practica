#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
 
struct dlList
{
 
	dlList *prev;
        char c;
        dlList *next;
 
} *start, *last;
 
void readFile(const char *name); 
bool check_list(void); 
void print_list(void); 

int main()
{	
	start = NULL;
	const char *name = "company list.txt"; 
	readFile(name);
	return 0;
}
 
void readFile(const char *name)
{
	char ch = ' ';
	dlList *p, *p1;
	ifstream in(name); 
	if(!in) 
    {
		cout << "The file \"" << name << "\" cannot be opened.\n";
	}
    while(in)
	{
		while(ch != '\n' && !in.eof())
		{
      		in.get(ch); 
			if(ch >= 65 && ch <=90 || ch >= 97 && ch <= 122)
 
			{
				if(ch >= 65 && ch <= 90)
				   ch = ch - 'A' + 'a';
				if(start == NULL)
				{
					start = new dlList;
					start -> c = ch;
					start -> next = NULL;
					start -> prev = NULL;
					last = start;
				}
				else  
				{ 
					p = new dlList;
					p -> c = ch;
					p -> next = NULL;
					p -> prev = last;
					last -> next = p;
					last = p; 
				}
			}
		}
 
		if(check_list())	print_list();
		p = start;
		while(p != NULL)
		{
			p1 = p -> next;
			delete p;
			p = p1;
		}
		start = NULL;
		last = NULL;
		ch = ' ';
	}
	in.close();
}

bool check_list(void)
{
	dlList *start1, *last1;
	start1 = start; 
	last1 = last;
	while (start1 != last1)
	{
		if ( (start1 -> c) != (last1 -> c) ) break;
		else
		{
			start1 = start1 -> next;
			last1 = last1 -> prev;
		}	
	}
	if (start1 == last1) return true;
	else 
		return false;
 
}

void print_list(void)
{

	dlList *p;
    ofstream f("C:\\Users\\Tatiana\\Documents\\Visual Studio 2012\\Projects\\Univer\\Univer\\univer.txt", ios::out);
	p = start;
	while(p != NULL)
	{ 
		f << p -> c;
		cout << p -> c;
		p = p -> next;
	}
	f.close();
}
