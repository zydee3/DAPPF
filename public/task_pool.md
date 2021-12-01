# Task_pool API Reference  
## task

<hr>

## task_pool

#### insert()

```cpp
void dappf::data::task_pool::task_pool::insert(long timestamp, std::function<void()>* task)
```

> Inserts a task into the task pool. Acquires the lock while inserting to prevent any  
> race conditions.  
> @param timestamp  
> @param task  

#### execute()

```cpp
void dappf::data::task_pool::task_pool::execute()
```

> Goes through the task pool one by one and checks if the task  
> can be executed. If the task can be executed then it is removed  
> from the pool and executed. The process is then repeated for the next  
> task. We hold the lock while iterating through to find the task to  
> prevent race conditions.  

#### run()

```cpp
void dappf::data::task_pool::task_pool::run()
```

> Helper function for running the execution of tasks within the task pool  
> forever by bounding the execute function inside a while(true) loop. We  
> are currently busy waiting, need to implement a semaphore or conditional  
> lock in the future  

#### start()

```cpp
void dappf::data::task_pool::task_pool::start()
```

> Starts the thread which infinitely runs the task pool checker.  

<hr>

