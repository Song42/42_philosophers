# philosophers - Dining Philosophers Problem

## About

**philosophers** is a concurrent programming project at École 42 that implements the classic "Dining Philosophers Problem" using threads and mutexes. This project explores fundamental concepts in concurrent programming, synchronization mechanisms, and deadlock prevention while simulating philosophers who alternately think and eat at a circular table.

The project demonstrates advanced understanding of multi-threaded programming, resource sharing, and synchronization primitives essential for systems programming and parallel computing applications.

## Learning Objectives

- **Concurrent Programming**: Mastering multi-threaded programming concepts and implementation
- **Synchronization Mechanisms**: Understanding mutexes, semaphores, and thread coordination
- **Deadlock Prevention**: Implementing strategies to avoid and resolve deadlock situations
- **Race Condition Management**: Preventing data races and ensuring thread safety
- **Resource Sharing**: Managing shared resources in multi-threaded environments
- **Performance Optimization**: Balancing efficiency with safety in concurrent systems
- **Time Management**: Precise timing control and real-time constraints

## Problem Description

### The Classic Scenario
The dining philosophers problem simulates five philosophers sitting around a circular table:
- Each philosopher alternates between thinking and eating
- There are forks on the table, one between each pair of philosophers
- A philosopher needs two forks (left and right) to eat
- Philosophers must avoid deadlock while competing for shared resources

### Project Implementation
The 42 version generalizes the problem:
- Configurable number of philosophers (N)
- N forks placed between philosophers
- Philosophers die if they don't eat within a specified time limit
- Optional constraint: each philosopher must eat a minimum number of times

## Technical Implementation

### Synchronization Strategy

#### Mutex-Based Solution
The implementation uses multiple mutex types for different synchronization needs:
- **Fork Mutexes**: One mutex per fork to control access
- **Write Mutex**: Serializes output to prevent garbled messages
- **Meal Mutex**: Protects meal-related data updates
- **Death Mutex**: Coordinates death detection and simulation termination

#### Deadlock Prevention
Several strategies prevent the classic deadlock scenario:
- **Ordered Resource Acquisition**: Philosophers acquire forks in a consistent order
- **Asymmetric Approach**: Different acquisition patterns for odd/even philosophers
- **Timeout Mechanisms**: Time limits prevent indefinite waiting
- **Resource Availability Checks**: Verify fork availability before attempting acquisition

### Thread Management

#### Monitoring Thread
A separate monitoring thread continuously checks for death conditions:
- Monitors time since last meal for each philosopher
- Detects when philosophers exceed time_to_die limit
- Terminates simulation when death occurs or all meals completed
- Ensures prompt detection and clean termination

### Timing and Precision

#### High-Precision Timing
The implementation requires precise timing control:
```c
long get_current_time(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
```

#### Synchronized Actions
All actions are precisely timed and logged:
- **Thinking**: Thinking periods
- **Eating**: Exact time_to_eat milliseconds
- **Sleeping**: Exact time_to_sleep milliseconds
- **Death Detection**: Continuous monitoring with millisecond precision

## Usage and Configuration

### Parameter Explanation
```bash
./philosophers [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]

# Arguments:
# 1. number_of_philosophers: Number of philosophers (and forks)
# 2. time_to_die: Time in milliseconds before a philosopher dies without eating
# 3. time_to_eat: Time in milliseconds a philosopher takes to eat
# 4. time_to_sleep: Time in milliseconds a philosopher takes to sleep
# 5. [optional] number_of_times_each_philosopher_must_eat: Minimum meals per philosopher
```

### Basic Execution
```bash
# Basic simulation with 5 philosophers
./philosophers 5 800 200 200
# 5 philosophers, 800ms to die, 200ms to eat, 200ms to sleep

# With meal requirement
./philosophers 5 800 200 200 7
# Each philosopher must eat 7 times
```

### Test Scenarios
```bash
# Death scenario - should terminate when philosopher dies
./philosophers 4 310 200 100

# Survival scenario - no philosopher should die
./philosophers 5 800 200 200

# Limited meals - simulation ends when all philosophers eat required times
./philosophers 4 410 200 200 10

# Edge cases
./philosophers 1 800 200 200    # Single philosopher (should die)
./philosophers 2 400 200 100    # Minimum viable scenario
```

## Advanced Implementation Details

### Race Condition Prevention

#### Atomic Operations
Critical sections are protected with appropriate mutexes:
- Meal counting and timing updates
- Death flag checking and setting
- Output message generation
- Resource acquisition and release

#### Memory Barriers
Proper memory ordering ensures thread safety:
- Volatile variables for shared state
- Mutex operations provide necessary barriers
- Consistent state visibility across threads

### Performance Optimization

#### Efficient Resource Management
- Minimal mutex contention through strategic locking
- Fast path optimization for common operations
- Reduced system call overhead
- Optimized thread scheduling cooperation

#### Scalability Considerations
- Linear scaling with philosopher count
- Constant overhead per philosopher
- Efficient memory usage patterns
- Minimal inter-thread communication overhead

### Error Handling and Robustness

#### Comprehensive Error Checking
- Thread creation and destruction validation
- Mutex initialization and cleanup verification
- Memory allocation failure handling
- Invalid parameter detection and reporting

#### Graceful Degradation
- Clean shutdown on error conditions
- Resource cleanup on premature termination
- Signal handling for external interruption
- Memory leak prevention in all scenarios

## Testing and Validation

### Memory and Performance Analysis
```bash
# Memory leak detection
valgrind --tool=memcheck ./philosophers 5 800 200 200

# Thread analysis
valgrind --tool=helgrind ./philosophers 5 800 200 200

# Performance profiling
time ./philosophers 10 800 200 200 100
```

## Key Challenges & Solutions

### Deadlock Prevention
- **Challenge**: Classic circular wait condition with fork acquisition
- **Solution**: Ordered resource acquisition and asymmetric philosopher behavior

### Race Condition Elimination
- **Challenge**: Multiple threads accessing shared data simultaneously
- **Solution**: Strategic mutex usage and atomic operations for critical sections

### Precise Timing Control
- **Challenge**: Accurate timing requirements with millisecond precision
- **Solution**: High-resolution timing functions and careful synchronization

### Death Detection Accuracy
- **Challenge**: Prompt and accurate detection of philosopher death conditions
- **Solution**: Dedicated monitoring thread with continuous state checking

## Skills Demonstrated

- **Concurrent Programming**: Advanced multi-threading and synchronization
- **System Programming**: Low-level thread and mutex management
- **Algorithm Design**: Deadlock prevention and resource allocation strategies
- **Performance Engineering**: Efficient concurrent system design
- **Debugging Expertise**: Multi-threaded debugging and validation techniques
- **Problem Solving**: Creative solutions to classic computer science problems
- **Resource Management**: Careful handling of system resources and cleanup

## Real-World Applications

The concepts learned in philosophers apply to numerous professional scenarios:
- **Database Systems**: Transaction management and deadlock prevention
- **Operating Systems**: Process scheduling and resource allocation
- **Web Servers**: Concurrent request handling and resource management
- **Game Development**: Multi-threaded game engines and physics simulation
- **Financial Systems**: Concurrent transaction processing and consistency
- **Distributed Systems**: Coordination and synchronization across multiple nodes

## Notes

The philosophers project represents a crucial milestone in understanding concurrent programming fundamentals. It demonstrates the complexity of multi-threaded systems and the careful design required to ensure correctness, safety, and performance.

The project emphasizes that concurrent programming requires different thinking patterns compared to sequential programming. Issues like race conditions, deadlocks, and resource contention must be carefully considered and addressed through proper synchronization mechanisms.

---

*Developed as part of the École 42 curriculum - mastering concurrent programming through the classic dining philosophers problem.*
