# Imperius
A make an LKM rootkit visible again.

# This tool is part of research on LKM rootkits that will be launched.

It involves getting the address of the "module_show" function from a rootkit, for example the diamorphine rootkit, and using it to call it, adding it back to lsmod, making it possible to remove an LKM rootkit.

We can obtain the function address in very simple kernels using */sys/kernel/tracing/available_filter_functions_addrs*, however, it is only available from kernel 6.5x onwards.

An alternative to this is to scan the kernel memory, and later add it to lsmod again, so that it can be removed, such as ModTracer: https://github.com/MatheuZSecurity/ModTracer (But there are still ways to bypass it, maybe I'll make a post about it soon).

So in summary, this LKM abuses the function of lkm rootkits that have the functionality to become visible again.

OBS: There is another trick of removing/defusing a LKM rootkit, but it will be in the research that will be launched in this year.

Join in Rootkit Researchers Group

https://discord.gg/66N5ZQppU7
