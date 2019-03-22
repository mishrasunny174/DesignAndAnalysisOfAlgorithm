#!/usr/bin/env python2
from pwn import *

context.log_level = "critical"

testData = [[ str(random.randint(0,100)) for _ in range(0,i)] for i in range(1,1001)]
insertionSortComparisons = []
mergeSortComparisons = []
print "INSERTION SORT\tMERGE SORT"
for i in range(len(testData)):
    inputArraySize = str(len(testData[i]))
    inputArray = ' '.join(testData[i])
    insertionSortBinary = process("./bin/practicals1a")
    insertionSortBinary.recvuntil("Enter size of array: ")
    insertionSortBinary.sendline(inputArraySize)
    insertionSortBinary.recvuntil("Enter array elements separated by space: ")
    insertionSortBinary.sendline(inputArray)
    insertionSortBinary.recvuntil("Number of comparisons: ")
    comparisonsInsertionSort = insertionSortBinary.recvline().strip()
    comparisonsInsertionSort = int(comparisonsInsertionSort)
    mergeSortBinary = process("./bin/practicals1b")
    mergeSortBinary.recvuntil("Enter size of array: ")
    mergeSortBinary.sendline(inputArraySize)
    mergeSortBinary.recvuntil("Enter array elements separated by space: ")
    mergeSortBinary.sendline(inputArray)
    mergeSortBinary.recvuntil("Number of comparisons: ")
    comparisonsMergeSort = mergeSortBinary.recvline().strip()
    comparisonsMergeSort = int(comparisonsMergeSort)
    print str(inputArraySize)+" : "+str(comparisonsInsertionSort)+"\t\t\t" + str(inputArraySize)+" : "+str(comparisonsMergeSort)
    insertionSortBinary.close()
    mergeSortBinary.close()