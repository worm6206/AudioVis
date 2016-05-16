#include <vector>
#include <string>

using namespace std;

struct pipelineReader { 
	vector<string> pipeline;
	void readFile(string fileName);
};