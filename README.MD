Tool for reading sound and visualising it in dance offigures.<br>
.wav -> openGL<br>
<hr><hr>
first install: https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux <br>
second install: "sudo apt install python3" or "sudo pacman -Sy python-pip"<br>
third install: "pip3 install aubio" or "pip install aubio" <br>
<hr>
then:<br>
add your .wav(44100) key to folder and name it "key.wav"<br>
generate "key_temp" from key.wav(or other .wav): "python3 read.py"<br>
compile "show": "cc show.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11"<br> 
run "show":"./a.out"<br>
<hr><hr>
*if you in windows, heh... maybe you choose bad side? think about it :D <br>
you can check docs and recompile/run for your system but yourself all libs and code is cross-platform