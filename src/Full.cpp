/*
A bandpass filter is an electronic device or 
circuit that allows signals between two specific 
frequencies to pass, but that discriminates against 
signals at other frequencies.
*/
#include <iostream>
#include <fstream>
#include <essentia/algorithmfactory.h>
#include <essentia/streaming/algorithms/poolstorage.h>
#include <essentia/streaming/algorithms/vectorinput.h>
#include <essentia/scheduler/network.h>
#include "../header/pipeline.hpp"
// #include "credit_libav.h" 
using namespace std;
using namespace essentia;
using namespace essentia::streaming;
using namespace essentia::scheduler;

int main(int argc, char* argv[]) {
	pipelineReader pl;
	pl.readFile("../pl/bandpass.pl");
	for (int x =0;x<pl.pipeline.size();x++){
		cout << "|" << pl.pipeline[x] << "|" << endl;
	}
	return 0;
}