 #include <iostream>
  #include <fstream>
  #include <iomanip>
 #include <string>
  
  using namespace std;

 void readFile(const char *name,string institute);  
 void print_list(string line); 
 int main()
 {
	 setlocale (LC_ALL, "RUS");
 	string institute;
  	const char *name = "company list.txt"; 
	cout << "Ввести назание института,который нужно выделить" << "\n" << "Institute of ";
	getline( cin, institute);
    readFile(name, institute);
  	return 0;
 }
 void readFile(const char *name, string institute)
  {
	  string ch;
 	string line;
  	ifstream in(name); 
  	if(!in) 
      {
  		cout << "The file \"" << name << "\" cannot be opened.\n";
  	}
      while(in)
  	{
		while(getline(in,line))
  		{
			if ( line.find(institute) != std::string::npos )
		    {
				// cout << " " ;
		         print_list(line);
				
			}
  		}
	}
  	in.close();
  }
 void print_list(string line)
  {
	 ofstream f("C:\\Users\\Tatiana\\Documents\\Visual Studio 2012\\Projects\\sort\\sort\\sort.txt", ios::app);
 	f << line << "\n";
 	cout << "\n" << line << endl;
  	//f.close();
  }
