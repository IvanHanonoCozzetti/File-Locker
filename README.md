# File Locker
File Console Application that hides, disguises and locks files.

### `System ()`
System calls the host environment's command processor (e.g. /bin/sh, cmd.exe, command.com) with the parameter command. Returns an implementation-defined value (usually the value that the invoked program returns).

## Parameters:
**command**	-	character string identifying the command to be run in the command processor. If a null pointer is given, command processor is checked for existence

## Return Values:
Implementation-defined value. If command is a null pointer, returns a nonzero value if and only if the command processor exists.

### *Further documentation and examples:*
https://en.cppreference.com/w/cpp/utility/program/system 
