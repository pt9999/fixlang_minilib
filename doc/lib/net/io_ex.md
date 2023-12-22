## io_ex.fix

#### creat: String -> U32 -> IOFail I32;

#### unlink: String -> IOFail ();

#### fflush : IOHandle -> IOFail ();

#### fdopen: I32 -> String -> IOFail IOHandle;

#### open_pipe: IOFail (IOHandle, IOHandle);

#### usleep: U32 -> IOFail ();

