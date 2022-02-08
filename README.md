# ld64

Utopia's dynamic linker.

## Building

This linker primarily (and for now only) targets Mach-O files.

Thus it needs some Mach-O specific headers, these can be found in two operating systems:

- macOS
- Utopia

Thankfully since Utopia was developed on a Linux distro, and it is powered by the Linux kernel, is possible to obtain a copy of the headers
fairly easily