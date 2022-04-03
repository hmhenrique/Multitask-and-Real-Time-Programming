arm-linux-g++ -Wall -Wextra src/main_td1e.cpp src/TimerLib/TimerLib.cpp -o main_td1e -lrt -lpthread
scp main_td1e root@192.168.50.51:ROB305/TD1;
rm main_td1e;