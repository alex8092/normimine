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
		string ld = "gcc";
		string ldflags = "";
		string includedir = "";
		string cflags = " -Wall -Wextra -Werror ";
		string srcdir = "";
		string objdir = "";
		for (int i = 2; i < argc; ++i)
		{
			string tmp = argv[i];
			size_t index = tmp.find(":ld:");
			if (index != string::npos)
			{
				ld = tmp.substr(index + 4, tmp.size() - index - 4);
			}
			index = tmp.find(":ldflags:");
			if (index != string::npos)
			{
				ldflags = tmp.substr(index + 9,	tmp.size() - index - 9);
			}
			index = tmp.find(":includedir:");
			if (index != string::npos)
			{
				includedir = tmp.substr(index + 12, tmp.size() - index - 12);
			}
			index = tmp.find(":cflags:");
			if (index != string::npos)
			{
				cflags += tmp.substr(index + 8, tmp.size() - index - 8);
			}
			index = tmp.find(":srcdir:");
			if (index != string::npos)
			{
				srcdir = tmp.substr(index + 8, tmp.size() - index - 8);
			}
			index = tmp.find(":objdir:");
			if (index != string::npos)
			{
				objdir = tmp.substr(index + 8, tmp.size() - index - 8);
			}
		}
		ofs << "LD = " << ld << endl;
		ofs << "LDFLAGS = " << ldflags << endl;
		ofs << "INCLUDEDIR = " << includedir << endl;
		ofs << "SRCDIR = " << srcdir << endl;
		ofs << "OBJDIR = " << objdir << endl;
		ofs << "CC = gcc" << endl;
		ofs << "CFLAGS = " << cflags << endl;
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
			ofs << "$(OBJDIR)/";
			if (index != string::npos)
				ofs << tmp.substr(0, index);
			else
				ofs << argv[i];
			ofs << ".o ";
		}
		ofs << endl;
		if (ld == "gcc")
			ofs << "\t$(LD) -o $(EXEC) $^ $(LIBS) $(LDFLAGS)" << endl << endl;
		else if (ld == "ar")
			ofs << "\t$(LD) cr $(EXEC).a $^ $(LDFLAGS)" << endl << endl;
		for (int i = 2; i < argc;++i)
		{
			string temp = argv[i];
			if (temp[0] == ':') continue;
			size_t index = temp.find_first_of(':');
			size_t index2 = string::npos;
			if (index != string::npos)
			{
				ofs << temp.substr(0, index) << ".o: $(SRCDIR)/" << temp.substr(0, index) << ".c ";
				for (size_t index_tmp = index + 1; index_tmp != string::npos;)
				{
					index2 = temp.find_first_of(':', index_tmp);
					if (index2 != string::npos)
					{
						ofs << "$(INCLUDEDIR)/" << temp.substr(index_tmp, index2 - index_tmp) << ".h ";
						index_tmp = index2 + 1;
					}
					else
					{
						ofs << "$(INCLUDEDIR)/" << temp.substr(index_tmp, temp.size() - index_tmp) << ".h";
						index_tmp = string::npos;
					}
				}
				ofs << endl;
			}
			else
			{
				ofs << temp << ".o: $(SRCDIR)/" << temp << ".c" << endl;
			}
			ofs << "\t$(CC) -o $(OBJDIR)/$@ -c $< $(CFLAGS)" << endl << endl;
		}

		ofs << "clean: " << endl;
		for (int i = 2; i < argc;++i)
		{
			string tmp = argv[i];
			if (tmp[0] == ':') continue;
			size_t index = tmp.find_first_of(':');
			if (index != string::npos)
				ofs << "\t/bin/rm -f $(OBJDIR)/" << tmp.substr(0, index) << ".o" << endl;
			else
				ofs << "\t/bin/rm -f $(OBJDIR)/" << tmp << ".o" << endl;
		}

		ofs << "fclean: clean" << endl;
		if (ld == "gcc")
			ofs << "\t/bin/rm -f $(EXEC)" << endl << endl;
		else if (ld == "ar")
			ofs << "\t/bin/rm -f $(EXEC).a" << endl << endl;

		ofs << "re: fclean all" << endl << endl;
		ofs << ".PHONY: clean fclean re all" << endl;
		ofs.close();
	}
}

