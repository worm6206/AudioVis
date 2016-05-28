#include <vector>
#include <string>
#include <essentia/algorithmfactory.h>
#include <essentia/streaming/algorithms/poolstorage.h>
#include <essentia/streaming/algorithms/vectorinput.h>
#include <essentia/scheduler/network.h>
using namespace std;
using namespace essentia;
using namespace essentia::streaming;
using namespace essentia::scheduler;

struct pipelineReader { 
	vector<string> algorithms;
	vector<vector<string> >parameters;

	vector<Algorithm*> Algorithms;

	Pool pool;

	void readFile(string fileName);
	void initAlgorithm();
};