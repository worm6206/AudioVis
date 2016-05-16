MonoLoader -> BandPass -> MonoWriter

MonoLoader:
	filename:	audio.mp3
	sampleRate:	44100

BandPass:
	bandwidtg:	10Hz
	cutoffFrequency:	800Hz

MonoWriter:
	outputFilename:	output.wav