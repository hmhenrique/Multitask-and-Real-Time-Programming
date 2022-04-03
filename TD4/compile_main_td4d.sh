arm-linux-g++ -Wall -Wextra src/main_td4d.cpp src/TimerLib/TimerLib.cpp src/Chrono/Chrono.cpp src/PosixThread/PosixThread.cpp src/Thread/Thread.cpp src/Mutex/Mutex.cpp src/Fifo/Fifo.hpp src/FifoProducer/FifoProducer.cpp src/FifoConsumer/FifoConsumer.cpp -o main_td4d -lrt -lpthread;
scp main_td4d root@192.168.50.51:ROB305/TD4;
rm main_td4d;