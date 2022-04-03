# [TD-2] Familiarisation avec l’API multitâches pthread

*Author : Henrique RODRIGUES*

To directly compile all the files, run:
```
./compile_all.sh
```
You may need to give permission for .sh files as follows:
```
chmod +x compile_all.sh
```
------------------

## a)
1. **Compile**:

```
arm-linux-g++ -Wall -Wextra src/main_td2a.cpp src/TimerLib/TimerLib.cpp -o main_td2a -lrt -lpthread
```

Or run:

```
./compile_main_td2a.sh
```

2. **Execute in the Raspberry Pi**:

```
./main_td2a <nLoops> <nTasks>
```

Example: ./main_td2b 1000000 4

------------------

## b)
1. **Compile**:

```
arm-linux-g++ -Wall -Wextra src/main_td2b.cpp src/TimerLib/TimerLib.cpp -o main_td2b -lrt -lpthread
```

Or run:

```
./compile_main_td2b.sh
```

2. **Execute in the Raspberry Pi**:

```
./main_td2b <nLoops> <nTasks> <schedPolicy>
```
Example: ./main_td2b 1000000 4 SCHED_RR 

To generate all data, run ./execute_td2b_raspberry.sh in the Raspberry, that has the following code:

```
for nLoops in 10000000 20000000 30000000 40000000
do
        echo "Running loop $nLoops"

        for nTasks in 1 2 3 4 5 6
        do
                echo "Running $nTasks tasks"
        ./main_td2b $nLoops $nTasks SCHED_RR
        done
done
```

------------------


## c)
1. **Compile**:

```
arm-linux-g++ -Wall -Wextra src/main_td2c.cpp src/TimerLib/TimerLib.cpp -o main_td2c -lrt -lpthread
```

Or run:

```
./compile_main_td2c.sh 
```

2. **Execute in the Raspberry Pi**:

```
./main_td2c <nLoops> <nTasks> protected
```

Example with Mutex protection: ./main_td2c 1000000 4 protected 