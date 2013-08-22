#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

std::string replaceAll(
		  std::string result, 
		    const std::string& replaceWhat, 
			  const std::string& replaceWithWhat)
{
	  while(1)
		    {
				    const int pos = result.find(replaceWhat);
					    if (pos==-1) break;
						    result.replace(pos,replaceWhat.size(),replaceWithWhat);
							  }
	    return result;
}

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		cout << "lancement du programme de test des espaces et tabulations" << endl;
		ifstream ifs(argv[1]);
		if (ifs.is_open())
		{
			cout << "ouverture du fichier" << endl;
			string line;
			int nbline = 0;
			while (getline(ifs, line))
			{
				nbline++;
				line = replaceAll(line, "\t" , "    ");
				int len = line.size();
				if (len == 0)
					continue;
				if (len > 80)
					cout << nbline << ":" << line << " <= La ligne depasse les 80 colonnes" << endl;
				if((line[len - 1] == ' ' || line[len - 1] == '\t') && line[len - 1] != 0)
					cout << nbline << ":" << line << " <= Espace en trop en fin de ligne" << endl;
				size_t index = line.find("if(");
				size_t index2 = line.find("while(");
				if (index != string::npos)
					cout << nbline << ":" << line << " <= Pas d'espace apres le if" << endl;
				else if (index2 != string::npos)
					cout << nbline << ":" << line << " <= Pas d'espace apres le while" << endl;
				index = line.find("for");
				if (index != string::npos)
					cout << nbline << ":" << line << " <= Boucle for interdite" << endl;
				index = line.find("switch");
				if (index != string::npos)
					cout << nbline << ":" << line << " <= Condition switch interdite" << endl;
				index = line.find("case");
				if (index != string::npos)
					cout << nbline << ":" << line << " <= Condition case interdite" << endl;
				index = line.find("goto");
				if (index != string::npos)
					cout << nbline << ":" << line << " <= Appel de goto interdit" << endl;
				index = line.find("//");
				if (index != string::npos)
					cout << nbline << ":" << line << " <= Commentaire uniligne interdit" << endl;	
				index = line.find("{");
				if (index != string::npos && line.at(len - 1) != '{')
					cout << nbline << ":" << line << " <= Les accolades sont seules sur leur ligne" << endl;
				index = line.find("return(");
				index2 = line.find("return;");
				if (index != string::npos || index2 != string::npos)
					cout << nbline << ":" << line << " <= Un espace est necessaire apres le return" << endl;
				index = line.find(",");
				if (index != string::npos && line.at(index+1) != ' ' && line.at(index+1) != '\'' && index+1 != len)
					cout << "\033[1;44;1m" <<  nbline << "\033[0m" << ":" << line << " <= Un espace est necessaire apres une virgule" << endl;
			}
			ifs.close();
		}
	}
	return 0;
}
