# Lottery Scheduling Example

This example illustrates the behavior of __lottery scheduling using compensation tickets__.

## Assignment Example

Consider the following input data set of four processes arriving at the given arrival time in the ready queue of the scheduler:

| Process | Arrival Time | Service Time | Tickets  |
|---------|--------------|--------------|----------|
| A       | 0            | 3            | 8        |
| B       | 0            | 1            | 6        |
| C       | 1            | 3            | 17       |
| D       | 2            | 3            | 10       |

The processes only require the CPU and are not going to be interrupted by I/O or any other reasons. The Scheduler only decides *online*, i.e. only based on the information of currently present processes. The quantum is __2__ time units. Processes __A__ and __C__ only use __1__ time unit of their quantum, while all other processes use the __full__ quantum.

Specify for every point in time from 0 to 9 (inclusive) the probability with which a process is scheduled to use the CPU. Assume that - for every drawing - always the process with the highest probability wins.

## Solution

| Time | %A    | %B   | %C    | %D    | Choice | Notes                                  |
|------|-------|------|-------|-------|--------|----------------------------------------|
| 0    | 8/14  | 6/14 |       |       | A      |                                        |
| 1    | 16/39 | 6/39 | 17/39 |       | C      | A yields, gets 8  compensation tickets |
| 2    | 16/66 | 6/66 | 34/66 | 10/66 | C      | C yields, gets 17 compensation tickets |
| 3    | 16/66 | 6/66 | 34/66 | 10/66 | C      | C finishes now                         |
| 4    | 16/32 | 6/32 |       | 10/32 | A      | A yields, gets 8 compensation tickets  |
| 5    | 16/32 | 6/32 |       | 10/32 | A      | A finishes now                         |
| 6    |       | 6/16 |       | 10/16 | D      |                                        |
| 7    |       | 6/16 |       | 10/16 | D      |                                        |
| 8    |       | 6/16 |       | 10/16 | D      | D finished now                         |
| 9    |       | 6/6  |       |       | B      | B finished now                         |

At time 1 A yields the CPU although the quantum is 2. For this reason, it is compensated by doubling its tickets (factor 2 computed via (available time quantum) / (actual time used), lecture part 4, slide 41).

At time 2 C yields the CPU and is compensated likewise. However, as it is immediately re-scheduled to use the CPU, its compensation tickets are removed again (lecture part 4, slide 42). C again yields after 1 time unit and is hence again compensated.

Note that the originally assigned tickets never expire. They are only removed once a process finishes its execution. Only compensation tickets expire whenever a process gets the CPU.
