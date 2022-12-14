import sys
from aubio import source, pitch

filename = "key.wav"

downsample = 1
samplerate = 44100 // downsample
if len( sys.argv ) > 2: samplerate = int(sys.argv[2])

win_s = 4096 // downsample # fft size
hop_s = 512  // downsample # hop size

s = source(filename, samplerate, hop_s)
samplerate = s.samplerate

tolerance = 0.8

pitch_o = pitch("yin", win_s, hop_s, samplerate)
pitch_o.set_unit("midi")
pitch_o.set_tolerance(tolerance)

pitches = []
confidences = []

# total number of frames read
total_frames = 0
f = open("key_temp", "w")
while True:
    samples, read = s()
    pitch = pitch_o(samples)[0]
    #pitch = int(round(pitch))
    confidence = pitch_o.get_confidence()
    #if confidence < 0.8: pitch = 0.
    print("%f %f" % (total_frames / float(samplerate), pitch))
    f.write(str(pitch) + '\n')
    pitches += [pitch]
    confidences += [confidence]
    total_frames += read
    if read < hop_s: break

f.close()
if 0: sys.exit(0)