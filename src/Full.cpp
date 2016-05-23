/**
 *
 * Main cpp for Essentia parsing.
 * by Kevin Yen.
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <essentia/algorithmfactory.h>
#include <essentia/streaming/algorithms/poolstorage.h>
#include <essentia/streaming/algorithms/vectorinput.h>
#include <essentia/scheduler/network.h>
#include "../header/pipeline.hpp"
using namespace std;
using namespace essentia;
using namespace essentia::streaming;
using namespace essentia::scheduler;

int main(int argc, char* argv[]) {

	pipelineReader pl;

	/*----------  read file  ----------*/
	pl.readFile("../pl/bandpass.pl");
	pl.initAlgorithm();

	// cout << "ALG:" << endl;
	// for (int x =0;x<pl.parameters.size();x++){
	// 	cout << x << ": " << pl.parameters[x][0] << endl;
	// }
	// for (int x =0;x<pl.parameters.size();x++){
	// 	cout << "PARA" << x << ":" <<endl;
	// 	for(int y=1;y<pl.parameters[x].size();y++){
	// 		cout << x << ", " << y << ": " << pl.parameters[x][y] << endl;
	// 	}
	// }

	/*----------  essentia  ----------*/
	
	// essentia::init();
	// Pool pool;
	// streaming::AlgorithmFactory& factory = streaming::AlgorithmFactory::instance();
	// vector<Algorithm*> Algorithms;





	return 0;
}