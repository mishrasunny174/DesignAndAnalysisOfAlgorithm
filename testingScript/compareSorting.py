#!/usr/bin/env python2
from pwn import *
import matplotlib.pyplot as mp

context.log_level = "critical"
testData = [[ str(random.randint(0,100)) for _ in range(0,i)] for i in range(25, 1001, 25)]
insertionSortComparisons = [[0],[0]]
mergeSortComparisons = [[0],[0]]
heapSortComparisons = [[0],[0]]
print "INSERTION SORT\tMERGE SORT\tHEAP SORT"
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
    heapSortBinary = process("./bin/practicals2")
    heapSortBinary.recvuntil("Enter size of array: ")
    heapSortBinary.sendline(inputArraySize)
    heapSortBinary.recvuntil("Enter array elements separated by space: ")
    heapSortBinary.sendline(inputArray)
    heapSortBinary.recvuntil("Number of comparisons: ")
    comparisonsHeapSort = heapSortBinary.recvline().strip()
    comparisonsHeapSort = int(comparisonsHeapSort)
    print str(inputArraySize)+" : "+str(comparisonsInsertionSort)+"\t\t\t" + str(inputArraySize)+" : "+str(comparisonsMergeSort) + "\t\t\t" + str(inputArraySize)+" : "+str(comparisonsHeapSort) 
    insertionSortComparisons[0].append(inputArraySize)
    insertionSortComparisons[1].append(comparisonsInsertionSort)
    mergeSortComparisons[0].append(inputArraySize)
    mergeSortComparisons[1].append(comparisonsMergeSort)
    heapSortComparisons[0].append(inputArraySize)
    heapSortComparisons[1].append(comparisonsHeapSort)
    insertionSortBinary.close()
    mergeSortBinary.close()

mp.plot(insertionSortComparisons[0], insertionSortComparisons[1], color='r', label="insertion sort")
mp.plot(mergeSortComparisons[0], mergeSortComparisons[1], color='b', label="merge sort")
mp.plot(heapSortComparisons[0], heapSortComparisons[1], color='g', label="heap sort")
mp.ylabel("NUMBER OF COMPARISONS")
mp.xlabel("ARRAY SIZE")
mp.title("INSERTION SORT VS MERGE SORT VS HEAP SORT")
mp.show()