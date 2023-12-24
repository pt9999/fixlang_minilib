## io_ex.fix

#### creat: String -> U32 -> IOFail I32;

#### unlink: String -> IOFail ();

#### fflush : IOHandle -> IOFail ();

#### fdopen: I32 -> String -> IOFail IOHandle;

#### pipe: IOFail (I32, I32);

#### open_pipe: IOFail (IOHandle, IOHandle);

#### usleep: U32 -> IOFail ();

