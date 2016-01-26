# rlimits64
set_nofile64.c will modify the current soft & hard NOFILE limits for a running process.
This was modified slightly to work with X86_64. Original can be found here: https://gist.github.com/carlhoerberg/6914280

tests/:
RLIMIT_NPROC test script.
RLIMIT_NOFILE test script.

The plan is to have an all-in-one tool to view, modify and test all RLIMIT's.
