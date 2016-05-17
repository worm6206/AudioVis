#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "pipeline.hpp"

using namespace std;

void pipelineReader::readFile(string fileName){
	vector<string> file;
	ifstream infile(fileName);
	string line, delimiter = " -> ";

	// file -> vector "file"
	while (getline(infile, line)) file.push_back(line);

	/*==============================================
	=            REST - READ PARAMETERS            =
	==============================================*/
	
	for(int i =0;i<file.size();i++){
		if(file[i][0]>=65&&file[i][0]<=90){
			vector<string> temp;
			temp.push_back(file[i].substr(0,file[i].size()-1));
			while(file[++i]!=""){
				istringstream iss(file[i]);
				string a, b;
				iss >> a >> b;
				temp.push_back(a.substr(0,a.size()-1));
				temp.push_back(b);
			}
			this->parameters.push_back(temp);
		}
	}
	
	/*=====  End of REST - READ PARAMETERS  ======*/
	
}