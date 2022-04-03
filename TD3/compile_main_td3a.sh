arm-linux-g++ -Wall -Wextra src/main_td3a.cpp src/TimerLib/TimerLib.cpp src/Chrono/Chrono.cpp -o main_td3a -lrt -lpthread;
scp main_td3a root@192.168.50.51:ROB305/TD3;
rm main_td3a;