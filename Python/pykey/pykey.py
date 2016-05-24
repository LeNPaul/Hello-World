import matplotlib.pyplot as plt
from scipy.fftpack import fft
from scipy.io import wavfile

sampFreq, snd = wavfile.read("440_sine.wav")

snd = snd / (2. ** 15)
