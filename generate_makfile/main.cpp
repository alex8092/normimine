#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/dir.h>
#include <sys/param.h>

using namespace std;

int main(int argc, char **argv)
{
	ofstream ofs("Makefile");
	if (ofs.is_open())
	{
		string ld = "gcc";
		string ldflags = "";
		string includedir = ".";
		string cflags = " -Wall -Wextra -Werror ";
		string srcdir = ".";
		string objdir = ".";
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

		ofs << "SRC = ";
		bool first = true;
		for (int i = 2; i < argc;++i)
		{
			string tmp = argv[i];
			if (tmp[0] == ':') continue;
			string path = "";
			size_t index = tmp.find_last_of('/');
			if (index != string::npos)
			{
				path = tmp.substr(0, index);
				tmp = tmp.substr(index + 1, tmp.size() - index - 1);
			}
			if (tmp == "*")
			{
				if (path == "")
					path = ".";
				int count, i;
				struct direct **files;
				int file_select();
				char * str = const_cast<char*>(path.c_str());
				count = scandir(str, &files, 0, 0);

				/* If no files found, make a non-selectable menu item */
				if 		(count <= 0)
					continue;
				int countbis = 0;
				for(i=1;i<count+1;++i)
				{
					string file = files[i-1]->d_name;
					if (file.find(".c") != string::npos)
					{
						if (file.find(".c.") == string::npos)
							countbis++;
					}
				}
				int j;
				for (i=1,j=1;i<count+1;++i)
				{
					string file = files[i-1]->d_name;
					if (file.find(".c") != string::npos)
					{
						if (file.find(".c.") != string::npos)
							continue ;
						j++;
						cout << file << endl;
						if (!first)
							ofs << "\t";
						else first = false;
						ofs << file;
						if (i + 1 < argc)
						{
							ofs << " \\" << endl;
						}
						else
						{
							if (j < countbis + 1)
								ofs << " \\" << endl;
							else
								ofs << endl;
						}
					}
				}
			}
			else
			{
				if (!first)
					ofs << "\t";
				else first = false;
				ofs << tmp << ".c";
				if (i + 1 < argc)
					ofs << " \\" << endl;
				else ofs << endl;
			}
		}
		ofs << "OBJS = $(SRC:.c=.o)" << endl;
		ofs << "OBJS_PREF = $(addprefix $(OBJDIR)/, $(OBJS))" << endl;
		ofs << "NAME = " << argv[1] << endl << endl;
		ofs << "all: $(NAME)" << endl << endl;
		ofs << "$(NAME): $(OBJS)" << endl;
		if (ld == "gcc")
			ofs << "\t$(LD) -o $(NAME) $(OBJS_PREF) $(LIBS) $(LDFLAGS)" << endl << endl;
		else if (ld == "ar")
			ofs << "\t$(LD) cr $(NAME).a $(OBJS_PREF) $(LDFLAGS)" << endl << endl;
		ofs << "$(OBJS): " << endl;
		ofs << "\t$(CC) -I$(INCLUDEDIR) -o $(OBJDIR)/$*.o -c $(SRCDIR)/$*.c $(CFLAGS)" << endl << endl;
		/*for (int i = 2; i < argc;++i)
		{
			string temp = argv[i];
			if (temp[0] == ':') continue;
			size_t index = temp.find_first_of(':');
			size_t index2 = string::npos;
			if (index != string::npos)
			{
				ofs << "$(OBJS): $(SRCDIR)/" << temp.substr(0, index) << ".c ";
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
			}
		}*/

		ofs << "clean: " << endl;
		/*for (int i = 2; i < argc;++i)
		{
			string tmp = argv[i];
			if (tmp[0] == ':') continue;
			size_t index = tmp.find_first_of(':');
			if (index != string::npos)*/
				ofs << "\t/bin/rm -f $(OBJS_PREF)" << endl; ///" << tmp.substr(0, index) << ".o" << endl;
			/*else
				ofs << "\t/bin/rm -f $(OBJDIR)/" << tmp << ".o" << endl;
		}*/

		ofs << "fclean: clean" << endl;
		if (ld == "gcc")
			ofs << "\t/bin/rm -f $(NAME)" << endl << endl;
		else if (ld == "ar")
			ofs << "\t/bin/rm -f $(NAME).a" << endl << endl;

		ofs << "re: fclean all" << endl << endl;
		ofs << ".PHONY: clean fclean re all" << endl;
		ofs.close();
	}
}

