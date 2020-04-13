# Test file for "Lab2_introToAVR"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

# Example test:
test "PINA: 0x0F, PINB: 0x04, PINC: 0x37 => PORTD: 128"
# Set inputs
setPINA 0x01 #1
setPINB 0x04 #4
setPINC 0x37 #55
# Continue for several ticks
continue 5
# Set expect values
expectPORTD 0x3C
# Check pass/fail
checkResult

# Add tests below
test "PINA: 0x01, PINB: 0xA9, PINC: 0xAA => PORTD: 3"
setPINA 0x45 #69
setPINB 0xA9 #169
setPINC 0xAA #170
continue 5
expectPORTD 0x9B
checkResult

test "PINA: 0x075, PINB: 0x48, PINC: 0xFB => PORTC: 3"
setPINA 0x75 #117
setPINB 0x48 #72
setPINC 0xFB #251
continue 5
expectPORTB 0xFF
checkResult

# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
