# :book: 0x05-processes_and_signals
In this project, I learned about handling process ID's and signals in Bash with `ps`, `pgrep`, `pkill`, `pkill`, `exit`, and `trap`.

## Process
A process is an executing (i.e., running) instance of a program. 

## PID Process Identication
An identification number that is automatically assigned to each process when it is created on a Unix-like operating system.

## Signal
Signals are software interrupts sent to a program to indicate that an important event has occurred.

# :computer: Tasks

## [0-what-is-my-pid](./0-what-is-my-pid): 
- Bash script that displays its own PID:
```
sylvain@ubuntu$ ./0-what-is-my-pid
4120
sylvain@ubuntu$
```

Repo:
 - GitHub repository: alx-system_engineering-devops
 - Directory: 0x05-processes_and_signals
 - File: 0-what-is-my-pid

shellcheck 0-what-is-my-pid #Check shell script formatting
chmod a+x 0-what-is-my-pid #Give file executable permissions
./0-what-is-my-pid school #Execute script

## [1-list_your_processes](1-list_your_processes)
- Bash script that displays a list of currently running processes:

Requirements:
 - Must show all processes, for all users, including those which might not have a TTY
 - Display in a user-oriented format
 - Show process hierarchy
```
sylvain@ubuntu$ ./1-list_your_processes | head -50
USER       PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
root         2  0.0  0.0      0     0 ?        S    Feb13   0:00 [kthreadd]
root         3  0.0  0.0      0     0 ?        S    Feb13   0:00  \_ [ksoftirqd/0]
root         4  0.0  0.0      0     0 ?        S    Feb13   0:00  \_ [kworker/0:0]
root         5  0.0  0.0      0     0 ?        S<   Feb13   0:00  \_ [kworker/0:0H]
root         7  0.0  0.0      0     0 ?        S    Feb13   0:02  \_ [rcu_sched]
root         8  0.0  0.0      0     0 ?        S    Feb13   0:03  \_ [rcuos/0]
root         9  0.0  0.0      0     0 ?        S    Feb13   0:00  \_ [rcu_bh]
root        10  0.0  0.0      0     0 ?        S    Feb13   0:00  \_ [rcuob/0]
root        11  0.0  0.0      0     0 ?        S    Feb13   0:00  \_ [migration/0]
root        12  0.0  0.0      0     0 ?        S    Feb13   0:02  \_ [watchdog/0]
root        13  0.0  0.0      0     0 ?        S<   Feb13   0:00  \_ [khelper]
root        14  0.0  0.0      0     0 ?        S    Feb13   0:00  \_ [kdevtmpfs]
root        15  0.0  0.0      0     0 ?        S<   Feb13   0:00  \_ [netns]
root        16  0.0  0.0      0     0 ?        S<   Feb13   0:00  \_ [writeback]
root        17  0.0  0.0      0     0 ?        S<   Feb13   0:00  \_ [kintegrityd]
root        18  0.0  0.0      0     0 ?        S<   Feb13   0:00  \_ [bioset]
root        19  0.0  0.0      0     0 ?        S<   Feb13   0:00  \_ [kworker/u3:0]
root        20  0.0  0.0      0     0 ?        S<   Feb13   0:00  \_ [kblockd]
root        21  0.0  0.0      0     0 ?        S<   Feb13   0:00  \_ [ata_sff]
root        22  0.0  0.0      0     0 ?        S    Feb13   0:00  \_ [khubd]
root        23  0.0  0.0      0     0 ?        S<   Feb13   0:00  \_ [md]
root        24  0.0  0.0      0     0 ?        S<   Feb13   0:00  \_ [devfreq_wq]
root        25  0.0  0.0      0     0 ?        S    Feb13   0:41  \_ [kworker/0:1]
root        27  0.0  0.0      0     0 ?        S    Feb13   0:00  \_ [khungtaskd]
root        28  0.0  0.0      0     0 ?        S    Feb13   0:00  \_ [kswapd0]
root        29  0.0  0.0      0     0 ?        S<   Feb13   0:00  \_ [vmstat]
root        30  0.0  0.0      0     0 ?        SN   Feb13   0:00  \_ [ksmd]
root        31  0.0  0.0      0     0 ?        S    Feb13   0:00  \_ [fsnotify_mark]
root        32  0.0  0.0      0     0 ?        S    Feb13   0:00  \_ [ecryptfs-kthrea]
root        33  0.0  0.0      0     0 ?        S<   Feb13   0:00  \_ [crypto]
root        45  0.0  0.0      0     0 ?        S<   Feb13   0:00  \_ [kthrotld]
root        46  0.0  0.0      0     0 ?        S    Feb13   0:00  \_ [kworker/u2:1]
root        65  0.0  0.0      0     0 ?        S<   Feb13   0:00  \_ [deferwq]
root        66  0.0  0.0      0     0 ?        S<   Feb13   0:00  \_ [charger_manager]
root       108  0.0  0.0      0     0 ?        S<   Feb13   0:00  \_ [kpsmoused]
root       125  0.0  0.0      0     0 ?        S    Feb13   0:00  \_ [scsi_eh_0]
root       126  0.0  0.0      0     0 ?        S    Feb13   0:00  \_ [kworker/u2:2]
root       172  0.0  0.0      0     0 ?        S    Feb13   0:00  \_ [jbd2/sda1-8]
root       173  0.0  0.0      0     0 ?        S<   Feb13   0:00  \_ [ext4-rsv-conver]
root       409  0.0  0.0      0     0 ?        S<   Feb13   0:00  \_ [iprt]
root       549  0.0  0.0      0     0 ?        S<   Feb13   0:00  \_ [kworker/u3:1]
root       808  0.0  0.0      0     0 ?        S    Feb13   0:00  \_ [kauditd]
root       834  0.0  0.0      0     0 ?        S<   Feb13   0:00  \_ [rpciod]
root       846  0.0  0.0      0     0 ?        S<   Feb13   0:00  \_ [nfsiod]
root         1  0.0  0.4  33608  2168 ?        Ss   Feb13   0:00 /sbin/init
root       373  0.0  0.0  19472   408 ?        S    Feb13   0:00 upstart-udev-bridge --daemon
root       378  0.0  0.2  49904  1088 ?        Ss   Feb13   0:00 /lib/systemd/systemd-udevd --daemon
root       518  0.0  0.1  23416   644 ?        Ss   Feb13   0:00 rpcbind
statd      547  0.0  0.1  21536   852 ?        Ss   Feb13   0:00 rpc.statd -L
sylvain@ubuntu$
```
Repo:
 - GitHub repository: alx-system_engineering-devops
 - Directory: 0x05-processes_and_signals
 - File: 1-list_your_processes

shellcheck 1-list_your_processes #Check shell script formatting
chmod a+x 1-list_your_processes #Give file executable permissions
./1-list_your_processes school #Execute script

## [2-show_your_bash_pid](2-show_your_bash_pid)
 - Bash script that displays lines containing the `bash` keyword based on the script defined in `1-list_your_processes`:
-Using your previous exercise command, write a Bash script that displays lines containing the bash word, thus allowing you to easily get the PID of your Bash process.

Requirements:
 - You cannot use pgrep
 - The third line of your script must be # shellcheck disable=SC2009 (for more info about ignoring shellcheck error here)

```
sylvain@ubuntu$ sylvain@ubuntu$ ./2-show_your_bash_pid
sylvain   4404  0.0  0.7  21432  4000 pts/0    Ss   03:32   0:00          \_ -bash
sylvain   4477  0.0  0.2  11120  1352 pts/0    S+   03:40   0:00              \_ bash ./2-show_your_bash_PID
sylvain   4479  0.0  0.1  10460   912 pts/0    S+   03:40   0:00                  \_ grep bash
sylvain@ubuntu$ 
```

Here we can see that my Bash PID is 4404.

Repo:
 - GitHub repository: alx-system_engineering-devops
 - Directory: 0x05-processes_and_signals
 - File: 2-show_your_bash_pid

shellcheck 2-show_your_bash_pid #Check shell script formatting
chmod a+x 2-show_your_bash_pid #Give file executable permissions
./2-show_your_bash_pid school #Execute script

## [3-show_your_bash_pid_made_easy](3-show_your_bash_pid_made_easy)
- Write a Bash script that displays the PID, along with the process name, of processes whose name contain the word bash.

Requirements:
 - You cannot use ps

```
sylvain@ubuntu$ ./3-show_your_bash_pid_made_easy
4404 bash
4555 bash
sylvain@ubuntu$ ./3-show_your_bash_pid_made_easy
4404 bash
4557 bash
sylvain@ubuntu$ 
```

Here we can see that:
 - For the first iteration: bash PID is 4404 and that the 3-show_your_bash_pid_made_easy script PID is 4555
 - For the second iteration: bash PID is 4404 and that the 3-show_your_bash_pid_made_easy script PID is 4557

Repo:
 - GitHub repository: alx-system_engineering-devops
 - Directory: 0x05-processes_and_signals
 - File: 3-show_your_bash_pid_made_easy

shellcheck 3-show_your_bash_pid_made_easy #Check shell script formatting
chmod a+x 3-show_your_bash_pid_made_easy #Give file executable permissions
./3-show_your_bash_pid_made_easy school #Execute script

## [4-to_infinity_and_beyond](4-to_infinity_and_beyond)
- Write a Bash script that displays To infinity and beyond indefinitely.

Requirements:
 - In between each iteration of the loop, add a sleep 2

```
sylvain@ubuntu$ ./4-to_infinity_and_beyond
To infinity and beyond
To infinity and beyond
To infinity and beyond
To infinity and beyond
To infinity and beyond
^C
sylvain@ubuntu$
```

Note that I ctrl+c (killed) the Bash script in the example.

Repo:
 - GitHub repository: alx-system_engineering-devops
 - Directory: 0x05-processes_and_signals
 - File: 4-to_infinity_and_beyond

shellcheck 4-to_infinity_and_beyond #Check shell script formatting
chmod a+x 4-to_infinity_and_beyond #Give file executable permissions
./4-to_infinity_and_beyond school #Execute script

## [5-dont_stop_me_now](5-dont_stop_me_now)
- We stopped our 4-to_infinity_and_beyond process using ctrl+c in the previous task, there is actually another way to do this.

Write a Bash script that stops 4-to_infinity_and_beyond process.

Requirements:

 - You must use kill

Terminal #0

```
sylvain@ubuntu$ ./4-to_infinity_and_beyond
To infinity and beyond
To infinity and beyond
To infinity and beyond
To infinity and beyond
To infinity and beyond
To infinity and beyond
To infinity and beyond
To infinity and beyond
To infinity and beyond
To infinity and beyond
To infinity and beyond
To infinity and beyond
To infinity and beyond
To infinity and beyond
Terminated
sylvain@ubuntu$
```

Terminal #1
```
sylvain@ubuntu$ ./5-dont_stop_me_now 
sylvain@ubuntu$
```

I opened 2 terminals in this example, started by running my 4-to_infinity_and_beyond Bash script in terminal #0 and then moved on terminal #1 to run 5-dont_stop_me_now. We can then see in terminal #0 that my process has been terminated.

shellcheck 5-dont_stop_me_now #Check shell script formatting
chmod a+x 5-dont_stop_me_now #Give file executable permissions
./5-dont_stop_me_now school #Execute script



## [6-stop_me_if_you_can](6-stop_me_if_you_can)
- Write a Bash script that stops 4-to_infinity_and_beyond process.

Requirements:
 - You cannot use kill or killall

Terminal #0

```
sylvain@ubuntu$ ./4-to_infinity_and_beyond
To infinity and beyond
To infinity and beyond
To infinity and beyond
To infinity and beyond
To infinity and beyond
To infinity and beyond
To infinity and beyond
To infinity and beyond
To infinity and beyond
To infinity and beyond
To infinity and beyond
Terminated
sylvain@ubuntu$ 
```

Terminal #1

```
sylvain@ubuntu$ ./6-stop_me_if_you_can
sylvain@ubuntu$
```

I opened 2 terminals in this example, started by running my 4-to_infinity_and_beyond Bash script in terminal #0 and then moved on terminal #1 to run 6-stop_me_if_you_can. We can then see in terminal #0 that my process has been terminated.

Repo:
 - GitHub repository: alx-system_engineering-devops
 - Directory: 0x05-processes_and_signals
 - File: 6-stop_me_if_you_can

shellcheck 6-stop_me_if_you_can #Check shell script formatting
chmod a+x 6-stop_me_if_you_can #Give file executable permissions
./6-stop_me_if_you_can school #Execute script

## [7-highlander](7-highlander)
- Write a Bash script that displays:
 - To infinity and beyond indefinitely
 - With a sleep 2 in between each iteration
 - I am invincible!!! when receiving a SIGTERM signal

Make a copy of your 6-stop_me_if_you_can script, name it 67-stop_me_if_you_can, that kills the 7-highlander process instead of the 4-to_infinity_and_beyond one.

Terminal #0
```
sylvain@ubuntu$ ./7-highlander
To infinity and beyond
To infinity and beyond
I am invincible!!!
To infinity and beyond
I am invincible!!!
To infinity and beyond
To infinity and beyond
To infinity and beyond
I am invincible!!!
To infinity and beyond
^C
sylvain@ubuntu$
```

Terminal #1
```
sylvain@ubuntu$ ./67-stop_me_if_you_can 
sylvain@ubuntu$ ./67-stop_me_if_you_can
sylvain@ubuntu$ ./67-stop_me_if_you_can
sylvain@ubuntu$ 
```

shellcheck 7-highlander #Check shell script formatting
chmod a+x 7-highlander #Give file executable permissions
./7-highlander school #Execute script

## [8-beheaded_process](8-beheaded_process)
- Write a Bash script that kills the process 7-highlander.

Terminal #0

```
sylvain@ubuntu$ ./7-highlander 
To infinity and beyond
To infinity and beyond
To infinity and beyond
To infinity and beyond
Killed
sylvain@ubuntu$
```

Terminal #1

```
sylvain@ubuntu$ ./8-beheaded_process
sylvain@ubuntu$
```

I started 7-highlander in Terminal #0 and then run 8-beheaded_process in terminal #1 and we can see that the 7-highlander has been killed.

Repo:

 - GitHub repository: alx-system_engineering-devops
 - Directory: 0x05-processes_and_signals
 - File: 8-beheaded_process

shellcheck 8-beheaded_process #Check shell script formatting
chmod a+x 8-beheaded_process #Give file executable permissions
./8-beheaded_process school #Execute script

## [100-process_and_pid_file](100-process_and_pid_file)
- Shellcheck 100-process_and_pid_file #Check shell script formatting
chmod a+x 100-process_and_pid_file #Give file executable permissions
./100-process_and_pid_file school #Execute script

## [101-manage_my_process, manage_my_process](101-manage_my_process, manage_my_process)
- Shellcheck 101-manage_my_process #Check shell script formatting
chmod a+x 101-manage_my_process #Give file executable permissions
./101-manage_my_process #Execute script

shellcheck manage_my_process #Check shell script formatting
chmod a+x manage_my_process #Give file executable permissions
./manage_my_process #Execute script


## 102-zombie.
- Betty 102-zombie.c
gcc 102-zombie.c -o zombie
./zombie 


# Commands
## Git push command
git add --all; git commit -m "";git push

# References
1. [Unix / Linux - Signals and Traps](https://www.tutorialspoint.com/unix/unix-signals-traps.htm)
