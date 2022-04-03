arm-linux-g++ -Wall -Wextra src/main_td1d.cpp src/TimerLib/TimerLib.cpp -o main_td1d -lrt -lpthread
scp main_td1d root@192.168.50.51:ROB305/TD1;
rm main_td1d;