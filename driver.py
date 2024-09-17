#!/usr/bin/env python
################################################################################
#
# Test driver for "triangle" program
# Reads file "./testCaseInputs.txt where each line is of the form:
#       <testcase number> <inputs>? <expected output>
# 

import re                                         # Regular expressions
from subprocess import Popen, PIPE                # Spawn process; get results
import subprocess                                 # Do we need this?
import random                                     # Random numbers

inputs = open('testCaseInputs.txt').read()
inputs = [item.split(',') for item in inputs.split('\n')[:-1]]
for args in inputs:
    passed = 0
#    print("Inputs: ", args)                      # if you want to see what the
#    print("Array length: ", len(args))           #  inputs are
    caseNo = args[0]
    expectedAnswer = args[len(args) - 1]
    command = ["./triangle"];
    i = 1
    while (i < len(args)-1):
        command.append(str(args[i]));
        i += 1
    print("Case:", caseNo,
          "\nCommand:", command,
          "\nExpected output:", expectedAnswer)
    
    cproc = subprocess.Popen(command, stdin=PIPE, stdout=PIPE, stderr=PIPE)
    out, err = cproc.communicate()

 #   print("Cproc:", cproc)                       # if you want to see what the
#    print("Output:", str(out))                   # outputs are 
 #   print("Stderr:", err)

    output = out.decode('utf-8') if isinstance(out, bytes) else str(out)
    match = re.search(expectedAnswer,output)

    if match:
        print("passed\n")
        passed = 1
    else:
        print("failed\n")

exit(0)
