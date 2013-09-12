! types

module cula_type
    use, intrinsic :: ISO_C_BINDING

    implicit none

    enum, bind(C)
        enumerator :: culaNoError, culaNotInitialized, culaNoHardware, culaInsufficientRuntime
    end enum
end module

