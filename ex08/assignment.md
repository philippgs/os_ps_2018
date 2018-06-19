# Assignment for the OS lab on May 30th, 2018

The goal of the following assignment is to check every solution of each scheduling algorithm for correctness. For this purpose, do the following:

**Note: The following steps must be completed in Windows!**

1) Download and extract the scheduling simulator tool available at http://dps.uibk.ac.at/~philipp/scheduling_tool_windows.zip (Windows) and http://dps.uibk.ac.at/~philipp/scheduling_tool_linux.zip (Linux).
2) In the extracted folder, run the `start.bat` script
3) Select "Scheduling"
4) Enter your own data set using the "+ Process"-Button on the lower left
5) Select the required scheduling algorithms at the top and press "Calculate" on the lower right
6) For each scheduling algorithm, compare the solution computed by the tool to your own solution. If they are equal, continue with the next scheduling algorithm. If they are not equal then write a report containing:
    * The full input data set (including quantum, and any other parameters required to reproduce the mismatch)
    * Both solutions (clearly mark which solution is yours and which solution is computed by the tool)
    * A description of the discrepancy and some reasoning which solution is correct (either yours or the tool's) and why

> Note that for lottery scheduling, the tool computes two versions: "Lottery Scheduling" and "Lottery Scheduling Theoretical". The latter is the one that you should compare your solution against, which implements "the highest number of tickets always wins". The former uses actual probabilities and is hence indeterministic (i.e. can produce multiple solutions that differ from each other, but are all correct).

Complete this procedure for both Task 1 and Task 2. Be as precise as possible. Please also report any bugs you might encounter with the tool (crashes, unexpected behavior, etc.) or propose improvements to the usability.

At the end of the lab, you should have a single report file containing all mismatching solutions accompanied by their respective input data sets and descriptions.