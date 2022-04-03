arm-linux-g++ -Wall -Wextra src/main_td4b.cpp src/TimerLib/TimerLib.cpp src/Chrono/Chrono.cpp src/PosixThread/PosixThread.cpp src/Thread/Thread.cpp src/Mutex/Mutex.cpp src/IncrementerMutex/IncrementerMutex.cpp -o main_td4b -lrt -lpthread;
scp main_td4b root@192.168.50.51:ROB305/TD4;
rm main_td4b;