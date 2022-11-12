Tool for reading and visualising.<br>
.wav -> openGL<br>
<hr><hr>
first install: https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux <br>
second install: "sudo apt install python3"<br>
third install: "pip3 install aubio"<br>
<hr>
then:<br>
generate "key_temp": "python3 read.py key.wav"<br>
compile "show": "cc show.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11"<br> 
run "show":"./a.out"<br>
<hr><hr>