!! R931 inquire-spec
!    is [ UNIT = ] file-unit-number
!    or FILE = file-name-expr
!    or ACCESS = scalar-default-char-variable
!    or ACTION = scalar-default-char-variable
!    or ASYNCHRONOUS = scalar-default-char-variable
!    or BLANK = scalar-default-char-variable
!    or DECIMAL = scalar-default-char-variable
!    or DELIM = scalar-default-char-variable
!    or DIRECT = scalar-default-char-variable
!    or ENCODING = scalar-default-char-variable
!    or ERR = label
!    or EXIST = scalar-default-logical-variable
!    or FORM = scalar-default-char-variable
!    or FORMATTED = scalar-default-char-variable
!    or ID = scalar-int-expr
!    or IOMSG = iomsg-variable
!    or IOSTAT = scalar-int-variable
!    or NAME = scalar-default-char-variable
!    or NAMED = scalar-default-logical-variable
!    or NEXTREC = scalar-int-variable
!    or NUMBER = scalar-int-variable
!    or OPENED = scalar-default-logical-variable
!    or PAD = scalar-default-char-variable
!    or PENDING = scalar-default-logical-variable
!    or POS = scalar-int-variable
!    or POSITION = scalar-default-char-variable
!    or READ = scalar-default-char-variable
!    or READWRITE = scalar-default-char-variable
!    or RECL = scalar-int-variable
!    or ROUND = scalar-default-char-variable
!    or SEQUENTIAL = scalar-default-char-variable
!    or SIGN = scalar-default-char-variable
!    or SIZE = scalar-int-variable
!    or STREAM = scalar-default-char-variable
!    or TEAM = image-team
!    or UNFORMATTED = scalar-default-char-variable
!    or WRITE = scalar-default-char-variable

!TODO-F08 - add more components to test

character :: cvar

inquire(5, ACCESS=cvar, action=cvar, asynchronous=cvar)
inquire (blank=cvar, unit=6, err=13)

13 end
