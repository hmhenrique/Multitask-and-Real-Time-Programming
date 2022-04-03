arm-linux-g++ -Wall -Wextra src/main_td1a.cpp src/TimerLib/TimerLib.cpp -o main_td1a -lrt -lpthread;
scp main_td1a root@192.168.50.51:ROB305/TD1;
rm main_td1a;