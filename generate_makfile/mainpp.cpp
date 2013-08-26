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
		ofs << "CC = g++" << endl;
		ofs << "CFLAGS = -Wall -Werror -Wextra" << endl;
		
		ofs << "LIBS = ";
		for (int i = 2; i < argc;++i)
		{
			string tmp = argv[i];
			size_t index = tmp.find(":lib:");
			if (index != string::npos)
			{
				index += 5;
				cout << index << endl;
				string tmp2 = tmp.substr(index, tmp.size() - index);
				index = tmp2.find_last_of('/');
				if (index != string::npos)
				{
					string path = tmp2.substr(0, index + 1);
					ofs << "-L" << path << " " << "-l" << tmp2.substr(index + 1, tmp2.size() - index - 1);
				}
				else
				{
					ofs << "-L. -l" << tmp2;
				}
			
			}
		}
		ofs << endl;

		ofs << "EXEC = " << argv[1] << endl << endl;
		ofs << "all: $(EXEC)" << endl << endl;
		ofs << "$(EXEC): ";
		for(int i = 2; i < argc;++i)
		{
			string tmp = argv[i];
			if (tmp[0] == ':') continue;
			size_t index = tmp.find_first_of(':');
			if (index != string::npos)
				ofs << tmp.substr(0, index);
			else
				ofs << argv[i];
			ofs << ".o ";
		}
		ofs << endl;
		ofs << "\t$(CC) -o $(EXEC) $^ $(LIBS)" << endl << endl;

		for (int i = 2; i < argc;++i)
		{
			string temp = argv[i];
			if (temp[0] == ':') continue;
			size_t index = temp.find_first_of(':');
			size_t index2 = string::npos;
			if (index != string::npos)
			{
				ofs << temp.substr(0, index) << ".cpp: ";
				for (size_t index_tmp = index + 1; index_tmp != string::npos;)
				{
					index2 = temp.find_first_of(':', index_tmp);
					if (index2 != string::npos)
					{
						ofs << temp.substr(index_tmp, index2 - index_tmp) << ".hpp ";
						index_tmp = index2 + 1;
					}
					else
					{
						ofs << temp.substr(index_tmp, temp.size() - index_tmp) << ".hpp";
						index_tmp = string::npos;
					}
				}
				ofs << endl << endl;
			}
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

