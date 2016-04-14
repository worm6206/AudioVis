#include <iostream>
#include <fstream>
#include <essentia/algorithmfactory.h>
#include <essentia/streaming/algorithms/poolstorage.h>
#include <essentia/streaming/algorithms/vectorinput.h>
#include <essentia/scheduler/network.h>
// #include "credit_libav.h" 
using namespace std;
using namespace essentia;
using namespace essentia::streaming;
using namespace essentia::scheduler;

int main(int argc, char* argv[]) {

  if (argc != 2) {
    cout << "ERROR: incorrect number of arguments." << endl;
    cout << "Usage: " << argv[0] << " audio_input" << endl;
    // creditLibAV();
    exit(1);
  }

  string audioFilename = argv[1];
  // string outputFilename = argv[2];

  // register the algorithms in the factory(ies)
  essentia::init();

  Pool pool;

  /////// PARAMS //////////////
  Real sampleRate = 44100.0;

  streaming::AlgorithmFactory& factory = streaming::AlgorithmFactory::instance();

  Algorithm* audio = factory.create("MonoLoader",
                                    "filename", audioFilename,
                                    "sampleRate", sampleRate);

  /////////// CONNECTING THE ALGORITHMS ////////////////
  cerr << "-------- connecting algos --------" << endl;

  // Audio -> POOL
  audio->output("audio")  >> PC(pool, "rhythm.ticks");

  /////////// STARTING THE ALGORITHMS //////////////////
  cerr << "-------- start processing " << audioFilename << " --------" << endl;

  Network(audio).run();

  cerr << "-------- writing to cout --------" << endl;
  // writing results to file
  vector<Real> ticks;
  if (pool.contains<vector<Real> >("rhythm.ticks")) { // there might be empty ticks
    ticks = pool.value<vector<Real> >("rhythm.ticks");
  }
  // // ostream* fileStream = new ofstream(outputFilename.c_str());
  for (size_t i=0; i<ticks.size(); ++i) {
    // *fileStream << ticks[i] << "\n";
    cout << ticks[i] << endl;
  }
  // delete fileStream;

  essentia::shutdown();

  return 0;
}