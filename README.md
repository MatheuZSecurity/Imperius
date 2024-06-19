# Imperius
A make an LKM rootkit visible again.

# This tool is part of research on LKM rootkits that will be launched.

It involves getting the memory address of a rootkit's "show_module" function, for example, and using that to call it, adding it back to lsmod, making it possible to remove an LKM rootkit.
