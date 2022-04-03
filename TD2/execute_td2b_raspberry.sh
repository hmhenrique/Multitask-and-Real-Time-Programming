for nLoops in 10000000 20000000 30000000 40000000
do
        echo ""
        echo "Running loop $nLoops"
        echo ""

        for nTasks in 1 2 3 4 5 6
        do
                echo ""
                echo "Running $nTasks tasks"
                echo ""
        ./main_td2b $nLoops $nTasks SCHED_RR
        done
done