## pureAudio

* Input:

	Audio file

* Output:

	stdout plain text

* Description:

	`pureAudio` is a program that doesn't modify the audio, but simply write the 44100Hz audio stream to `stdout`.

* Usage:  

	`./pureAudio INPUT_AUDIO > OUTPUT_TEXT`

## pureAudio[Audio]

* Input:

	Audio file

* Output:

	Audio file

* Description:

	`pureAudio` is a program that doesn't modify the audio and write the audio stream back to output audio file.

* Usage:

	`./pureAudio INPUT_AUDIO OUTPUT_AUDIO`

```
OUTPUT_AUDIO example: output_audio.wav
```

## allPass

* Input:

	Audio file

* Output:

	stdout plain text

* Description:

	`allPass` has only one All-Pass filter with default parameters, and write the output of All-Pass filter to `stdout`.

* Usage:

	`./allPass INPUT_AUDIO > OUTPUT_TEXT`

## allPass[Audio]

* Input:

	Audio file

* Output:

	Audio file

* Description:

	`allPass` has only one All-Pass filter with default parameters, and write the output of All-Pass filter to output audio file.

* Usage:

	`./allPass\[Audio\] INPUT_AUDIO OUTPUT_AUDIO`

```
OUTPUT_AUDIO example: output_audio.wav
```

## HighLowPass  
### (NOT WORKING AS I EXPECTED)

* Input:

	Audio file

* Output:

	stdout plain text

* Description:

	`HighLowPass` has implemented 2 filters, High-Pass filter and Low-Pass filter. High-Pass filter only allow sound frequency higher than the decided frequency to pass, so the output audio stream will only have sound frequency higher than the frequency user decided. Low-Pass frequency vice versa. `FREQ_1` is for High-Pass filter, and `FREQ_2` is for Low-Pass filter. If the `FREQ_1` is 80 and `FREQ_2` is 100, the output will only keep the sound frequency between 80Hz and 100Hz. *This is what I expected but the output is not perfect.* The output audio stream is written to `stdout`.

* Usage:

	`./HighLowPass INPUT_AUDIO FREQ_1 FREQ_2 > OUTPUT_TEXT`

## HighLowPass[Audio]  
### (NOT WORKING AS I EXPECTED)

* Input:

	Audio file

* Output:

	Audio file

* Description:

	`HighLowPass` has implemented 2 filters, High-Pass filter and Low-Pass filter. High-Pass filter only allow sound frequency higher than the decided frequency to pass, so the output audio stream will only have sound frequency higher than the frequency user decided. Low-Pass frequency vice versa. `FREQ_1` is for High-Pass filter, and `FREQ_2` is for Low-Pass filter. If the `FREQ_1` is 80 and `FREQ_2` is 100, the output will only keep the sound frequency between 80Hz and 100Hz. *This is what I expected but the output is not perfect.* The output audio stream is written to the output audio file.

* Usage:

	`./HighLowPass\[Audio\] INPUT_AUDIO FREQ_1 FREQ_2 OUTPUT_AUDIO`

```
OUTPUT_AUDIO example: output_audio.wav
```

## BandPass

* Input:

	Audio file

* Output:

	stdout plain text

* Description:

	`BandPass` has implemented the Band-Pass filter, which allow a range of frequency to pass, around a set frequency. If `FREQ_RANGE` is 10 and `FREQ` is 200, the out put audio stream will only have the sound frequency of 190Hz to 210Hz. The output of the filter is written to `stdout`.

* Usage:

	`./BandPass INPUT_AUDIO FREQ_RANGE FREQ > OUTPUT_TEXT`

## BandPass[Audio]

* Input:

	Audio file

* Output:

	Audio file

* Description:

	`BandPass` has implemented the Band-Pass filter, which allow a range of frequency to pass, around a set frequency. If `FREQ_RANGE` is 10 and `FREQ` is 200, the out put audio stream will only have the sound frequency of 190Hz to 210Hz. The output of the filter is written to the output audio file.

* Usage:

	`./BandPass\[Audio\] INPUT_AUDIO FREQ_RANGE FREQ OUTPUT_AUDIO`

```
OUTPUT_AUDIO example: output_audio.wav
```
