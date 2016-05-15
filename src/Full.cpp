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

  if (argc != 5) {
    cerr << "ERROR: incorrect number of arguments." << endl;
    cerr << "Usage: " << argv[0] << " INPUT_AUDIO FREQ_RANGE FREQ OUTPUT_AUDIO" << endl;
    pipelineReader test;
    cerr << test.test << endl;
    // creditLibAV();
    exit(1);
  }

  string audioFilename = argv[1];
  string bandwidth = argv[2];
  string cutoffFrequency = argv[3];
  string outputFilename = argv[4];

  // register the algorithms in the factory(ies)
  essentia::init();

  Pool pool;

  /////// PARAMS //////////////
  Real sampleRate = 44100.0;

  streaming::AlgorithmFactory& factory = streaming::AlgorithmFactory::instance();

  Algorithm* audio = factory.create("MonoLoader",
                                    "filename", audioFilename,
                                    "sampleRate", sampleRate);
  Algorithm* filter = factory.create("BandPass", 
                                    "bandwidth", stoi(bandwidth), 
                                    "cutoffFrequency", stoi(cutoffFrequency));

  // Algorithm* Meter = factory.create("LevelExtractor", "frameSize", 88200, "hopSize", 44100);
  // Algorithm* BandPass = factory.create("BandPass");
  Algorithm* writer = factory.create("MonoWriter",
                                     "filename", outputFilename);

  /////////// CONNECTING THE ALGORITHMS ////////////////
  cerr << "-------- connecting algos --------" << endl;

  // Audio -> POOL
  audio->output("audio")  >> filter->input("signal");
  // Meter->output("loudness") >> PC(pool, "meter");

  filter->output("signal") >> writer->input("audio");


  /////////// STARTING THE ALGORITHMS //////////////////
  cerr << "-------- start processing --------" << endl;

  Network(audio).run();

  // cerr << "-------- writing to cout  --------" << endl;
  // // writing results to file
  // vector<Real> ticks;
  // if (pool.contains<vector<Real> >("meter")) { // there might be empty ticks
  //   ticks = pool.value<vector<Real> >("meter");
  //   cerr << "Total ticks: " << ticks.size() << endl;
  // }
  // // // ostream* fileStream = new ofstream(outputFilename.c_str());
  // for (size_t i=0; i<ticks.size(); ++i) {
  //   // *fileStream << ticks[i] << "\n";
  //   cout << ticks[i] << endl;
  // }
  // // delete fileStream;

  essentia::shutdown();

  return 0;
}