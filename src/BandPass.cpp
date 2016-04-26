/*
This program only uses MonoLoader in streaming mode. every row of data
 is one tick, there are 44100 ticks in one second, thus the total row 
 number is time in second * 44100.
*/
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

  if (argc != 4) {
    cerr << "ERROR: incorrect number of arguments." << endl;
    cerr << "Usage: " << argv[0] << " audio_input bandwidth(hz) cutoffFrequency(hz) > file_output" << endl;
    // creditLibAV();
    exit(1);
  }

  string audioFilename = argv[1];
  string bandwidth = argv[2];
  string cutoffFrequency = argv[3];
  // string outputFilename = argv[4];

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

  Algorithm* Meter = factory.create("LevelExtractor", "frameSize", 882, "hopSize", 441);
  // Algorithm* BandPass = factory.create("BandPass");
  // Algorithm* writer = factory.create("MonoWriter",
  //                                    "filename", outputFilename);

  /////////// CONNECTING THE ALGORITHMS ////////////////
  cerr << "-------- connecting algos --------" << endl;

  // Audio -> POOL
  audio->output("audio")  >> filter->input("signal");

  filter->output("signal") >> Meter->input("signal");

  Meter->output("loudness") >> PC(pool, "meter");


  /////////// STARTING THE ALGORITHMS //////////////////
  cerr << "-------- start processing --------" << endl;

  Network(audio).run();

  cerr << "-------- writing to cout  --------" << endl;
  // writing results to file
  vector<Real> ticks;
  if (pool.contains<vector<Real> >("meter")) { // there might be empty ticks
    ticks = pool.value<vector<Real> >("meter");
    cerr << "Total ticks: " << ticks.size() << endl;
  }
  // // ostream* fileStream = new ofstream(outputFilename.c_str());
  cout << "id,tick" << endl;
  for (size_t i=0; i<ticks.size(); ++i) {
    // *fileStream << ticks[i] << "\n";
    cout << i << "," << ticks[i] << endl;
  }
  // delete fileStream;

  essentia::shutdown();

  return 0;
}