# [TD-4] Classes de base pour la programmation multitâches

*Author : Henrique RODRIGUES*

To directly compile all the files, run:
```
./compile_all.sh
```
You may need to give permission for .sh files:
```
chmod +x compile_all.sh
```
------------------

## a)
1. **Compile**:

```
arm-linux-g++ -Wall -Wextra src/main_td4a.cpp src/TimerLib/TimerLib.cpp src/Chrono/Chrono.cpp src/PosixThread/PosixThread.cpp src/Thread/Thread.cpp src/Incrementer/Incrementer.cpp -o main_td4a -lrt -lpthread
```

Or run:

```
./compile_main_td4a.sh
```

2. **Execute in the Raspberry Pi**:

```
./main_td4a <nLoops> <nTasks> <Sched Policy>
```

Example: ./main_td4a 10000 4 SCHED_RR

------------------

## b)
1. **Compile**:

```
arm-linux-g++ -Wall -Wextra src/main_td4b.cpp src/TimerLib/TimerLib.cpp src/Chrono/Chrono.cpp src/PosixThread/PosixThread.cpp src/Thread/Thread.cpp src/Mutex/Mutex.cpp src/IncrementerMutex/IncrementerMutex.cpp -o main_td4b -lrt -lpthread
```

Or run:

```
./compile_main_td4b.sh
```

2. **Execute in the Raspberry Pi**:

```
./main_td4b <nLoops> <nTasks> <Sched Policy>
```

Example: ./main_td4b 10000 4 SCHED_RR

------------------


## c)
1. **Compile**:

```
arm-linux-g++ -Wall -Wextra src/main_td4c.cpp src/TimerLib/TimerLib.cpp src/Chrono/Chrono.cpp src/PosixThread/PosixThread.cpp src/Thread/Thread.cpp src/Mutex/Mutex.cpp src/Semaphore/Semaphore.cpp src/SemProducer/SemProducer.cpp src/SemConsumer/SemConsumer.cpp -o main_td4c -lrt -lpthread
```

Or run:

```
./compile_main_td4c.sh
```

2. **Execute in the Raspberry Pi**:

```
./main_td4c <nProd> <nCons> <nItems>
```

Example: ./main_td4c 5 4 700

------------------


## d)
1. **Compile**:

```
arm-linux-g++ -Wall -Wextra src/main_td4d.cpp src/TimerLib/TimerLib.cpp src/Chrono/Chrono.cpp src/PosixThread/PosixThread.cpp src/Thread/Thread.cpp src/Mutex/Mutex.cpp src/Fifo/Fifo.hpp src/FifoProducer/FifoProducer.cpp src/FifoConsumer/FifoConsumer.cpp -o main_td4d -lrt -lpthread
```

Or run:
```
./compile_main_td4d.sh
```

2. **Execute in the Raspberry Pi**:

```
./main_td4d <nProd> <nCons> <nItems>
```

Example: ./main_td4d 5 4 700