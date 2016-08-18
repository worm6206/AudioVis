#include <iostream>
#include <fstream>
#include <essentia/algorithmfactory.h>
#include <essentia/streaming/algorithms/poolstorage.h>
#include <essentia/streaming/algorithms/vectorinput.h>
#include <essentia/scheduler/network.h>
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

using namespace std;
using namespace essentia;
using namespace essentia::streaming;
using namespace essentia::scheduler;
using namespace rapidjson;

int main(int argc, char* argv[]) {

  if (argc != 2) {
    cout << "Error: incorrect number of arguments." << endl;
    cout << "Usage: " << argv[0] << " audio_input" << endl;
    exit(1);
  }

  string audioFilename = argv[1];

  // register the algorithms in the factory(ies)
  essentia::init();

  Pool pool;

  /////// PARAMS //////////////
  Real sampleRate = 44100.0;
  int frameSize = 2048;
  int hopSize = 1024;

  streaming::AlgorithmFactory& factory = streaming::AlgorithmFactory::instance();

  Algorithm* audio = factory.create("MonoLoader",
                                    "filename", audioFilename,
                                    "sampleRate", sampleRate);

  Algorithm* fc    = factory.create("FrameCutter",
                                    "frameSize", frameSize,
                                    "hopSize", hopSize,
                                    "silentFrames", "noise");

  // Algorithm* win = factory.create("Windowing","type", "blackmanharris62");

  Algorithm* spec = factory.create("Spectrum","size",frameSize);


  /////////// CONNECTING THE ALGORITHMS ////////////////
  cerr << "-------- connecting algos --------" << endl;

  // Audio -> FrameCutter
  audio->output("audio") >> fc->input("signal");

  fc->output("frame") >> spec->input("frame");

  // win->output("frame") >> spec->input("frame");

  spec->output("spectrum") >> PC(pool,"out.temp");

  /////////// STARTING THE ALGORITHMS //////////////////
  cerr << "-------- start processing " << audioFilename << " --------" << endl;

  Network network(audio);
  network.run();

  // printing results to file
  cerr << "-------- results --------" << endl;

  const vector<vector<Real> >& fft_vector = pool.value<vector<vector<Real> > >("out.temp");

  StringBuffer s;
  Writer<StringBuffer> w(s);

  w.StartArray();
  for(auto &x : fft_vector){
    w.StartArray();
    for(auto &y : x){
      w.Double(y);
    }
    w.EndArray();
  }
  w.EndArray();

  cout << s.GetString() << endl;

  cerr << "fft ticks: " << fft_vector.size() << endl;
  cerr << "fft width: " << fft_vector[0].size() << endl;

  essentia::shutdown();

  return 0;
}
