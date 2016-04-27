## pureAudio

* Input:
	Audio file

* Output:
	stdout plain text

* Description:
	`pureAudio` is a program that doesn't modify the audio, but simply write the audio stream to `stdout`.

Usage:  `./pureAudio INPUT_AUDIO >> OUTPUT_TEXT`

## pureAudio[Audio]

Input:
	Audio file

Output:
	Audio file

Usage:  `./pureAudio INPUT_AUDIO OUTPUT_AUDIO`

```
OUTPUT_AUDIO example: output_audio.wav
```

## allPass

Input:
	Audio file

Output:
	stdout plain text

Usage:  `./allPass INPUT_AUDIO >> OUTPUT_TEXT`

## allPass[Audio]

Input:
	Audio file

Output:
	Audio file

Usage:  `./allPass\[Audio\] INPUT_AUDIO OUTPUT_AUDIO`

```
OUTPUT_AUDIO example: output_audio.wav
```

## HighLowPass

Input:
	Audio file

Output:
	stdout plain text

Usage:  `./HighLowPass INPUT_AUDIO FREQ_1 FREQ_2 >> OUTPUT_TEXT`

## HighLowPass[Audio]

Input:
	Audio file

Output:
	Audio file

Usage:  `./HighLowPass\[Audio\] INPUT_AUDIO FREQ_1 FREQ_2 OUTPUT_AUDIO`

```
OUTPUT_AUDIO example: output_audio.wav
```

## BandPass

Input:
	Audio file

Output:
	stdout plain text

Usage:  `./BandPass INPUT_AUDIO FREQ_RANGE FREQ >> OUTPUT_TEXT`

## BandPass[Audio]

Input:
	Audio file

Output:
	Audio file

Usage:  `./BandPass\[Audio\] INPUT_AUDIO FREQ_RANGE FREQ OUTPUT_AUDIO`

```
OUTPUT_AUDIO example: output_audio.wav
```
