# Readme

## EDF实现方式

+ app.c

	+ 同ppt所述，增加了每个任务的开始释放时间，周期。

+ OS_TCB 

	+ 向`TCB`结构体中增加了每个任务的周期和完成时间。

+ OS_TimeTick()
	
	+ 使得每个任务减少剩余完成时间。

+ OS_InitExit()

	+ 输出`preempt`的任务。

+ OS_Sched()

	+ 输出`complete`的任务。

	+ 信息输出根据下个执行的任务是否为当前任务进行判断。

+ OS_SchedNew()

	+ 便利所有的TCB找到调度任务。

