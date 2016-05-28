#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "pipeline.hpp"
#include <essentia/algorithmfactory.h>
#include <essentia/streaming/algorithms/poolstorage.h>
#include <essentia/streaming/algorithms/vectorinput.h>
#include <essentia/scheduler/network.h>

using namespace std;
using namespace essentia;
using namespace essentia::streaming;
using namespace essentia::scheduler;

/**

	TODO:
	- connection recognize
	- dynamic factor create

 */

// bool is_digits(const std::string &str) return str.find_first_not_of("0123456789") == std::string::npos;



void pipelineReader::initAlgorithm(){

	essentia::init();
	streaming::AlgorithmFactory& factory = streaming::AlgorithmFactory::instance();

	for(int x =0;x<this->parameters.size();x++){
		Algorithm* temp;
		switch(parameters[x].size()){
			case 1:
				temp = factory.create(this->parameters[x][0]);
				break;
			case 3:
				temp = factory.create(this->parameters[x][0],this->parameters[x][1],this->parameters[x][2]);
				break;
			default:
				throw EssentiaException("ERROR: Uncaught dymanicCreate input size");
		}
		this->Algorithms.push_back(temp);
	}

	// for(int x =0;x<this->parameters.size();x++){
	// 	connect();
	// }
	connect(Algorithms[0]->output("audio"), Algorithms[1]->input("audio"));

	Network(Algorithms[0]).run();
}

void pipelineReader::readFile(string fileName){
	vector<string> file;
	ifstream infile(fileName);
	string line;

	// file -> vector "file"
	while (getline(infile, line)) file.push_back(line);
	
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
	
}