


## Troubleshoot



If you get an like the one below:
```bash
(gdb) run
Starting program: /Users/YoungChanPark/projects/c-practice/c-extension/gdb/debug
Unable to find Mach task port for process-id 25506: (os/kern) failure (0x5).
 (please check gdb is codesigned - see taskgated(8))
```
Either do `sudo gdb executable_file`, or refer to the below link.

https://stackoverflow.com/questions/11504377/gdb-fails-with-unable-to-find-mach-task-port-for-process-id-error



### codesign

https://stackoverflow.com/questions/18423124/please-check-gdb-is-codesigned-see-taskgated8-how-to-get-gdb-installed-w
