# build a c++ file with python
import sys, os, getopt


def main():
    os.system('g++ ' + 'network.cpp' + ' -o ' + 'network')
    os.system('echo built cpp')
    os.system('./network')

if __name__ =='__main__':
    main()