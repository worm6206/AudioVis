/*
High:
A high-pass filter is an electronic filter 
that passes signals with a frequency higher 
than a certain cutoff frequency and attenuates 
signals with frequencies lower than the cutoff 
frequency.

Low:
A low-pass filter is a filter that passes signals 
with a frequency lower than a certain cutoff 
frequency and attenuates signals with frequencies 
higher than the cutoff frequency. 
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

  if (argc != 5) {
    cerr << "ERROR: incorrect number of arguments." << endl;
    cerr << "Usage: " << argv[0] << " audio_input high_fqncy low_fqncy file_output" << endl;
    // creditLibAV();
    exit(1);
  }


  string audioFilename = argv[1];
  string cutoffFrequencyHigh = argv[2];
  string cutoffFrequencyLow = argv[3];
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
  Algorithm* HighPass = factory.create("HighPass", "cutoffFrequency", stoi(cutoffFrequencyHigh));
  Algorithm* LowPass = factory.create("LowPass", "cutoffFrequency", stoi(cutoffFrequencyLow));

  Algorithm* writer = factory.create("MonoWriter", "filename", outputFilename);

  /////////// CONNECTING THE ALGORITHMS ////////////////
  cerr << "-------- connecting algos --------" << endl;

  // Audio -> POOL
  audio->output("audio")  >> HighPass->input("signal");
  HighPass->output("signal") >> LowPass->input("signal");
  LowPass->output("signal") >> writer->input("audio");


  /////////// STARTING THE ALGORITHMS //////////////////
  cerr << "-------- start processing --------" << endl;

  Network(audio).run();

  essentia::shutdown();

  return 0;
}