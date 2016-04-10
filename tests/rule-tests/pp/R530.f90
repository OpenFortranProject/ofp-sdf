COMMON /myblock/ a, /TRUTH/ b
13 BIND(C) :: whatever
BIND(C) :: myroutine, /myblock/
BIND(C) :: foo, bar, /truth/, beauty
END PROGRAM
