Tool for reading sound and visualising it in dance of figures.<br>
.wav -> openGL<br>
<hr><hr>
first install: https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux <br>
second install: "<b>sudo apt install python3</b>" or "<b>sudo pacman -Sy python-pip</b>"<br>
third install: "<b>pip3 install aubio</b>" or "<b>pip install aubio</b>" <br>
<hr>
then:<br>
add your .wav(44100) key to folder and name it "key.wav"<br>
generate "key_temp" from "key.wav": "<b>python3 read.py</b>"<br>
compile "show": "<b>cc show.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11</b>"<br> 
run "show":"<b>./a.out</b>"<br>
<hr><hr>
*if you in windows<br>
you can check docs and recompile/run for your system but yourself all libs and code is cross-platform
