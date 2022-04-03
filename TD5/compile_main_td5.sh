arm-linux-g++ -Wall -Wextra -Wno-psabi src/main_td5.cpp src/TimerLib/TimerLib.cpp src/Chrono/Chrono.cpp src/PosixThread/PosixThread.cpp src/Thread/Thread.cpp src/Timer/Timer.cpp src/PeriodicTimer/PeriodicTimer.cpp src/Looper/Looper.cpp src/Calibrator/Calibrator.cpp src/CpuLoop/CpuLoop.cpp src/Mutex/Mutex.cpp src/CpuMutexLoop/CpuMutexLoop.cpp -o main_td5 -lrt -lpthread;
scp main_td5 root@192.168.50.51:ROB305/TD5;
rm main_td5;