arm-linux-g++ -Wall -Wextra src/main_td4c.cpp src/TimerLib/TimerLib.cpp src/Chrono/Chrono.cpp src/PosixThread/PosixThread.cpp src/Thread/Thread.cpp src/Mutex/Mutex.cpp src/Semaphore/Semaphore.cpp src/SemProducer/SemProducer.cpp src/SemConsumer/SemConsumer.cpp -o main_td4c -lrt -lpthread;
scp main_td4c root@192.168.50.51:ROB305/TD4;
rm main_td4c;