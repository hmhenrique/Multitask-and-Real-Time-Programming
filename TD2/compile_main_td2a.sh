arm-linux-g++ -Wall -Wextra src/main_td2a.cpp src/TimerLib/TimerLib.cpp -o main_td2a -lrt -lpthread;
scp main_td2a root@192.168.50.51:ROB305/TD2;
rm main_td2a;