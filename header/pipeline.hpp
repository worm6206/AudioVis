#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct pipelineReader {   // Declare CELL bit field
	string test = "header connected";
	vector<string> readFile(string fileName);
};