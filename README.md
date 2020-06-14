# edx-harvard-cs50

Personal C-Language workouts of CS50's Introduction to Computer Science.  
This repository stores my solutions for CS50 Solutions Sets, and all the contents are available [here](https://cs50.harvard.edu/x/2019/).  

## Courses

Based on the online courses by edX, MOOC by Harbard, MIT, and more, **CS50's introduction to Computer Science**.  
<https://www.edx.org/course/cs50s-introduction-to-computer-science>

## Table Of Contents

The problem sets in this repository are basically based on 2019 CS50 courses, but additionally including the others of past courses and latest ones.  

- [Problem Set 1](https://github.com/hwakabh/edx-harvard-cs50/tree/master/week1/)
  - [hello](https://github.com/hwakabh/edx-harvard-cs50/tree/master/week1/psets/hello/)
  - [water](https://github.com/hwakabh/edx-harvard-cs50/tree/master/week1/psets/water/)
  - [mario](https://github.com/hwakabh/edx-harvard-cs50/tree/master/week1/psets/mario/)
  - [greedy](https://github.com/hwakabh/edx-harvard-cs50/tree/master/week1/psets/greedy/)
  - [credit](https://github.com/hwakabh/edx-harvard-cs50/tree/master/week1/psets/credit/)
- [Problem Set 2](https://github.com/hwakabh/edx-harvard-cs50/tree/master/week2)
  - [caesar](https://github.com/hwakabh/edx-harvard-cs50/tree/master/week2/psets/caesar)
  - [vigenere](https://github.com/hwakabh/edx-harvard-cs50/tree/master/week2/psets/vigenere)
  - [crack](https://github.com/hwakabh/edx-harvard-cs50/tree/master/week2/psets/crack)
  - [initials](https://github.com/hwakabh/edx-harvard-cs50/tree/master/week2/psets/initials)
- [Problem Set 3](https://github.com/hwakabh/edx-harvard-cs50/tree/master/week3/)
  - music
  - fifteen

## Runtimes

As the CS50 course uses the online coding environment, `cloud9`, all the codes here are considered to build locally on your environments.  
Runtimes expected to compile/run correctly, under the software versions below:  

| Components | Version |
| --- | --- |
| OS | OSX 10.15.4 (Catalina) |
| gcc | 11.0.3 |

Note that it's required to install `gcc` on your environments if you use OSX, since OSX does not include gcc by default.  

```bash
# Install gcc on your OSX
$ xcode-select --install
# Check gcc version
$ gcc -dumpversion
```

The outputs of detailed version with `gcc` might be like below:  

```bash
$ gcc -v
Configured with: --prefix=/Library/Developer/CommandLineTools/usr --with-gxx-include-dir=/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/4.2.1
Apple clang version 11.0.3 (clang-1103.0.32.29)
Target: x86_64-apple-darwin19.4.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin
```

## Libraries

While CS50 courses, it's basically required to use `cs50.h` to understanding well for beginners, source codes here it does not. So the answers to problem sets, or examples in the courses should be differ from the ones described in course.  

If you'd like to use basic `cs50.h` for your codes, it's required to add the below in your codes `#include <cs50.h>`, and you should compile with the command like:

```bash
# Use linker with `-l` options
$ gcc -Wall -o hello ./hello.c -lcs50
```

Also, the documents for the `cs50.h` is available [here](https://man.cs50.io/).  

If you have GitHub accounts, you can use CS50 IDE from [this link](https://ide.cs50.io), where you can use many utilities, like `debug50` or `style50` or so, created by CS50, so that you need not install CS50 libraries manually into your environment.  

## Disclaimer

All the contents on this repository is totally for personal version controllings, and does not intend to provide best ways to coding with the code here.  
I think the codes here would not alway be the best solutions, so that I always welcome PRs for improving the solutions.  
