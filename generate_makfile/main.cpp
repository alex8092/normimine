#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
	ofstream ofs("Makefile");
	if (ofs.is_open())
	{
		ofs << "CC = gcc" << endl;
		ofs << "CFLAGS = -Wall -Werror -Wextra" << endl;
		ofs << "EXEC = " << argv[1] << endl << endl;
		ofs << "all: $(EXEC)" << endl << endl;
		ofs << "$(EXEC): ";
		for(int i = 2; i < argc;++i)
		{
			string tmp = argv[i];
			size_t index = tmp.find_first_of(':');
			if (index != string::npos)
				ofs << tmp.substr(0, index);
			else
				ofs << argv[i];
			ofs << ".o ";
		}
		ofs << endl;
		ofs << "\t$(CC) -o $(EXEC) $^" << endl << endl;

		for (int i = 2; i < argc;++i)
		{
			string temp = argv[i];
			size_t index = temp.find_first_of(':');
			size_t index2 = string::npos;
			if (index != string::npos)
			{
				ofs << temp.substr(0, index) << ".c: ";
				for (size_t index_tmp = index + 1; index_tmp != string::npos;)
				{
					index2 = temp.find_first_of(':', index_tmp);
					if (index2 != string::npos)
					{
						ofs << temp.substr(index_tmp, index2 - index_tmp) << ".h ";
						index_tmp = index2 + 1;
					}
					else
					{
						ofs << temp.substr(index_tmp, temp.size() - index_tmp) << ".h";
						index_tmp = string::npos;
					}
				}
			}
			ofs << endl << endl;
		}

		ofs << "%.o: %.c" << endl;
		ofs << "\t$(CC) -o $@ -c $< $(CFLAGS)" << endl << endl;
		ofs << "clean: " << endl;
		ofs << "\trm -f *.o" << endl << endl;
		ofs << "mrproper: clean" << endl;
		ofs << "\trm -f $(EXEC)" << endl << endl;
		ofs << ".PHONY: clean mrproper" << endl;
		ofs.close();
	}
}

