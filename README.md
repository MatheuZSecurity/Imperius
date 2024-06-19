# Imperius
A make an LKM rootkit visible again.

# This tool is part of research on LKM rootkits that will be launched.

It involves getting the memory address of a rootkit's "show_module" function, for example, and using that to call it, adding it back to lsmod, making it possible to remove an LKM rootkit.

We can obtain the function address in very simple kernels using */sys/kernel/tracing/avaibale_filter_functions_addrs*, however, it is only available from kernel 6.5x onwards.

An alternative to this is to scan the kernel memory
