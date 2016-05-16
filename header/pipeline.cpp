#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "pipeline.hpp"

using namespace std;

void pipelineReader::readFile(string fileName){
	vector<string> file, pipeline;
	ifstream infile(fileName);
	string line, delimiter = " -> ";

	// file -> vector "file"
	while (getline(infile, line)) file.push_back(line);

	size_t pos = 0;
	string token;
	while ((pos = file[0].find(delimiter)) != string::npos) {
		token = file[0].substr(0, pos);
		this->pipeline.push_back(token);
		file[0].erase(0, pos + delimiter.length());
	}
	this->pipeline.push_back(file[0]);

	
}