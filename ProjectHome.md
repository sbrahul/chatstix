## Intrduction ##

Chatstix is a multithreaded, multicast IRC like chat server, running on embedded Linux (Armstrong 2.6.31-omap1) on a _Gumstix®_ _Overo™_ board (running _OMAP3530_ CPU). Chatstix is capable of supporting multiple chat rooms and Instant Messaging, and will support file transfers. All communication is performed using BSD sockets and threading using the POSIX pthread library. Inter-thread synchronization is performed using POSIX semaphores. Chatstix is developed in C language on a Linux machine and has been cross-compiled for the OMAP platform using the GNU ARM toolchain.


Author:
(Rahul Sreeram)
http://web.njit.edu/~rbs22/main/


_=Update=_

A new C++ build with GUI (most probably using QT) is on its way. Stay Tuned!