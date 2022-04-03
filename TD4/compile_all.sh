arm-linux-g++ -Wall -Wextra src/main_td4a.cpp src/TimerLib/TimerLib.cpp src/Chrono/Chrono.cpp src/PosixThread/PosixThread.cpp src/Thread/Thread.cpp src/Incrementer/Incrementer.cpp -o main_td4a -lrt -lpthread;
arm-linux-g++ -Wall -Wextra src/main_td4b.cpp src/TimerLib/TimerLib.cpp src/Chrono/Chrono.cpp src/PosixThread/PosixThread.cpp src/Thread/Thread.cpp src/Mutex/Mutex.cpp src/IncrementerMutex/IncrementerMutex.cpp -o main_td4b -lrt -lpthread;
arm-linux-g++ -Wall -Wextra src/main_td4c.cpp src/TimerLib/TimerLib.cpp src/Chrono/Chrono.cpp src/PosixThread/PosixThread.cpp src/Thread/Thread.cpp src/Mutex/Mutex.cpp src/Semaphore/Semaphore.cpp src/SemProducer/SemProducer.cpp src/SemConsumer/SemConsumer.cpp -o main_td4c -lrt -lpthread;
arm-linux-g++ -Wall -Wextra src/main_td4d.cpp src/TimerLib/TimerLib.cpp src/Chrono/Chrono.cpp src/PosixThread/PosixThread.cpp src/Thread/Thread.cpp src/Mutex/Mutex.cpp src/Fifo/Fifo.hpp src/FifoProducer/FifoProducer.cpp src/FifoConsumer/FifoConsumer.cpp -o main_td4d -lrt -lpthread;
scp main_td4a main_td4b main_td4c main_td4d root@192.168.50.51:ROB305/TD4;
rm main_td4a;
rm main_td4b;
rm main_td4c;
rm main_td4d;