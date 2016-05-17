#include <vector>
#include <string>

using namespace std;

struct pipelineReader { 
	vector<string> algorithms;
	vector<vector<string> >parameters;
	void readFile(string fileName);
};