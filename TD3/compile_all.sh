arm-linux-g++ -Wall -Wextra src/main_td3a.cpp src/TimerLib/TimerLib.cpp src/Chrono/Chrono.cpp -o main_td3a -lrt -lpthread;
arm-linux-g++ -Wall -Wextra src/main_td3b.cpp src/TimerLib/TimerLib.cpp src/Chrono/Chrono.cpp src/Timer/Timer.cpp src/PeriodicTimer/PeriodicTimer.cpp src/CountDown/CountDown.cpp -o main_td3b -lrt -lpthread;
arm-linux-g++ -Wall -Wextra -Wno-psabi src/main_td3c.cpp src/TimerLib/TimerLib.cpp src/Chrono/Chrono.cpp src/Timer/Timer.cpp src/PeriodicTimer/PeriodicTimer.cpp src/Looper/Looper.cpp src/Calibrator/Calibrator.cpp src/CpuLoop/CpuLoop.cpp -o main_td3c -lrt -lpthread;
scp main_td3a main_td3b main_td3c root@192.168.50.51:ROB305/TD3;
rm main_td3c;
rm main_td3b;
rm main_td3a;