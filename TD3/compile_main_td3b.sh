arm-linux-g++ -Wall -Wextra src/main_td3b.cpp src/TimerLib/TimerLib.cpp src/Chrono/Chrono.cpp src/Timer/Timer.cpp src/PeriodicTimer/PeriodicTimer.cpp src/CountDown/CountDown.cpp -o main_td3b -lrt -lpthread;
scp main_td3b root@192.168.50.51:ROB305/TD3;
rm main_td3b;