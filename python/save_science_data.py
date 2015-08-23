import serial
import datetime
import gzip
import zipfile
import os
import shutil
import threading

def get_cpu_temp():
	f = open("/sys/class/thermal/thermal_zone0/temp")
	cpu_temp = f.read()
	f.close()
	return float(cpu_temp)/1000

def add_data(file, data, add_temp):
    f = open('datos/' + file, 'a')
    data_text = datetime.datetime.now().isoformat() + ',' + data.rstrip()
    if add_temp == True:
        data_text = data_text + ',' + str(get_cpu_temp()) + '\n'
    f.write( data_text + '\n')
    f.close()
    
def compress_file(file):
	with open('procesado/' + file, 'rb') as f_in, gzip.open('comprimido/' +file+'.gz', 'wb') as f_out:
		shutil.copyfileobj(f_in, f_out)
		os.remove('procesado/' + file)

def move_file(file):
	os.rename('datos/' + file, 'procesado/' + file)
	compress_file(file)

def read_data(port):
    file_science = datetime.datetime.now().strftime("%Y-%m-%d_%H-%M-%S-%f") + '-science.txt'
    file_geiger = datetime.datetime.now().strftime("%Y-%m-%d_%H-%M-%S-%f") + '-geiger.txt'
    num_geiger_entries = 0
    num_science_entries = 0
    ser = serial.Serial(port, 115200)
    ser.flush()
    while 1:
        new_data = ser.readline()
        if new_data[0] == 'D':
            add_data(file_science, new_data, add_temp = True)
            num_science_entries += 1
        elif new_data[0] == 'G':
            add_data(file_geiger, new_data, add_temp = False)
            num_geiger_entries += 1
        
        if num_geiger_entries == 100:
            move_file(file_geiger)
    	    file_geiger = datetime.datetime.now().strftime("%Y-%m-%d_%H-%M-%S-%f") + '-geiger.txt'
    	    num_geiger_entries = 0
        
        if num_science_entries == 5000:
            print(file_science)
            move_file(file_science)
    	    file_science = datetime.datetime.now().strftime("%Y-%m-%d_%H-%M-%S-%f") + '-science.txt'
    	    num_science_entries = 0
    	    

read_data('/dev/ttyACM0')